#pragma once

#include <array>

#include "Instruction.hpp"

namespace Nominax
{
	/// <summary>
	/// Contains the count of required immediate arguments for each instruction.
	/// </summary>
	constexpr std::array<std::uint8_t, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS
	{
		1,
		1,
		1,
		1,
		0,
		2,
		2,
		1,
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
		0,
		0,
		0,
		0,
		0,
		0,
		4,
		0,
		0,
		0,
		0,
		0
	};
}