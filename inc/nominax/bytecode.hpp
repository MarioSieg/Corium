#pragma once

#include "record.hpp"

namespace nominax {
	using opcode = std::uint64_t;
	
	enum class alignas(alignof(opcode)) instruction: opcode {
		inter		= 0x00'00'00'00'00'00'00'00,
		intrin		= 0x00'00'00'00'00'00'00'01,
		call		= 0x00'00'00'00'00'00'00'02,
		ret			= 0x00'00'00'00'00'00'00'03,
		mov			= 0x00'00'00'00'00'00'00'04,
		sto			= 0x00'00'00'00'00'00'00'05,
		push		= 0x00'00'00'00'00'00'00'06,
		pop			= 0x00'00'00'00'00'00'00'07,
		pop2		= 0x00'00'00'00'00'00'00'08,
		dupl		= 0x00'00'00'00'00'00'00'09,
		dupl2		= 0x00'00'00'00'00'00'00'0A,
		nop			= 0x00'00'00'00'00'00'00'0B,
		pushz		= 0x00'00'00'00'00'00'00'0C,
		ipusho		= 0x00'00'00'00'00'00'00'0D,
		fpusho		= 0x00'00'00'00'00'00'00'0E,
		iinc		= 0x00'00'00'00'00'00'00'0F,
		idec		= 0x00'00'00'00'00'00'00'10,
		iadd		= 0x00'00'00'00'00'00'00'11,
		isub		= 0x00'00'00'00'00'00'00'12,
		imul		= 0x00'00'00'00'00'00'00'13,
		idiv		= 0x00'00'00'00'00'00'00'14,
		imod		= 0x00'00'00'00'00'00'00'15,
		iand		= 0x00'00'00'00'00'00'00'16,
		ior			= 0x00'00'00'00'00'00'00'17,
		ixor		= 0x00'00'00'00'00'00'00'18,
		icom		= 0x00'00'00'00'00'00'00'19,
		isal		= 0x00'00'00'00'00'00'00'1A,
		isar		= 0x00'00'00'00'00'00'00'1B,
		irol		= 0x00'00'00'00'00'00'00'1C,
		iror		= 0x00'00'00'00'00'00'00'1D,
		ineg		= 0x00'00'00'00'00'00'00'1E,
		fadd		= 0x00'00'00'00'00'00'00'1F,
		fsub		= 0x00'00'00'00'00'00'00'20,
		fmul		= 0x00'00'00'00'00'00'00'21,
		fdiv		= 0x00'00'00'00'00'00'00'22,
		fmod		= 0x00'00'00'00'00'00'00'23,
		fneg		= 0x00'00'00'00'00'00'00'24,
		finc		= 0x00'00'00'00'00'00'00'25,
		fdec		= 0x00'00'00'00'00'00'00'26,
		jmp			= 0x00'00'00'00'00'00'00'27,
		jmprel		= 0x00'00'00'00'00'00'00'28,
		jz			= 0x00'00'00'00'00'00'00'29,
		jnz			= 0x00'00'00'00'00'00'00'2A,
		jo_cmpi		= 0x00'00'00'00'00'00'00'2B,
		jo_cmpf		= 0x00'00'00'00'00'00'00'2C,
		jno_cmpi	= 0x00'00'00'00'00'00'00'2D,
		jno_cmpf	= 0x00'00'00'00'00'00'00'2E,
		je_cmpi		= 0x00'00'00'00'00'00'00'2F,
		je_cmpf		= 0x00'00'00'00'00'00'00'30,
		jne_cmpi	= 0x00'00'00'00'00'00'00'31,
		jne_cmpf	= 0x00'00'00'00'00'00'00'32,
		ja_cmpi		= 0x00'00'00'00'00'00'00'33,
		ja_cmpf		= 0x00'00'00'00'00'00'00'34,
		jl_cmpi		= 0x00'00'00'00'00'00'00'35,
		jl_cmpf		= 0x00'00'00'00'00'00'00'36,
		jae_cmpi	= 0x00'00'00'00'00'00'00'37,
		jae_cmpf	= 0x00'00'00'00'00'00'00'38,
		jle_cmpi	= 0x00'00'00'00'00'00'00'39,
		jle_cmpf	= 0x00'00'00'00'00'00'00'3A,
		
		count
	};

	/* 64-bit byte code signal data contains either an instruction or an immediate value. */
	union alignas(alignof(opcode)) csignal {
		record64 r64;
		instruction instr;
		opcode op;
		void* ptr;

		explicit constexpr csignal(record64 x_) noexcept;
		explicit constexpr csignal(instruction x_) noexcept;
		explicit constexpr csignal(void* x_) noexcept;
		explicit constexpr csignal(i64 x_) noexcept;
		explicit constexpr csignal(u64 x_) noexcept;
		explicit constexpr csignal(f64 x_) noexcept;
		explicit constexpr csignal(c32 x_) noexcept;
	};

	constexpr csignal::csignal(const record64 x_) noexcept : r64{x_} {}
	constexpr csignal::csignal(const instruction x_) noexcept : instr{x_} {}
	constexpr csignal::csignal(void* const x_) noexcept : ptr{x_} {}
	constexpr csignal::csignal(const i64 x_) noexcept : r64{x_} {}
	constexpr csignal::csignal(const u64 x_) noexcept : r64{x_} {}
	constexpr csignal::csignal(const f64 x_) noexcept : r64{x_} {}
	constexpr csignal::csignal(const c32 x_) noexcept : r64{x_} {}

	constexpr auto operator""_sig_u(const unsigned long long int x_) noexcept -> csignal {
		return csignal{static_cast<u64>(x_)};
	}

	constexpr auto operator""_sig_i(const unsigned long long int x_) noexcept -> csignal {
		return csignal{static_cast<i64>(x_)};
	}

	constexpr auto operator""_sig_f(const long double x_) noexcept -> csignal {
		return csignal{static_cast<f64>(x_)};
	}

	static_assert(std::is_same_v<std::underlying_type_t<instruction>, std::uint64_t>);
	static_assert(sizeof(instruction) == alignof(u64));
	static_assert(alignof(instruction) == alignof(u64));
	static_assert(sizeof(csignal) == alignof(u64));
	static_assert(alignof(csignal) == alignof(u64));
	static_assert(std::is_standard_layout_v<csignal>);
}
