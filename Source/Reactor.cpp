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

#include "../Include/Nominax/Reactor.hpp"
#include "../Include/Nominax/Interrupts.hpp"
#include "../Include/Nominax/MacroCfg.hpp"

namespace Nominax {
	auto ReactorInput::Validate() const noexcept -> ReactorValidationResult {
		// validate all pointers:
		if (__builtin_expect(!(this->SignalStatus && this->CodeChunk && this->IntrinsicTable && this->InterruptHandler && this->Stack), 0)) {
			return ReactorValidationResult::NullPtr;
		}

		// validate the size for the corresponding pointers:
		if (__builtin_expect(!this->CodeChunkSize || !this->IntrinsicTableSize || !this->StackSize, 0)) {
			return ReactorValidationResult::ZeroSize;
		}

		// first instruction will be skipped and must be NOP:
		if (__builtin_expect(CodeChunk->Instr != Instruction::nop, 0)) {
			return ReactorValidationResult::MissingCodePrologue;
		}

		// last instruction must be interrupt:
		if (__builtin_expect(CodeChunkSize < 2, 0) || __builtin_expect((CodeChunk + CodeChunkSize - 2)->Instr != Instruction::inter, 0)) {
			return ReactorValidationResult::MissingCodeEpilogue;
		}

		// first stack entry is never used and must be nop-padding:
		if (__builtin_expect(*Stack != Record64::Padding(), 0)) {
			return ReactorValidationResult::MissingStackPrologue;
		}

		// validate intrinsic routines:
		auto** begin = this->IntrinsicTable;
		auto** const end = this->IntrinsicTable + this->IntrinsicTableSize;
		while (__builtin_expect(begin < end, 1)) {
			if (__builtin_expect(!*begin++, 0)) {
				return ReactorValidationResult::NullIntrinsicRoutine;
			}
		}

		return ReactorValidationResult::Ok;
	}

	/// <summary>
	/// Fast, platform dependent implementation for a bitwise left rotation.
	/// </summary>
	[[nodiscard]] __attribute__((always_inline, pure)) static inline auto Rol64(std::uint64_t value, const std::uint8_t shift) noexcept -> std::uint64_t {
		#if NOMINAX_OS_WINDOWS && NOMINAX_USE_ARCH_OPT && NOMINAX_ARCH_X86_64
				return _rotl64(value, shift);
		#elif !NOMINAX_OS_WINDOWS && NOMINAX_USE_ARCH_OPT && NOMINAX_ARCH_X86_64
				asm volatile(
					"rolq %%cl, %0"
					: "=r"(value)
					: "0" (value), "c"(shift)
					);
				return value;
		#else
				return std::rotl<std::uint64_t>(value, shift);
		#endif
	}

	/// <summary>
	/// Fast, platform dependent implementation for a bitwise right rotation.
	/// </summary>
	[[nodiscard]] __attribute__((always_inline, pure)) static inline auto Ror64(std::uint64_t value, const std::uint8_t shift) noexcept -> std::uint64_t {
		#if NOMINAX_OS_WINDOWS && NOMINAX_USE_ARCH_OPT && NOMINAX_ARCH_X86_64
				return _rotr64(value, shift);
		#elif !NOMINAX_OS_WINDOWS && NOMINAX_USE_ARCH_OPT && NOMINAX_ARCH_X86_64
				asm volatile(
					"rorq %%cl, %0"
					: "=r"(value)
					: "0" (value), "c"(shift)
					);
				return value;
		#else
				return std::rotr<std::uint64_t>(value, shift);
		#endif
	}

	/// <summary>
	/// Operator for double precision floating point modulo.
	/// </summary>
	__attribute__((always_inline)) static inline void operator %=(Record64& self, const double value) noexcept {
		self.F64 = std::fmod(self.F64, value);
	}

	/// <summary>
	/// Trigger a breakpoint.
	/// </summary>
	[[maybe_unused]] __attribute__((always_inline, cold)) static inline auto BreakpointInterrupt() noexcept -> void
	{
		#if NOMINAX_ARCH_X86_64
				asm("int $3");
		#elif NOMINAX_ARCH_ARM_64
			#if NOMINAX_OS_MAC || NOMINAX_OS_IOS
					asm("trap");
			#else
					asm("bkpt 0");
			#endif
		#else
				auto* int3 = reinterpret_cast<int*>(3);
				*int3 = 3;
		#endif
	}

	/// <summary>
	/// Insert memory read fence barrier.
	/// </summary>
	__attribute__((always_inline)) inline void ReadFence() noexcept {
		asm volatile("":::"memory");
	}

	/// <summary>
	/// Insert memory write fence barrier.
	/// </summary>
	__attribute__((always_inline)) inline void WriteFence() noexcept {
		asm volatile("":::"memory");
	}

	/// <summary>
	/// Insert memory read-write fence barrier.
	/// </summary>
	__attribute__((always_inline)) inline void ReadWriteFence() noexcept {
		asm volatile("":::"memory");
	}

	#if NOMINAX_REACTOR_ASM_MARKERS
		/*
		 * This inserts a comment with the msg into the assembler code.
		 * Useful for finding the asm code of the instructions.
		 * These should be disabled when building for release.
		 * Asm volatile is like a black box and never touched by the compiler so it might affect code generation/ordering!
		 */
		#define ASM_MARKER(msg) asm volatile("#" msg)
	#else
		#define ASM_MARKER(msg)
	#endif

	#if NOMINAX_STACK_OVERFLOW_CHECKS
		/* Inserts a stack overflow sentinel, which triggers a system interrupt
		 * of type stack_overflow by setting the interrupt accumulator and jumping to the fault label.
		 * This of course adds some overhead, but not much.
		 * If stack overflow sentinels are disabled, a stack overflow will trigger a
		 * segmentation fault (SIGSEGV), which will be handled by the signal handler
		 * set in interrupts.hpp
		 * The
		 * x is the number of pushes to check for.
		 * x = 1 -> check for 1 more push
		 * x = 2 -> check for 2 more pushes
		 * etc..
		 */
		#define STO_SENTINEL(x)																						\
			do {																									\
				if (__builtin_expect(sp + ((x) - 1) >= spHi, 0)) {													\
					interruptCode = static_cast<decltype(interruptCode)>(SystemInterrupt::StackOverflow);			\
					goto _hard_fault_err_;																			\
				}																									\
			} while(false)
	#else
		#define STO_SENTINEL(x)
	#endif

	/// <summary>
	/// Implementation for the "intrin" instruction.
	/// This contains a jump table with the implementation of all system intrinsic routines.
	/// The stack pointer is copied, so all local pushes will be popped automatically when
	/// returning. Since all local pushes and pops are not updates to the original stack pointer,
	/// this function can only modify the stack values, but not the original sp.
	/// For that reason the intrinsic routines requires the caller to push/pop the arguments and the return values.
	/// This is very important!
	/// So for single argument intrinsic routines, the intrinsic routine just modifies the stack top:
	/// For example (pseudo code):
	/// stack[0] = sin(stack[0])
	/// If a preserved value is needed, a call to "dupl" is needed before calling "intrin".
	/// A two argument intrinsic routine will write the result into the previous stack element and use the top as second argument:
	/// stack[-1] = atan2(stack[-1], stack[0])
	/// So the stack will be:
	/// +---+-------+
	/// |sp | value |
	/// +---+-------+
	/// | 0 | 12233 | << top -> stack[0] -> (arg1 and result)
	/// +---+-------+
	/// | 1 | 27223 | << top - 1 -> stack[-1] -> (arg2)
	/// +---+-------+
	/// So stack[-1] will be overwritten and contains the result.
	/// stack[0] will still contain arg2.
	/// </summary>
	__attribute__((hot)) static void SyscallIntrin(Record64* const sp, const std::uint64_t id) {
		static constexpr const void* __restrict__ BRANCH_TABLE[static_cast<std::size_t>(SystemIntrinsicID::count_)] {
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

		struct $ {
			[[nodiscard]]
			static consteval auto ValidateBranchTable() noexcept -> bool {
				const auto* current = BRANCH_TABLE;
				const auto* const end = BRANCH_TABLE + sizeof BRANCH_TABLE / sizeof *BRANCH_TABLE;
				while (__builtin_expect(current < end, 1)) {
					if (__builtin_expect(!(*current++), 0)) {
						return false;
					}
				}
				return true;
			}
		};
		static_assert($::ValidateBranchTable());

		goto **(BRANCH_TABLE + id);
		
	__cos__: __attribute__((hot));
		(*sp).F64 = std::cos((*sp).F64);
		return;
		
	__sin__: __attribute__((hot));
		(*sp).F64 = std::sin((*sp).F64);
		return;
		
	__tan__: __attribute__((hot));
		(*sp).F64 = std::tan((*sp).F64);
		return;
		
	__acos__: __attribute__((hot));
		(*sp).F64 = std::acos((*sp).F64);
		return;
		
	__asin__: __attribute__((hot));
		(*sp).F64 = std::asin((*sp).F64);
		return;
		
	__atan__: __attribute__((hot));
		(*sp).F64 = std::atan((*sp).F64);
		return;
		
	__atan2__: __attribute__((hot));
		(*(sp - 1)).F64 = std::atan2((*(sp - 1)).F64, (*sp).F64);
		return;
		
	__cosh__: __attribute__((hot));
		(*sp).F64 = std::cosh((*sp).F64);
		return;
		
	__sinh__: __attribute__((hot));
		(*sp).F64 = std::sinh((*sp).F64);
		return;
		
	__tanh__: __attribute__((hot));
		(*sp).F64 = std::tanh((*sp).F64);
		return;
		
	__acosh__: __attribute__((hot));
		(*sp).F64 = std::acosh((*sp).F64);
		return;
		
	__asinh__: __attribute__((hot));
		(*sp).F64 = std::asinh((*sp).F64);
		return;
		
	__atanh__: __attribute__((hot));
		(*sp).F64 = std::atanh((*sp).F64);
		return;
		
	__exp__: __attribute__((hot));
		(*sp).F64 = std::exp((*sp).F64);
		return;
		
	__log__: __attribute__((hot));
		(*sp).F64 = std::log((*sp).F64);
		return;
		
	__log10__: __attribute__((hot));
		(*sp).F64 = std::log10((*sp).F64);
		return;
		
	__exp2__: __attribute__((hot));
		(*sp).F64 = std::exp2((*sp).F64);
		return;
		
	__ilogb__: __attribute__((hot));
		(*sp).I64 = std::ilogb((*sp).F64);
		return;
		
	__log2__: __attribute__((hot));
		(*sp).F64 = std::log2((*sp).F64);
		return;
		
	__pow__: __attribute__((hot));
		(*(sp - 1)).F64 = std::pow((*(sp - 1)).F64, (*sp).F64);
		return;
		
	__sqrt__: __attribute__((hot));
		(*sp).F64 = std::sqrt((*sp).F64);
		return;
		
	__cbrt__: __attribute__((hot));
		(*sp).F64 = std::cbrt((*sp).F64);
		return;
		
	__hypot__: __attribute__((hot));
		(*(sp - 1)).F64 = std::hypot((*(sp - 1)).F64, (*sp).F64);
		return;
		
	__ceil__: __attribute__((hot));
		(*sp).F64 = std::ceil((*sp).F64);
		return;
		
	__floor__: __attribute__((hot));
		(*sp).F64 = std::floor((*sp).F64);
		return;
		
	__round__: __attribute__((hot));
		(*sp).F64 = std::round((*sp).F64);
		return;
		
	__rint__: __attribute__((hot));
		(*sp).F64 = std::rint((*sp).F64);
		return;
		
	__max__: __attribute__((hot));
		(*(sp - 1)).I64 = std::max((*(sp - 1)).I64, (*sp).I64);
		return;
		
	__min__: __attribute__((hot));
		(*(sp - 1)).I64 = std::min((*(sp - 1)).I64, (*sp).I64);
		return;
		
	__fmax__: __attribute__((hot));
		(*(sp - 1)).F64 = std::max((*(sp - 1)).F64, (*sp).F64);
		return;
		
	__fmin__: __attribute__((hot));
		(*(sp - 1)).F64 = std::min((*(sp - 1)).F64, (*sp).F64);
		return;
		
	__fdim__: __attribute__((hot));
		(*(sp - 1)).F64 = std::fdim((*(sp - 1)).F64, (*sp).F64);
		return;
		
	__abs__: __attribute__((hot));
		(*sp).I64 = std::abs((*sp).I64);
		return;
		
	__fabs__: __attribute__((hot));
		(*sp).F64 = std::abs((*sp).F64);
		return;
	}

	__attribute__((hot)) auto ExecuteChecked(const ReactorInput& input) -> ReactorOutput {
		if (const auto result = input.Validate(); __builtin_expect(result != ReactorValidationResult::Ok, 0)) {
			return {
				.Input = &input,
				.ValidationResult = result,
			};
		}
		
		const auto pre = std::chrono::high_resolution_clock::now();

		static constexpr const void* __restrict__ const BRANCH_TABLE[static_cast<std::size_t>(Instruction::count_)] {
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
				const auto* iter = BRANCH_TABLE;
				const auto* const end = BRANCH_TABLE + sizeof BRANCH_TABLE / sizeof *BRANCH_TABLE;
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
		
		InterruptAccumulator								interruptCode		{};												/* interrupt ID flag        */
		void* __restrict__									usrDat				{input.UserData};								/* user data                */
		intrinsic_routine* const* const						intrinsicTable		{input.IntrinsicTable};						/* intrinsic table hi       */
		InterruptRoutine* const								interruptHandler	{input.InterruptHandler};						/* global interrupt routine */
		const Signal* const __restrict						ipLo				{input.CodeChunk};							/* instruction low Ptr      */
		const Signal* __restrict__							ip					{ipLo};										/* instruction Ptr			*/
		Record64* __restrict__								sp					{input.Stack};									/* stack pointer lo			*/
		Record64* const	__restrict__						spHi				{input.Stack + input.StackSize - 1};			/* stack pointer hi			*/

		ASM_MARKER("reactor exec");

		// exec first:
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__int__: __attribute__((cold)); {
			ASM_MARKER("__int__");
			interruptCode = (*++ip).R64.R32.I32;
			// check if interrupt handler request exit or interrupt is error (interrupt < 0) or success (interrupt == 0)
			if (__builtin_expect(!interruptHandler(interruptCode, usrDat) || interruptCode <= 0, 0)) {
				goto _terminate_;
			}
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__intrin__: __attribute__((hot));
		ASM_MARKER("__intrin__");
		SyscallIntrin(sp, (*++ip).R64.U64);				// syscall(sp, imm())
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__cintrin__: __attribute__((hot));
		ASM_MARKER("__cintrin__");
		if (__builtin_expect(!(**(intrinsicTable + (*++ip).R64.U64))(sp), 0)) {
			goto _terminate_;
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__call__: __attribute__((hot)); {
			ASM_MARKER("__call__");
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__ret__: __attribute__((hot)); {
			ASM_MARKER("__ret__");
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__mov__: __attribute__((hot)); {
			ASM_MARKER("__mov__");
			const std::uint64_t dst{(*++ip).R64.U64};		// imm() -> arg 1 (reg) - dst
			*(sp + dst) = *(sp + (*++ip).R64.U64);			// poke(dst) = poke(imm())
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__sto__: __attribute__((hot)); {
			ASM_MARKER("__sto__");
			const std::uint64_t dst{(*++ip).R64.U64 };		// imm() -> arg 1 (reg) - dst
			(*(sp + dst)).U64 = (*++ip).R64.U64;			// poke(dst) = imm()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__push__: __attribute__((hot));
		ASM_MARKER("__push__");
		STO_SENTINEL(1);
		*++sp = (*++ip).R64;								// push(imm())
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__pop__: __attribute__((hot));
		ASM_MARKER("__pop__");
		--sp;
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__pop2__: __attribute__((hot));
		ASM_MARKER("__pop2__");
		sp -= 2;
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__dupl__: __attribute__((hot)); {
			ASM_MARKER("__dupl__");
			STO_SENTINEL(1);
			const auto top{*sp};							// peek()
			*++sp = top;									// push(peek())
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__dupl2__: __attribute__((hot)); {
			STO_SENTINEL(2);
			const auto top{*sp};							// peek
			*++sp = top;									// push(peek())
			*++sp = top;									// push(peek())
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__swap__: __attribute__((hot)); {
			ASM_MARKER("__swap__");
			const auto top = *sp;							// backup = top()
			*sp = *(sp - 1);								// top() = poke(1)
			*(sp - 1) = top;								// poke(1) = backup
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()
		
	__nop__: __attribute__((cold));
		ASM_MARKER("__nop__");
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()
		
	__jmp__: __attribute__((hot)); {
			ASM_MARKER("__jmp__");
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			ip = ipLo + abs;								// ip = begin + offset
		}
		goto **(BRANCH_TABLE + (*ip).OpCode);							// next_instr() -> no inc -> new address

	__jmprel__: __attribute__((hot)); {
			ASM_MARKER("__jmprel__");
			const std::uint64_t rel{(*++ip).R64.U64};		// relative address
			ip += rel;										// ip +-= rel
		}
		goto **(BRANCH_TABLE + (*ip).OpCode);							// next_instr() -> no inc -> new address

	__jz__: __attribute__((hot)); {
			ASM_MARKER("__jz__");
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp--).I64 == 0) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
		}	
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jnz__: __attribute__((hot)); {
			ASM_MARKER("__jnz__");
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp--).I64 != 0) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jo_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jo_cmpi__");
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp--).I64 == 1) {							// pop()
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jo_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jo_cmpf__");
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp--).F64 == 1.0) {						// pop()
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jno_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jno_cmpi__");
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp--).I64 != 1) {							// pop()
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jno_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jno_cmpf__");
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp--).F64 != 1.0) {						// pop()
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()
		
	__je_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__je_cmpi__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).I64 == (*(sp + 1)).I64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__je_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__je_cmpf__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).F64 == (*(sp + 1)).F64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jne_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jne_cmpi__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).I64 != (*(sp + 1)).I64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jne_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jne_cmpf__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).F64 != (*(sp + 1)).F64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__ja_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__ja_cmpi__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).I64 > (*(sp + 1)).I64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__ja_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__ja_cmpf__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).F64 > (*(sp + 1)).F64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jl_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jl_cmpi__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).I64 < (*(sp + 1)).I64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jl_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jl_cmpf__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).F64 < (*(sp + 1)).F64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jae_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jae_cmpi__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).I64 >= (*(sp + 1)).I64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jae_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jae_cmpf__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).F64 >= (*(sp + 1)).F64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jle_cmpi__: __attribute__((hot)); {
			ASM_MARKER("__jle_cmpi__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).I64 <= (*(sp + 1)).I64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__jle_cmpf__: __attribute__((hot)); {
			ASM_MARKER("__jle_cmpf__");
			--sp;											// pop()
			const std::uint64_t abs{(*++ip).R64.U64};		// absolute address
			if ((*sp).F64 <= (*(sp + 1)).F64) {
				ip = ipLo + abs - 1;						// ip = begin + offset - 1 (inc stride)
			}
			--sp;											// pop()
		}
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__ipushz__: __attribute__((hot));
		ASM_MARKER("__ipushz__");
		STO_SENTINEL(1);
		(*++sp).I64 = 0;									// push(0)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__ipusho__: __attribute__((hot));
		ASM_MARKER("__ipusho__");
		STO_SENTINEL(1);
		(*++sp).I64 = 1;									// push(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__fpusho__: __attribute__((hot));
		ASM_MARKER("__fpusho__");
		STO_SENTINEL(1);
		(*++sp).F64 = 1.0;									// push(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()
		
	__iinc__: __attribute__((hot));
		ASM_MARKER("__iinc__");
		++(*sp).I64;
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__idec__: __attribute__((hot));
		ASM_MARKER("__idec__");
		--(*sp).I64;
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__iadd__: __attribute__((hot));
		ASM_MARKER("__iadd__");
		--sp;											// pop
		(*sp).I64 += (*(sp + 1)).I64;						// peek() += poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__isub__: __attribute__((hot));
		ASM_MARKER("__isub__");
		--sp;											// pop
		(*sp).I64 -= (*(sp + 1)).I64;						// peek() -= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()
		
	__imul__: __attribute__((hot));
		ASM_MARKER("__imul__");
		--sp;											// pop
		(*sp).I64 *= (*(sp + 1)).I64;						// peek() *= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__idiv__: __attribute__((hot));
		ASM_MARKER("__idiv__");
		--sp;											// pop
		(*sp).I64 /= (*(sp + 1)).I64;						// peek() /= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__imod__: __attribute__((hot));
		ASM_MARKER("__imod__");
		--sp;											// pop
		(*sp).I64 %= (*(sp + 1)).I64;						// peek() %= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__iand__: __attribute__((hot));
		ASM_MARKER("__iand__");
		--sp;											// pop
		(*sp).I64 &= (*(sp + 1)).I64;						// peek() &= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__ior__: __attribute__((hot));
		ASM_MARKER("__ior__");
		--sp;											// pop
		(*sp).I64 |= (*(sp + 1)).I64;						// peek() |= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__ixor__: __attribute__((hot));
		ASM_MARKER("__ixor__");
		--sp;											// pop
		(*sp).I64 ^= (*(sp + 1)).I64;						// peek() ^= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__icom__: __attribute__((hot));
		ASM_MARKER("__icom__");
		(*sp).I64 = ~(*sp).I64;
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__isal__: __attribute__((hot));
		ASM_MARKER("__isal__");
		--sp;											// pop
		(*sp).I64 <<= (*(sp + 1)).I64;						// peek() <<= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__isar__: __attribute__((hot));
		ASM_MARKER("__isar__");
		--sp;											// pop
		(*sp).I64 >>= (*(sp + 1)).I64;						// peek() >>= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__irol__: __attribute__((hot));
		ASM_MARKER("__irol__");
		--sp;											// pop
		(*sp).U64 = Rol64((*sp).U64, (*(sp + 1)).U64);
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__iror__: __attribute__((hot));
		ASM_MARKER("__iror__");
		--sp;											// pop
		(*sp).U64 = Ror64((*sp).U64, (*(sp + 1)).U64);
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__ineg__: __attribute__((hot));
		ASM_MARKER("__ineg__");
		(*sp).I64 = -(*sp).I64;
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__fadd__: __attribute__((hot));
		ASM_MARKER("__fadd__");
		--sp;											// pop
		(*sp).F64 += (*(sp + 1)).F64;						// peek() += poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__fsub__: __attribute__((hot));
		ASM_MARKER("__fsub__");
		--sp;											// pop
		(*sp).F64 -= (*(sp + 1)).F64;						// peek() -= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__fmul__: __attribute__((hot));
		ASM_MARKER("__fmul__");
		--sp;											// pop
		(*sp).F64 *= (*(sp + 1)).F64;						// peek() *= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__fdiv__: __attribute__((hot));
		ASM_MARKER("__fdiv__");
		--sp;											// pop
		(*sp).F64 /= (*(sp + 1)).F64;						// peek() /= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__fmod__: __attribute__((hot));
		ASM_MARKER("__fmod__");
		--sp;											// pop
		*sp %= (*(sp + 1)).F64;							// peek() %= poke(1)
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__fneg__: __attribute__((hot));
		ASM_MARKER("__fneg__");
		(*sp).F64 = -(*sp).F64;
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__finc__: __attribute__((hot));
		ASM_MARKER("__finc__");
		++(*sp).F64;
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	__fdec__: __attribute__((hot));
		ASM_MARKER("__fdec__");
		--(*sp).F64;
		goto **(BRANCH_TABLE + (*++ip).OpCode);						// next_instr()

	_hard_fault_err_: __attribute__((cold));
	_terminate_: __attribute__((cold));
		ASM_MARKER("_terminate_");
		return {
			.Input = &input,
			.ValidationResult = ReactorValidationResult::Ok,
			.TerminateResult = TerminateTypeCvt(interruptCode),
			.SystemInterrupt = InterruptCvt(interruptCode),
			.Pre = pre,
			.Post = std::chrono::high_resolution_clock::now(),
			.Duration = std::chrono::high_resolution_clock::now() - pre,
			.InterruptCode = interruptCode,
			.IpDiff = ip - input.CodeChunk,
			.SpDiff = sp - input.Stack,
		};
	}
}
