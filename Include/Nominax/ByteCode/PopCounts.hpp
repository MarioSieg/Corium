#pragma once

#include <array>

#include "Instruction.hpp"

namespace Nominax
{
	/// <summary>
	/// Contains the amount of stack pops each instruction will perform.
	/// </summary>
	constexpr std::array<std::uint8_t, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_POP_COUNTS
	{
		0,
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
		1,
		0,
		4,
		8,
		8,
		8,
		8
	};
}