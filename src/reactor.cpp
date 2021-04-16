#include "../inc/nominax/reactor.hpp"
#include "../inc/nominax/interrupts.hpp"
#include "../inc/nominax/macrocfg.hpp"
#include "../inc/nominax/reactor_internals.hpp"
#include "../inc/nominax/sysintrin.hpp"

namespace nominax {
	auto reactor_input::validate() const noexcept -> reactor_validation_result {
		// validate all pointers:
		if (__builtin_expect(!(this->test_signal_status && this->code_chunk && this->intrinsic_table && this->interrupt_handler && this->stack), 0)) {
			return reactor_validation_result::null_ptr;
		}

		if (__builtin_expect(!this->code_chunk_size || !this->intrinsic_table_size || !this->stack_size, 0)) {
			return reactor_validation_result::zero_size;
		}

		// first instruction will be skipped and must be NOP:
		if (__builtin_expect(code_chunk->instr != instruction::nop, 0)) {
			return reactor_validation_result::missing_code_prologue;
		}

		// last instruction must be interrupt:
		if (__builtin_expect(code_chunk_size < 2, 0) || __builtin_expect((code_chunk + code_chunk_size - 2)->instr != instruction::inter, 0)) {
			return reactor_validation_result::missing_code_epilogue;
		}

		// first stack entry is never used and must be nop-padding:
		if (__builtin_expect(*stack != record64::nop_padding(), 0)) {
			return reactor_validation_result::missing_stack_prologue;
		}

		// validate intrinsic routines:
		auto** begin = this->intrinsic_table;
		auto** const end = this->intrinsic_table + this->intrinsic_table_size;
		while (__builtin_expect(begin < end, 1)) {
			if (__builtin_expect(!*begin++, 0)) {
				return reactor_validation_result::null_intrinsic_routine;
			}
		}

		return reactor_validation_result::ok;
	}

	/* So in C++ 20 we already have [[likely]] and [[unlikely]].
	 * When I wrote this comment (11.04.2021) LLVM/Clang 11 has no support for [[likely]] and [[unlikely]].
	 * The support will come with LLVM/Clang 12. Until all compiles correctly support [[likely]] and [[unlikely]]
	 * I use the built-in intrinsic "__builtin_expect" like in the Linux kernel. I often use branch hints do indicate expected branches,
	 * but the most performance critical code is the reactor, so it's important that they are noticed by the compiler,
	 * which is not yet the case with [[likely]] and [[unlikely]]!
	 * x86-64 has branch hints - some sources say they are ignored, some say they are not, other say it depends on the company
	 * ARM-64 also has some branch hints
	 * The biggest difference could affect the code reordering - search for more info.
	 */

	#if NOMINAX_REACTOR_ASM_MARKERS
	 /* This inserts a comment with the msg into the assembler code.
	  * Useful for finding the asm code of the instructions.
	  * These should be disabled when building for release.
	  * Asm volatile is like a black box and never touched by the compiler so it might affect code generation/ordering!
	  */
		#define ASM_MARKER(msg) asm volatile("#" msg)
	#else
		#define ASM_MARKER(msg)
	#endif

	#if NOMINAX_STACK_OVERFLOW_CHECKS
		/* Inserts a stack overflow sentinel.
		* x is the number of pushes to check for.
		* x = 1 -> check for 1 more push
		* x = 2 -> check for 2 more pushes
		* etc..
		*/
		#define STO_SENTINEL(x)																						\
			do {																									\
				if (__builtin_expect(sp + ((x) - 1) >= sp_hi, 0)) {													\
					interrupt_code = static_cast<decltype(interrupt_code)>(interrupt::stack_overflow);				\
					goto _hard_fault_err_;																			\
				}																									\
			} while(false)
	#else
		#define STO_SENTINEL(x)
	#endif

	__attribute__((hot)) static void syscall_intrin(record64* const sp_, const u64 id_) {
		static constexpr const void* __restrict__ bt[static_cast<std::size_t>(intrinsic::count_)] {
			&&__cos__,
			&&__sin__,
			&&__tan__,
			&&__acos__,
			&&__asin__,
			&&__atan__,
			&&__atan2__,
			&&__cosh__,
			&&__sinh__,
			&&__tanh__,
			&&__acosh__,
			&&__asinh__,
			&&__atanh__,
			&&__exp__,
			&&__log__,
			&&__log10__,
			&&__exp2__,
			&&__ilogb__,
			&&__log2__,
			&&__pow__,
			&&__sqrt__,
			&&__cbrt__,
			&&__hypot__,
			&&__ceil__,
			&&__floor__,
			&&__round__,
			&&__rint__,
			&&__max__,
			&&__min__,
			&&__fmax__,
			&&__fmin__,
			&&__fdim__,
			&&__abs__,
			&&__fabs__
		};

		goto **(bt + id_);
		
	__cos__: __attribute__((hot));
		(*sp_).f = std::cos((*sp_).f);
		return;
		
	__sin__: __attribute__((hot));
		(*sp_).f = std::sin((*sp_).f);
		return;
		
	__tan__: __attribute__((hot));
		(*sp_).f = std::tan((*sp_).f);
		return;
		
	__acos__: __attribute__((hot));
		(*sp_).f = std::acos((*sp_).f);
		return;
		
	__asin__: __attribute__((hot));
		(*sp_).f = std::asin((*sp_).f);
		return;
		
	__atan__: __attribute__((hot));
		(*sp_).f = std::atan((*sp_).f);
		return;
		
	__atan2__: __attribute__((hot));
		(*(sp_ - 1)).f = std::atan2((*(sp_ - 1)).f, (*sp_).f);
		return;
		
	__cosh__: __attribute__((hot));
		(*sp_).f = std::cosh((*sp_).f);
		return;
		
	__sinh__: __attribute__((hot));
		(*sp_).f = std::sinh((*sp_).f);
		return;
		
	__tanh__: __attribute__((hot));
		(*sp_).f = std::tanh((*sp_).f);
		return;
		
	__acosh__: __attribute__((hot));
		(*sp_).f = std::acosh((*sp_).f);
		return;
		
	__asinh__: __attribute__((hot));
		(*sp_).f = std::asinh((*sp_).f);
		return;
		
	__atanh__: __attribute__((hot));
		(*sp_).f = std::atanh((*sp_).f);
		return;
		
	__exp__: __attribute__((hot));
		(*sp_).f = std::exp((*sp_).f);
		return;
		
	__log__: __attribute__((hot));
		(*sp_).f = std::log((*sp_).f);
		return;
		
	__log10__: __attribute__((hot));
		(*sp_).f = std::log10((*sp_).f);
		return;
		
	__exp2__: __attribute__((hot));
		(*sp_).f = std::exp2((*sp_).f);
		return;
		
	__ilogb__: __attribute__((hot));
		(*sp_).i = std::ilogb((*sp_).f);
		return;
		
	__log2__: __attribute__((hot));
		(*sp_).f = std::log2((*sp_).f);
		return;
		
	__pow__: __attribute__((hot));
		(*(sp_ - 1)).f = std::pow((*(sp_ - 1)).f, (*sp_).f);
		return;
		
	__sqrt__: __attribute__((hot));
		(*sp_).f = std::sqrt((*sp_).f);
		return;
		
	__cbrt__: __attribute__((hot));
		(*sp_).f = std::cbrt((*sp_).f);
		return;
		
	__hypot__: __attribute__((hot));
		(*(sp_ - 1)).f = std::hypot((*(sp_ - 1)).f, (*sp_).f);
		return;
		
	__ceil__: __attribute__((hot));
		(*sp_).f = std::ceil((*sp_).f);
		return;
		
	__floor__: __attribute__((hot));
		(*sp_).f = std::floor((*sp_).f);
		return;
		
	__round__: __attribute__((hot));
		(*sp_).f = std::round((*sp_).f);
		return;
		
	__rint__: __attribute__((hot));
		(*sp_).f = std::rint((*sp_).f);
		return;
		
	__max__: __attribute__((hot));
		(*(sp_ - 1)).i = std::max((*(sp_ - 1)).i, (*sp_).i);
		return;
		
	__min__: __attribute__((hot));
		(*(sp_ - 1)).i = std::min((*(sp_ - 1)).i, (*sp_).i);
		return;
		
	__fmax__: __attribute__((hot));
		(*(sp_ - 1)).f = std::max((*(sp_ - 1)).f, (*sp_).f);
		return;
		
	__fmin__: __attribute__((hot));
		(*(sp_ - 1)).f = std::min((*(sp_ - 1)).f, (*sp_).f);
		return;
		
	__fdim__: __attribute__((hot));
		(*(sp_ - 1)).f = std::fdim((*(sp_ - 1)).f, (*sp_).f);
		return;
		
	__abs__: __attribute__((hot));
		(*sp_).i = std::abs((*sp_).i);
		return;
		
	__fabs__: __attribute__((hot));
		(*sp_).f = std::abs((*sp_).f);
		return;
	}

	auto execute_reactor(const reactor_input& input_) -> reactor_output {
		if (const auto result = input_.validate(); __builtin_expect(result != reactor_validation_result::ok, 0)) {
			return {
				.input = &input_,
				.validation_result = result,
			};
		}
		
		const auto pre = std::chrono::high_resolution_clock::now();

		static constexpr const void* __restrict__ const bt[static_cast<std::size_t>(instruction::count_)] {
			&&__int__,
			&&__intrin__,
			&&__cintrin__,
			&&__call__,
			&&__ret__,
			&&__mov__,
			&&__sto__,
			&&__push__,
			&&__pop__,
			&&__pop2__,
			&&__dupl__,
			&&__dupl2__,
			&&__swap__,
			&&__nop__,
			&&__jmp__,
			&&__jmprel__,
			&&__jz__,
			&&__jnz__,
			&&__jo_cmpi__,
			&&__jo_cmpf__,
			&&__jno_cmpi__,
			&&__jno_cmpf__,
			&&__je_cmpi__,
			&&__je_cmpf__,
			&&__jne_cmpi__,
			&&__jne_cmpf__,
			&&__ja_cmpi__,
			&&__ja_cmpf__,
			&&__jl_cmpi__,
			&&__jl_cmpf__,
			&&__jae_cmpi__,
			&&__jae_cmpf__,
			&&__jle_cmpi__,
			&&__jle_cmpf__,
			&&__ipushz__,
			&&__ipusho__,
			&&__fpusho__,
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
			&&__fdec__
		};
		
		struct $ {
			[[nodiscard]]
			static consteval auto validate_branch_table() noexcept -> bool {
				const auto* iter = bt;
				const auto* const end = bt + sizeof bt / sizeof *bt;
				while (__builtin_expect(iter < end, 1)) {
					if (__builtin_expect(!(*iter++), 0)) {
						return false;
					}
				}
				return true;
			}
		};
		static_assert($::validate_branch_table());
		
		ASM_MARKER("reactor begin");
		
		interrupt_accumulator								interrupt_code		{};												/* interrupt id flag        */
		void* __restrict__									usr_dat				{input_.user_data};								/* user data                */
		intrinsic_routine* const* const						intrinsic_table		{input_.intrinsic_table};						/* intrinsic table hi       */
		interrupt_routine* const							interrupt_handler	{input_.interrupt_handler};						/* global interrupt routine */
		const csignal* const __restrict						ip_lo				{input_.code_chunk};							/* instruction low ptr      */
		const csignal* __restrict__							ip					{ip_lo};										/* instruction ptr			*/
		record64* __restrict__								sp					{input_.stack};									/* stack pointer lo			*/
		record64* const	__restrict__						sp_hi				{input_.stack + input_.stack_size - 1};			/* stack pointer hi			*/

		ASM_MARKER("reactor exec");

		// exec first:
		goto **(bt + (*++ip).op);						// next_instr()

	__int__: __attribute__((cold)); {
			ASM_MARKER("__int__");
			interrupt_code = (*++ip).r64.r32.i;
			// check if interrupt handler request exit or interrupt is error (interrupt < 0) or success (interrupt == 0)
			if (__builtin_expect(!interrupt_handler(interrupt_code, usr_dat) || interrupt_code <= 0, 0)) {
				goto _terminate_;
			}
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__intrin__: __attribute__((hot));
		ASM_MARKER("__intrin__");
		syscall_intrin(sp, (*++ip).r64.u);				// syscall(sp, imm())
		goto **(bt + (*++ip).op);						// next_instr()

	__cintrin__: __attribute__((hot));
		ASM_MARKER("__cintrin__");
		if (__builtin_expect(!(**(intrinsic_table + (*++ip).r64.i))(sp), 0)) {
			goto _terminate_;
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__call__: __attribute__((hot)); {
			ASM_MARKER("__call__");
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__ret__: __attribute__((hot)); {
			ASM_MARKER("__ret__");
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__mov__: __attribute__((hot)); {
			ASM_MARKER("__mov__");
			const u64 dst{(*++ip).r64.u};				// imm() -> arg 1 (reg) - dst
			*(sp + dst) = *(sp + (*++ip).r64.u);		// poke(dst) = poke(imm())
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__sto__: __attribute__((hot)); {
			ASM_MARKER("__sto__");
			const u64 dst{(*++ip).r64.u};				// imm() -> arg 1 (reg) - dst
			(*(sp + dst)).u = (*++ip).r64.u;			// poke(dst) = imm()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__push__: __attribute__((hot));
		ASM_MARKER("__push__");
		STO_SENTINEL(1);
		*++sp = (*++ip).r64;							// push(imm())
		goto **(bt + (*++ip).op);						// next_instr()

	__pop__: __attribute__((hot));
		ASM_MARKER("__pop__");
		--sp;
		goto **(bt + (*++ip).op);						// next_instr()

	__pop2__: __attribute__((hot));
		ASM_MARKER("__pop2__");
		sp -= 2;
		goto **(bt + (*++ip).op);						// next_instr()

	__dupl__: __attribute__((hot)); {
			ASM_MARKER("__dupl__");
			STO_SENTINEL(1);
			const auto top{*sp};						// peek()
			*++sp = top;								// push(peek())
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__dupl2__: __attribute__((hot)); {
			STO_SENTINEL(2);
			const auto top{*sp};				// peek
			*++sp = top;						// push(peek())
			*++sp = top;						// push(peek())
		}
		goto **(bt + (*++ip).op);				// next_instr()

	__swap__: __attribute__((hot)); {
			ASM_MARKER("__swap__");
			const auto top = *sp;				// backup = top()
			*sp = *(sp - 1);					// top() = poke(1)
			*(sp - 1) = top;					// poke(1) = backup
		}
		goto **(bt + (*++ip).op);				// next_instr()
		
	__nop__: __attribute__((cold));
		ASM_MARKER("__nop__");
		goto **(bt + (*++ip).op);				// next_instr()
		
	__jmp__: __attribute__((hot)); {
			ASM_MARKER("__jmp__");
			const u64 abs{(*++ip).r64.u};				// absolute address
			ip = ip_lo + abs;							// ip = begin + offset
		}
		goto **(bt + (*ip).op);							// next_instr() -> no inc -> new address

	__jmprel__: __attribute__((hot)); {
			ASM_MARKER("__jmprel__");
			const u64 rel{(*++ip).r64.u};				// relative address
			ip += rel;									// ip +-= rel
		}
		goto **(bt + (*ip).op);							// next_instr() -> no inc -> new address

	__jz__: __attribute__((hot)); {
			ASM_MARKER("__jz__");
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp--).u == 0) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
		}	
		goto **(bt + (*++ip).op);						// next_instr()

	__jnz__: __attribute__((hot)); {
			ASM_MARKER("__jnz__");
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp--).u != 0) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jo_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jo_cmpi__");
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp--).i == 1) {						// pop()
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jo_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jo_cmpf__");
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp--).f == 1.0) {						// pop()
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jno_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jno_cmpi__");
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp--).i != 1) {						// pop()
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jno_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jno_cmpf__");
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp--).f != 1.0) {						// pop()
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(bt + (*++ip).op);						// next_instr()
		
	__je_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__je_cmpi__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).i == (*(sp + 1)).i) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__je_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__je_cmpf__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).f == (*(sp + 1)).f) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jne_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jne_cmpi__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).i != (*(sp + 1)).i) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jne_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jne_cmpf__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).f != (*(sp + 1)).f) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__ja_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__ja_cmpi__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).i > (*(sp + 1)).i) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__ja_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__ja_cmpf__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).f > (*(sp + 1)).f) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jl_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jl_cmpi__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).i < (*(sp + 1)).i) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jl_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jl_cmpf__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).f < (*(sp + 1)).f) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jae_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jae_cmpi__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).i >= (*(sp + 1)).i) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jae_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jae_cmpf__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).f >= (*(sp + 1)).f) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jle_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jle_cmpi__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).i <= (*(sp + 1)).i) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__jle_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jle_cmpf__");
			--sp;										// pop()
			const u64 abs{(*++ip).r64.u};				// absolute address
			if ((*sp).f <= (*(sp + 1)).f) {
				ip = ip_lo + abs - 1;					// ip = begin + offset - 1 (inc stride)
			}
			--sp;										// pop()
		}
		goto **(bt + (*++ip).op);						// next_instr()

	__ipushz__: __attribute__((hot));
		ASM_MARKER("__ipushz__");
		STO_SENTINEL(1);
		(*++sp).u = 0;									// push(0)
		goto **(bt + (*++ip).op);						// next_instr()

	__ipusho__: __attribute__((hot));
		ASM_MARKER("__ipusho__");
		STO_SENTINEL(1);
		(*++sp).u = 1;									// push(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__fpusho__: __attribute__((hot));
		ASM_MARKER("__fpusho__");
		STO_SENTINEL(1);
		(*++sp).f = 1.0;								// push(1)
		goto **(bt + (*++ip).op);						// next_instr()
		
	__iinc__: __attribute__((hot));
		ASM_MARKER("__iinc__");
		++(*sp).i;
		goto **(bt + (*++ip).op);						// next_instr()

	__idec__: __attribute__((hot));
		ASM_MARKER("__idec__");
		--(*sp).i;
		goto **(bt + (*++ip).op);						// next_instr()

	__iadd__: __attribute__((hot));
		ASM_MARKER("__iadd__");
		--sp;											// pop
		(*sp).i += (*(sp + 1)).i;						// peek() += poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__isub__: __attribute__((hot));
		ASM_MARKER("__isub__");
		--sp;											// pop
		(*sp).i -= (*(sp + 1)).i;						// peek() -= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()
		
	__imul__: __attribute__((hot));
		ASM_MARKER("__imul__");
		--sp;											// pop
		(*sp).i *= (*(sp + 1)).i;						// peek() *= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__idiv__: __attribute__((hot));
		ASM_MARKER("__idiv__");
		--sp;											// pop
		(*sp).i /= (*(sp + 1)).i;						// peek() /= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__imod__: __attribute__((hot));
		ASM_MARKER("__imod__");
		--sp;											// pop
		(*sp).i %= (*(sp + 1)).i;						// peek() %= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__iand__: __attribute__((hot));
		ASM_MARKER("__iand__");
		--sp;											// pop
		(*sp).i &= (*(sp + 1)).i;						// peek() &= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__ior__: __attribute__((hot));
		ASM_MARKER("__ior__");
		--sp;											// pop
		(*sp).i |= (*(sp + 1)).i;						// peek() |= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__ixor__: __attribute__((hot));
		ASM_MARKER("__ixor__");
		--sp;											// pop
		(*sp).i ^= (*(sp + 1)).i;						// peek() ^= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__icom__: __attribute__((hot));
		ASM_MARKER("__icom__");
		(*sp).i = ~(*sp).i;
		goto **(bt + (*++ip).op);						// next_instr()

	__isal__: __attribute__((hot));
		ASM_MARKER("__isal__");
		--sp;											// pop
		(*sp).i <<= (*(sp + 1)).i;						// peek() <<= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__isar__: __attribute__((hot));
		ASM_MARKER("__isar__");
		--sp;											// pop
		(*sp).i >>= (*(sp + 1)).i;						// peek() >>= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__irol__: __attribute__((hot));
		ASM_MARKER("__irol__");
		--sp;											// pop
		(*sp).u = rol((*sp).u, (*(sp + 1)).r32.i);
		goto **(bt + (*++ip).op);						// next_instr()

	__iror__: __attribute__((hot));
		ASM_MARKER("__iror__");
		--sp;											// pop
		(*sp).u = ror((*sp).u, (*(sp + 1)).r32.i);
		goto **(bt + (*++ip).op);						// next_instr()

	__ineg__: __attribute__((hot));
		ASM_MARKER("__ineg__");
		(*sp).i = -(*sp).i;
		goto **(bt + (*++ip).op);						// next_instr()

	__fadd__: __attribute__((hot));
		ASM_MARKER("__fadd__");
		--sp;											// pop
		(*sp).f += (*(sp + 1)).f;						// peek() += poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__fsub__: __attribute__((hot));
		ASM_MARKER("__fsub__");
		--sp;											// pop
		(*sp).f -= (*(sp + 1)).f;						// peek() -= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__fmul__: __attribute__((hot));
		ASM_MARKER("__fmul__");
		--sp;											// pop
		(*sp).f *= (*(sp + 1)).f;						// peek() *= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__fdiv__: __attribute__((hot));
		ASM_MARKER("__fdiv__");
		--sp;											// pop
		(*sp).f /= (*(sp + 1)).f;						// peek() /= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__fmod__: __attribute__((hot));
		ASM_MARKER("__fmod__");
		--sp;											// pop
		*sp %= (*(sp + 1)).f;							// peek() %= poke(1)
		goto **(bt + (*++ip).op);						// next_instr()

	__fneg__: __attribute__((hot));
		ASM_MARKER("__fneg__");
		(*sp).f = -(*sp).f;
		goto **(bt + (*++ip).op);						// next_instr()

	__finc__: __attribute__((hot));
		ASM_MARKER("__finc__");
		++sp->f;
		goto **(bt + (*++ip).op);						// next_instr()

	__fdec__: __attribute__((hot));
		ASM_MARKER("__fdec__");
		--sp->f;
		goto **(bt + (*++ip).op);						// next_instr()

	_hard_fault_err_: __attribute__((cold));
	_terminate_: __attribute__((cold));
		ASM_MARKER("_terminate_");
		return {
			.input = &input_,
			.validation_result = reactor_validation_result::ok,
			.terminate_result = terminate_type_cvt(interrupt_code),
			.system_interrupt = interrupt_cvt(interrupt_code),
			.pre = pre,
			.post = std::chrono::high_resolution_clock::now(),
			.duration = std::chrono::high_resolution_clock::now() - pre,
			.interrupt_code = interrupt_code,
			.ip_diff = static_cast<std::ptrdiff_t>(ip - input_.code_chunk),
			.sp_diff = static_cast<std::ptrdiff_t>(sp - input_.stack),
		};
	}
}
