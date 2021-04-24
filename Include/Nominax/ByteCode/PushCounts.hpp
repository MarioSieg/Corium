#pragma once

#include <array>

#include "Instruction.hpp"

namespace Nominax
{
	/// <summary>
	/// Contains the amount of stack pushes each instruction will perform.
	/// </summary>
	constexpr std::array<std::uint8_t, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_PUSH_COUNTS
	{
		0,
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
		1,
		4,
		0,
		4,
		4,
		4,
		4
	};
}