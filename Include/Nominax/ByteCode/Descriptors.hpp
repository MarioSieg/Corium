#pragma once

#include <array>
#include <string_view>

#include "Instruction.hpp"

namespace Nominax
{
	/// <summary>
	/// Contains a short descripion for all instructions.
	/// </summary>
	constexpr std::array<const std::string_view, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_DESCRIPTIONS
	{
		"interrupt reactor execution",
		"call intrinsic system routine",
		"call custom intrinsic routine",
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
		"floating point decrement",
		"push quad vector",
		"pop quad vector",
		"floating point quad vector addition",
		"floating point quad vector subtraction",
		"floating point quad vector multiplication",
		"floating point quad vector division",
	};
}