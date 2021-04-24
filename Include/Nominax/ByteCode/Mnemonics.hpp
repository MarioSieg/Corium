#pragma once

#include <array>
#include <string_view>

#include "Instruction.hpp"

namespace Nominax
{
	/// <summary>
	/// Contains all instruction mnemonics.
	/// </summary>
	constexpr std::array<const std::string_view, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_MNEMONICS
	{
		"int",
		"intrin",
		"cintrin",
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
		"fdec",
		"vpush",
		"vpop",
		"vadd",
		"vsub",
		"vmul",
		"vdiv"
	};
}