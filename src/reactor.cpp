#include "../inc/nominax/reactor.hpp"
#include "../inc/nominax/macrocfg.hpp"
#include "../inc/nominax/platform.hpp"

#include <algorithm>
#include <array>
#include <cassert>

#if NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT
#include <x86intrin.h>
#endif

namespace nominax {	
	auto reactor_input::validate() const noexcept -> reactor_validation_result {
		// validate all pointers:
		if (!(this->test_signal_status
			&& this->code_chunk
			&& this->intrinsic_table
			&& this->interrupt_handler
			&& this->stack)) [[unlikely]] {
			return reactor_validation_result::null_ptr;
		}

		if (!this->code_chunk_size || !this->intrinsic_table_size || !this->stack_size) [[unlikely]] {
			return reactor_validation_result::zero_size;
		}

		// first instruction will be skipped and must be NOP:
		if (code_chunk->instr != instruction::nop) [[unlikely]] {
			return reactor_validation_result::missing_code_prologue;
		}

		// first stack entry is never used and must be nop-padding:
		if (*stack != rec_nop_padding) [[unlikely]] {
			return reactor_validation_result::missing_stack_prologue;
		}

		// validate intrinsic routines:
		auto** begin = this->intrinsic_table;
		auto** const end = this->intrinsic_table + this->intrinsic_table_size;
		while (begin < end) [[likely]] {
			if (!*begin++) [[unlikely]] {
				return reactor_validation_result::null_intrinsic_routine;
			}
		}

		return reactor_validation_result::ok;
	}

	auto execute_reactor(const reactor_input& input) -> reactor_output {
		if (const auto result = input.validate(); result != reactor_validation_result::ok) [[unlikely]] {
			return reactor_output{
				.validation_result = result,
				.input = input,
				.status = false
			};
		}
		
		const auto pre = std::chrono::high_resolution_clock::now();

		static constexpr std::array<const void* __restrict__ const, static_cast<std::size_t>(instruction::count)> branch_table = {
			&&__int__,
			&&__intrin__,
			&&__call__,
			&&__ret__,
			&&__mov__,
			&&__sto__,
			&&__push__,
			&&__pop__,
			&&__pop2__,
			&&__dupl__,
			&&__dupl2__,
			&&__nop__,
			&&__pushz__,
			&&__pusho__,
			&&__iinc__,
			&&__idec__,
			&&__iadd__,
			&&__isub__,
			&&__imul__,
			&&__idiv__,
			&&__imod__,
			&&__iand__,
			&&__ior__,
			&&__ixor__,
			&&__icom__,
			&&__isal__,
			&&__isar__,
			&&__irol__,
			&&__iror__,
			&&__ineg__
		};
		
		struct $ {
			[[nodiscard]]
			static consteval auto validate_branch_table() noexcept -> bool {
				return std::ranges::all_of(branch_table.begin(), branch_table.end(), [](const void* const x) noexcept -> bool {
					return x != nullptr;
				});
			}
		};
		static_assert($::validate_branch_table());

		#define DBGA assert

		#if NOMINAX_REACTOR_ASM_MARKERS
			#define MARKER(msg) asm volatile("#" msg)
		#else
			#define MARKER(_)
		#endif
		
		MARKER("reactor begin");
		
		interrupt_accumulator								interrupt			{};																/* interrupt id flag        */
		void*												usr_dat				{input.user_data};												/* user data                */
		volatile std::sig_atomic_t* const					test_signal_status	{input.test_signal_status};										/* signal status flag       */
		intrinsic_routine* const* const						intrinsic_table		{input.intrinsic_table};										/* intrinsic table hi       */
		intrinsic_routine* const* const						intrinsic_table_hi	{input.intrinsic_table + input.intrinsic_table_size};			/* intrinsic table lo       */
		interrupt_routine* const							interrupt_handler	{input.interrupt_handler};										/* global interrupt routine */
		const signal32* __restrict__						ip					{input.code_chunk};												/* instruction ptr lo       */
		const signal32* const __restrict__					ip_hi				{input.code_chunk + input.code_chunk_size};						/* instruction ptr hi       */
		record32* __restrict__								sp					{input.stack};													/* stack pointer lo			*/
		record32* const	__restrict__						sp_hi				{input.stack + input.stack_size};								/* stack pointer hi			*/
		const void* __restrict__ const* __restrict__ const	bp					{branch_table.data()};											/* branch pointer			*/
			
		#define NEXT() goto **(bp + (*++ip).op)
		#define IMM() (*++ip)
		#define POKE(x) (*(sp + (x)))
		#define PUSH() (*++sp)
		#define PEEK() (*sp)
		#define POP() (--sp)

		MARKER("reactor exec");
		
		NEXT();

	__int__: {
			MARKER("__int__");
			DBGA(ip <= ip_hi);
			interrupt = IMM().r32.u;
			if (interrupt < 0 || !interrupt_handler(interrupt, *test_signal_status, usr_dat)) [[unlikely]] {
				goto _terminate_;
			}
		}
		NEXT();

	__intrin__: {
			MARKER("__intrin__");
			DBGA(ip <= ip_hi); // check for arg 1 (imm)
			const auto iid = IMM().r32.i;
			if (iid < 0) [[likely]] {
				// TODO call build-in
			} else {
				DBGA(intrinsic_table + iid < intrinsic_table_hi);
				(**(intrinsic_table + iid))();
			}
		}
		NEXT();

	__call__: {
			MARKER("__call__");
		}
		NEXT();

	__ret__: {
			MARKER("__ret__");
		}
		NEXT();

	__mov__: {
			MARKER("__mov__");
			DBGA(ip <= ip_hi);                  // check for arg 1	(reg)
			DBGA(ip + 1 <= ip_hi);				// check for arg 2	(reg)
			const u32 dst = IMM().r32.u;		// arg 1 (reg) - dst
			const u32 src = IMM().r32.u;		// arg 2 (reg) - src
			POKE(dst) = POKE(src);				// copy
		}
		NEXT();

	__sto__: {
			MARKER("__sto__");
			DBGA(ip <= ip_hi);                  // check for arg 1	(reg)
			DBGA(ip + 1 <= ip_hi);				// check for arg 2	(imm)
			const u32 dst = IMM().r32.u;		// arg 1 (reg) - dst
			DBGA(dst != 0);						// stack bottom is reserved for nop padding
			const u32 imm = IMM().r32.u;		// arg 2 (reg) - raw bits
			POKE(dst).u = imm;					// copy
		}
		NEXT();

	__push__:
		MARKER("__push__");
		PUSH() = IMM().r32;
		NEXT();

	__pop__:
		MARKER("__pop__");
		POP();
		NEXT();

	__pop2__:
		MARKER("__pop2__");
		sp -= 2;
		NEXT();

	__dupl__: {
			MARKER("__dupl__");
			const auto top = PEEK();
			PUSH() = top;
		}
		NEXT();

	__dupl2__: {
			MARKER("__dupl2__");
			const auto top = PEEK();
			PUSH() = top;
			PUSH() = top;
		}
		NEXT();

	__nop__:
		MARKER("__nop__");
		NEXT();

	__pushz__:
		MARKER("__pushz__");
		PUSH().u = 0;
		NEXT();

	__pusho__:
		MARKER("__pusho__");
		PUSH().u = 1;
		NEXT();

	__iinc__:
		MARKER("__iinc__");
		++sp->i;
		NEXT();

	__idec__:
		MARKER("__idec__");
		--sp->i;
		NEXT();

	__iadd__:
		MARKER("__iadd__");
		POP();
		PEEK().i += POKE(1).i;
		NEXT();

	__isub__:
		MARKER("__isub__");
		POP();
		PEEK().i -= POKE(1).i;
		NEXT();
		
	__imul__:
		MARKER("__imul__");
		POP();
		PEEK().i *= POKE(1).i;
		NEXT();

	__idiv__:
		MARKER("__idiv__");
		POP();
		PEEK().i /= POKE(1).i;
		NEXT();

	__imod__:
		MARKER("__imod__");
		POP();
		PEEK().i %= POKE(1).i;
		NEXT();

	__iand__:
		MARKER("__iand__");
		POP();
		PEEK().i &= POKE(1).i;
		NEXT();

	__ior__:
		MARKER("__ior__");
		POP();
		PEEK().i |= POKE(1).i;
		NEXT();

	__ixor__:
		MARKER("__ixor__");
		POP();
		PEEK().i ^= POKE(1).i;
		NEXT();

	__icom__:
		MARKER("__icom__");
		PEEK().i = ~PEEK().i;
		NEXT();

	__isal__:
		MARKER("__isal__");
		POP();
		PEEK().i <<= POKE(1).i;
		NEXT();

	__isar__:
		MARKER("__isar__");
		POP();
		PEEK().i >>= POKE(1).i;
		NEXT();

	__irol__:
		MARKER("__irol__");
		POP();
		#if NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT
			PEEK().u = _rotl(PEEK().u, POKE(1).i);
		#else
			PEEK().u = rol(PEEK().u, POKE(1).i);
		#endif
		NEXT();

	__iror__:
		MARKER("__iror__");
		POP();
		#if NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT
			PEEK().u = _rotr(PEEK().u, POKE(1).i);
		#else
			PEEK().u = ror(PEEK().u, POKE(1).i);
		#endif
		NEXT();

	__ineg__:
		MARKER("__ineg__");
		PEEK().i = -PEEK().i;
		NEXT();
		
	_terminate_:
		MARKER("reactor end");
		const auto post = std::chrono::high_resolution_clock::now();
		const auto dur = post - pre;
		const auto ip_diff = static_cast<std::ptrdiff_t>(ip - input.code_chunk);
		const auto sp_diff = static_cast<std::ptrdiff_t>(sp - input.stack);

		MARKER("reactor ret");
		return {
			.validation_result = reactor_validation_result::ok,
			.input = input,
			.status = !interrupt,
			.pre = pre,
			.post = post,
			.duration = dur,
			.interrupt = interrupt,
			.ip_diff = ip_diff,
			.sp_diff = sp_diff,
		};
	}
}
