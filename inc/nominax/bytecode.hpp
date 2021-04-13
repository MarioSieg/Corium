#pragma once

#include <array>
#include <string_view>

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
		swap		= 0x00'00'00'00'00'00'00'0B,
		nop			= 0x00'00'00'00'00'00'00'0C,
		jmp			= 0x00'00'00'00'00'00'00'0D,
		jmprel		= 0x00'00'00'00'00'00'00'0E,
		jz			= 0x00'00'00'00'00'00'00'0F,
		jnz			= 0x00'00'00'00'00'00'00'10,
		jo_cmpi		= 0x00'00'00'00'00'00'00'11,
		jo_cmpf		= 0x00'00'00'00'00'00'00'12,
		jno_cmpi	= 0x00'00'00'00'00'00'00'13,
		jno_cmpf	= 0x00'00'00'00'00'00'00'14,
		je_cmpi		= 0x00'00'00'00'00'00'00'15,
		je_cmpf		= 0x00'00'00'00'00'00'00'16,
		jne_cmpi	= 0x00'00'00'00'00'00'00'17,
		jne_cmpf	= 0x00'00'00'00'00'00'00'18,
		ja_cmpi		= 0x00'00'00'00'00'00'00'19,
		ja_cmpf		= 0x00'00'00'00'00'00'00'1A,
		jl_cmpi		= 0x00'00'00'00'00'00'00'1B,
		jl_cmpf		= 0x00'00'00'00'00'00'00'1C,
		jae_cmpi	= 0x00'00'00'00'00'00'00'1D,
		jae_cmpf	= 0x00'00'00'00'00'00'00'1E,
		jle_cmpi	= 0x00'00'00'00'00'00'00'1F,
		jle_cmpf	= 0x00'00'00'00'00'00'00'20,
		pushz		= 0x00'00'00'00'00'00'00'21,
		ipusho		= 0x00'00'00'00'00'00'00'22,
		fpusho		= 0x00'00'00'00'00'00'00'23,
		iinc		= 0x00'00'00'00'00'00'00'24,
		idec		= 0x00'00'00'00'00'00'00'25,
		iadd		= 0x00'00'00'00'00'00'00'26,
		isub		= 0x00'00'00'00'00'00'00'27,
		imul		= 0x00'00'00'00'00'00'00'28,
		idiv		= 0x00'00'00'00'00'00'00'29,
		imod		= 0x00'00'00'00'00'00'00'2A,
		iand		= 0x00'00'00'00'00'00'00'2B,
		ior			= 0x00'00'00'00'00'00'00'2C,
		ixor		= 0x00'00'00'00'00'00'00'2D,
		icom		= 0x00'00'00'00'00'00'00'2E,
		isal		= 0x00'00'00'00'00'00'00'2F,
		isar		= 0x00'00'00'00'00'00'00'30,
		irol		= 0x00'00'00'00'00'00'00'31,
		iror		= 0x00'00'00'00'00'00'00'32,
		ineg		= 0x00'00'00'00'00'00'00'33,
		fadd		= 0x00'00'00'00'00'00'00'34,
		fsub		= 0x00'00'00'00'00'00'00'35,
		fmul		= 0x00'00'00'00'00'00'00'36,
		fdiv		= 0x00'00'00'00'00'00'00'37,
		fmod		= 0x00'00'00'00'00'00'00'38,
		fneg		= 0x00'00'00'00'00'00'00'39,
		finc		= 0x00'00'00'00'00'00'00'3A,
		fdec		= 0x00'00'00'00'00'00'00'3B,

		/* !no instruction - count of total instructions! */
		count_
	};

	/* instruction meta database */
	namespace idb {
		struct instruction_data_flags final {
			enum $ : std::uint8_t {
				none = 0,
				i64 = 1 << 0,
				f64 = 1 << 1,
				u64 = 1 << 2,
				c32 = 1 << 3,
				ref = 1 << 4,
			};
		};

		enum class instruction_type : std::uint8_t {
			control,
			memory,
			branching,
			arithmetic,
			bitwise
		};

		struct instruction_info final {
			const std::string_view mnemonic;
			const std::string_view description;
			const instruction_type type;
			const std::uint8_t push_count;
			const std::uint8_t pop_count;
			const std::uint8_t imm_arg_count;
		};
		
		constexpr std::array<const std::string_view, static_cast<std::size_t>(instruction::count_)> mnemonics {
			"inter",
			"intrin",
			"call",
			"ret",
			"mov",
			"sto",
			"push",
			"pop",
			"pop2",
			"dupl",
			"dupl2",
			"swap",
			"nop",
			"jmp",
			"jmprel",
			"jz",
			"jnz",
			"jo_cmpi",
			"jo_cmpf",
			"jno_cmpi",
			"jno_cmpf",
			"je_cmpi",
			"je_cmpf",
			"jne_cmpi",
			"jne_cmpf",
			"ja_cmpi",
			"ja_cmpf",
			"jl_cmpi",
			"jl_cmpf",
			"jae_cmpi",
			"jae_cmpf",
			"jle_cmpi",
			"jle_cmpf",
			"pushz",
			"ipusho",
			"fpusho",
			"iinc",
			"idec",
			"iadd",
			"isub",
			"imul",
			"idiv",
			"imod",
			"iand",
			"ior",
			"ixor",
			"icom",
			"isal",
			"isar",
			"irol",
			"iror",
			"ineg",
			"fadd",
			"fsub",
			"fmul",
			"fdiv",
			"fmod",
			"fneg",
			"finc",
			"fdec"
		};

		constexpr std::array<const std::string_view, static_cast<std::size_t>(instruction::count_)> descriptions {
			"interrupt reactor execution",
			"call intrinsic system routine",
			"call procedure",
			"return from procedure",
			"copy stack slot to stack record",
			"copy immediate to stack record",
			"push one stack record onto stack",
			"pop one stack record from stack",
			"pop two records from stack",
			"duplicate stack top",
			"duplicate stack top two times",
			"swap the stack top slot with the lower slot",
			"no operation",
			"absolute direct unconditional jump",
			"relative indirect jump unconditional jump",
			"jump if zero",
			"jump if not zero",
			"jump if one - compare as integer",
			"jump if one - compare as float",
			"jump if not one - compare as integer",
			"jump if not one - compare as  integer",
			"jump if equal as integer",
			"jump if equal - compare as floating point",
			"jump if not equal - compare  as integer",
			"jump if not equal - compare  as floating point",
			"jump if above - compare  as integer",
			"jump if above - compare  as floating point",
			"jump if less - compare as floating point",
			"jump if less - compare as floating point",
			"jump if above or equal - compare as integer",
			"jump if above or equal - compare as floating point",
			"jump if less or equal - compare as integer",
			"jump if less or equal - compare as floating point",
			"push zero as integer",
			"push one as  integer",
			"push one as floating point",
			"integer increment",
			"integer decrement",
			"integer addition",
			"integer subtraction",
			"integer multiplication",
			"integer division",
			"integer remainder",
			"integer bitwise and",
			"integer bitwise or",
			"integer bitwise xor",
			"integer bitwise complement",
			"integer bitwise arithmetic left shift",
			"integer bitwise arithmetic right shift",
			"integer bitwise rotation left",
			"integer bitwise right rotation",
			"integer negation",
			"floating point addition",
			"floating point subtraction",
			"floating point multiplication",
			"floating point division",
			"floating point remainder",
			"floating point negation",
			"floating point increment",
			"floating point decrement"
		};

		constexpr std::array<instruction_type, static_cast<std::size_t>(instruction::count_)> types {
			instruction_type::control,
			instruction_type::control,
			instruction_type::control,
			instruction_type::control,
			instruction_type::memory,
			instruction_type::memory,
			instruction_type::memory,
			instruction_type::memory,
			instruction_type::memory,
			instruction_type::memory,
			instruction_type::memory,
			instruction_type::memory,
			instruction_type::memory,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::branching,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::bitwise,
			instruction_type::bitwise,
			instruction_type::bitwise,
			instruction_type::bitwise,
			instruction_type::bitwise,
			instruction_type::bitwise,
			instruction_type::bitwise,
			instruction_type::bitwise,
			instruction_type::bitwise,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic,
			instruction_type::arithmetic
		};

		constexpr std::array<std::uint8_t, static_cast<std::size_t>(instruction::count_)> push_count {
			0,
			0,
			0,
			0,
			0,
			0,
			1,
			0,
			0,
			1,
			2,
			2,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1,
			1
		};

		constexpr std::array<std::uint8_t, static_cast<std::size_t>(instruction::count_)> pop_count {
			0,
			0,
			0,
			1,
			0,
			0,
			0,
			1,
			2,
			0,
			0,
			2,
			0,
			0,
			0,
			1,
			1,
			1,
			1,
			1,
			1,
			2,
			2,
			2,
			2,
			2,
			2,
			2,
			2,
			2,
			2,
			2,
			2,
			0,
			0,
			1,
			1,
			1,
			2,
			2,
			2,
			2,
			2,
			2,
			2,
			2,
			1,
			2,
			2,
			2,
			2,
			1,
			2,
			2,
			2,
			2,
			2,
			1,
			1,
			1
		};
	}
	
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

	constexpr csignal::csignal(const record64 x_) noexcept : r64 {x_} {}
	constexpr csignal::csignal(const instruction x_) noexcept : instr {x_} {}
	constexpr csignal::csignal(void* const x_) noexcept : ptr {x_} {}
	constexpr csignal::csignal(const i64 x_) noexcept : r64 {x_} {}
	constexpr csignal::csignal(const u64 x_) noexcept : r64 {x_} {}
	constexpr csignal::csignal(const f64 x_) noexcept : r64 {x_} {}
	constexpr csignal::csignal(const c32 x_) noexcept : r64 {x_} {}

	constexpr auto operator""_sig_u(const unsigned long long int x_) noexcept -> csignal {
		return csignal {static_cast<u64>(x_)};
	}

	constexpr auto operator""_sig_i(const unsigned long long int x_) noexcept -> csignal {
		return csignal {static_cast<i64>(x_)};
	}

	constexpr auto operator""_sig_f(const long double x_) noexcept -> csignal {
		return csignal {static_cast<f64>(x_)};
	}

	static_assert(std::is_same_v<std::underlying_type_t<instruction>, std::uint64_t>);
	static_assert(sizeof(instruction) == alignof(u64));
	static_assert(alignof(instruction) == alignof(u64));
	static_assert(sizeof(csignal) == alignof(u64));
	static_assert(alignof(csignal) == alignof(u64));
	static_assert(std::is_standard_layout_v<csignal>);
}
