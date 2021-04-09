#pragma once

#include "record.hpp"

namespace nominax {
	enum class instruction: std::uint32_t {
		inter		= 0x00'00'00'00,
		intrin		= 0x00'00'00'01,
		call		= 0x00'00'00'02,
		ret			= 0x00'00'00'03,
		mov			= 0x00'00'00'04,
		sto			= 0x00'00'00'05,
		push		= 0x00'00'00'06,
		pop			= 0x00'00'00'07,
		pop2		= 0x00'00'00'08,
		dupl		= 0x00'00'00'09,
		dupl2		= 0x00'00'00'0A,
		nop			= 0x00'00'00'0B,
		pushz		= 0x00'00'00'0C,
		pusho		= 0x00'00'00'0D,
		iinc		= 0x00'00'00'0E,
		idec		= 0x00'00'00'0F,
		iadd		= 0x00'00'00'10,
		isub		= 0x00'00'00'11,
		imul		= 0x00'00'00'12,
		idiv		= 0x00'00'00'13,
		imod		= 0x00'00'00'14,
		iand		= 0x00'00'00'15,
		ior			= 0x00'00'00'16,
		ixor		= 0x00'00'00'17,
		icom		= 0x00'00'00'18,
		isal		= 0x00'00'00'19,
		isar		= 0x00'00'00'1A,
		irol		= 0x00'00'00'1B,
		iror		= 0x00'00'00'1C,
		ineg		= 0x00'00'00'1D,
		fadd		= 0x00'00'00'1E,
		fsub		= 0x00'00'00'1F,
		fmul		= 0x00'00'00'20,
		fdiv		= 0x00'00'00'21,
		fmod		= 0x00'00'00'22,
		fneg		= 0x00'00'00'23,
		
		count
	};

	union alignas(alignof(std::underlying_type_t<instruction>)) signal32 {
		record32 r32;
		instruction instr;
		std::underlying_type_t<instruction> op;

		explicit constexpr signal32(record32 x) noexcept;
		explicit constexpr signal32(instruction x) noexcept;
		explicit constexpr signal32(i32 x) noexcept;
		explicit constexpr signal32(u32 x) noexcept;
		explicit constexpr signal32(f32 x) noexcept;
		explicit constexpr signal32(c32 x) noexcept;
	};

	constexpr signal32::signal32(const record32 x) noexcept : r32{x} {}
	constexpr signal32::signal32(const instruction x) noexcept : instr{x} {}
	constexpr signal32::signal32(const i32 x) noexcept : r32{x} {}
	constexpr signal32::signal32(const u32 x) noexcept : r32{x} {}
	constexpr signal32::signal32(const f32 x) noexcept : r32{x} {}
	constexpr signal32::signal32(const c32 x) noexcept : r32{x} {}

	static_assert(std::is_same_v<std::underlying_type_t<instruction>, std::uint32_t>);
	static_assert(sizeof(instruction) == alignof(u32));
	static_assert(alignof(instruction) == alignof(u32));
	static_assert(sizeof(signal32) == alignof(u32));
	static_assert(alignof(signal32) == alignof(u32));
	static_assert(std::is_standard_layout_v<signal32>);
}
