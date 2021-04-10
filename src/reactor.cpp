#include <algorithm>
#include <array>

#include "../inc/nominax/reactor.hpp"
#include "../inc/nominax/macrocfg.hpp"
#include "../inc/nominax/platform.hpp"
#include "../inc/nominax/reactor_internals.hpp"

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

	#define LIKELY(x)	__builtin_expect(!!(x), 1)
	#define UNLIKELY(x) __builtin_expect(!!(x), 0)

	#if NOMINAX_REACTOR_ASM_MARKERS
	#define ASM_MARKER(msg) asm volatile("#" msg)
	#else
	#define ASM_MARKER(msg)
	#endif

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
			&&__ipusho__,
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
			&&__ineg__,
			&&__fadd__,
			&&__fsub__,
			&&__fmul__,
			&&__fdiv__,
			&&__fmod__,
			&&__fneg__,
			&&__finc__,
			&&__fdec__,
			&&__fpusho__
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
		
		asm volatile("#" "reactor begin");
		
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

		ASM_MARKER("reactor exec");

		// exec first:
		goto **(bp + (*++ip).op);				// next_instr()

	__int__: {
			ASM_MARKER("__int__");
			interrupt = (*++ip).r32.u;			// imm()
			if (UNLIKELY(interrupt < 0 || !interrupt_handler(interrupt, *test_signal_status, usr_dat))) [[unlikely]] {
				goto _terminate_;
			}
		}
		goto **(bp + (*++ip).op);				// next_instr()

	__intrin__: {
			ASM_MARKER("__intrin__");
			const auto iid = (*++ip).r32.i;		// imm()
			if (LIKELY(iid < 0)) [[likely]] {
				// TODO call build-in
			} else {
				(**(intrinsic_table + iid))();
			}
		}
		goto **(bp + (*++ip).op);				// next_instr()

	__call__: {
			ASM_MARKER("__call__");
		}
		goto **(bp + (*++ip).op);				// next_instr()

	__ret__: {
			ASM_MARKER("__ret__");
		}
		goto **(bp + (*++ip).op);				// next_instr()

	__mov__: {
			ASM_MARKER("__mov__");
			const u32 dst = (*++ip).r32.u;		// imm() -> arg 1 (reg) - dst
			const u32 src = (*++ip).r32.u;		// imm() -> arg 2 (reg) - src
			*(sp + dst) = *(sp + src);			// poke(dst) = poke(src)
		}
		goto **(bp + (*++ip).op);				// next_instr()

	__sto__: {
			ASM_MARKER("__sto__");
			const u32 dst = (*++ip).r32.u;		// imm() -> arg 1 (reg) - dst
			const u32 imm = (*++ip).r32.u;		// imm() -> arg 2 (reg) - raw bits
			(*(sp + dst)).u = imm;				// poke(dst) = imm()
		}
		goto **(bp + (*++ip).op);				// next_instr()

	__push__:
		ASM_MARKER("__push__");
		*++sp = (*++ip).r32;					// push(imm())
		goto **(bp + (*++ip).op);				// next_instr()

	__pop__:
		ASM_MARKER("__pop__");
		--sp;
		goto **(bp + (*++ip).op);				// next_instr()

	__pop2__:
		ASM_MARKER("__pop2__");
		sp -= 2;
		goto **(bp + (*++ip).op);				// next_instr()

	__dupl__: {
			ASM_MARKER("__dupl__");
			const auto top = *sp;				// peek()
			*++sp = top;						// push(peek())
		}
		goto **(bp + (*++ip).op);				// next_instr()

	__dupl2__: {
			ASM_MARKER("__dupl2__");
			const auto top = *sp;				// peek
			*++sp = top;						// push(peek())
			*++sp = top;						// push(peek())
		}
		goto **(bp + (*++ip).op);				// next_instr()

	__nop__:
		ASM_MARKER("__nop__");
		goto **(bp + (*++ip).op);				// next_instr()

	__pushz__:
		ASM_MARKER("__pushz__");
		(*++sp).u = 0;							// push(0)
		goto **(bp + (*++ip).op);				// next_instr()

	__ipusho__:
		ASM_MARKER("__ipusho__");
		(*++sp).u = 1;							// push(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__iinc__:
		ASM_MARKER("__iinc__");
		++sp->i;
		goto **(bp + (*++ip).op);				// next_instr()

	__idec__:
		ASM_MARKER("__idec__");
		--sp->i;
		goto **(bp + (*++ip).op);				// next_instr()

	__iadd__:
		ASM_MARKER("__iadd__");
		--sp;									// pop
		(*sp).i += (*(sp + 1)).i;				// peek() += poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__isub__:
		ASM_MARKER("__isub__");
		--sp;									// pop
		(*sp).i -= (*(sp + 1)).i;				// peek() -= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()
		
	__imul__:
		ASM_MARKER("__imul__");
		--sp;									// pop
		(*sp).i *= (*(sp + 1)).i;				// peek() *= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__idiv__:
		ASM_MARKER("__idiv__");
		--sp;									// pop
		(*sp).i /= (*(sp + 1)).i;				// peek() /= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__imod__:
		ASM_MARKER("__imod__");
		--sp;									// pop
		(*sp).i %= (*(sp + 1)).i;				// peek() %= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__iand__:
		ASM_MARKER("__iand__");
		--sp;									// pop
		(*sp).i &= (*(sp + 1)).i;				// peek() &= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__ior__:
		ASM_MARKER("__ior__");
		--sp;									// pop
		(*sp).i |= (*(sp + 1)).i;				// peek() |= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__ixor__:
		ASM_MARKER("__ixor__");
		--sp;									// pop
		(*sp).i ^= (*(sp + 1)).i;				// peek() ^= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__icom__:
		ASM_MARKER("__icom__");
		(*sp).i = ~(*sp).i;
		goto **(bp + (*++ip).op);				// next_instr()

	__isal__:
		ASM_MARKER("__isal__");
		--sp;									// pop
		(*sp).i <<= (*(sp + 1)).i;				// peek() <<= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__isar__:
		ASM_MARKER("__isar__");
		--sp;									// pop
		(*sp).i >>= (*(sp + 1)).i;				// peek() >>= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__irol__:
		ASM_MARKER("__irol__");
		--sp;									// pop
		(*sp).u = rol((*sp).u, (*(sp + 1)).i);
		goto **(bp + (*++ip).op);				// next_instr()

	__iror__:
		ASM_MARKER("__iror__");
		--sp;									// pop
		(*sp).u = ror((*sp).u, (*(sp + 1)).i);
		goto **(bp + (*++ip).op);				// next_instr()

	__ineg__:
		ASM_MARKER("__ineg__");
		(*sp).i = -(*sp).i;
		goto **(bp + (*++ip).op);				// next_instr()

	__fadd__:
		ASM_MARKER("__fadd__");
		--sp;									// pop
		(*sp).f += (*(sp + 1)).f;				// peek() += poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__fsub__:
		ASM_MARKER("__fsub__");
		--sp;									// pop
		(*sp).f -= (*(sp + 1)).f;				// peek() -= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__fmul__:
		ASM_MARKER("__fmul__");
		--sp;									// pop
		(*sp).f *= (*(sp + 1)).f;				// peek() *= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__fdiv__:
		ASM_MARKER("__fdiv__");
		--sp;									// pop
		(*sp).f /= (*(sp + 1)).f;				// peek() /= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__fmod__:
		ASM_MARKER("__fmod__");
		--sp;									// pop
		*sp %= (*(sp + 1)).f;					// peek() %= poke(1)
		goto **(bp + (*++ip).op);				// next_instr()

	__fneg__:
		ASM_MARKER("__fneg__");
		(*sp).f = -(*sp).f;
		goto **(bp + (*++ip).op);				// next_instr()

	__finc__:
		ASM_MARKER("__iinc__");
		++sp->f;
		goto **(bp + (*++ip).op);				// next_instr()

	__fdec__:
		ASM_MARKER("__iinc__");
		--sp->f;
		goto **(bp + (*++ip).op);				// next_instr()

	__fpusho__:
		ASM_MARKER("__fpusho__");
		(*++sp).f = 1.F;						// push(1)
		goto **(bp + (*++ip).op);				// next_instr()
		
	_terminate_:
		ASM_MARKER("reactor end");
		const auto post = std::chrono::high_resolution_clock::now();
		const auto dur = post - pre;
		const auto ip_diff = static_cast<std::ptrdiff_t>(ip - input.code_chunk);
		const auto sp_diff = static_cast<std::ptrdiff_t>(sp - input.stack);

		ASM_MARKER("reactor ret");
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
