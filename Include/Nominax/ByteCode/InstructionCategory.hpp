#pragma once

#include <cstdint>

namespace Nominax
{
	/// <summary>
	/// Instruction category.
	/// </summary>
	enum class InstructionCategory : std::uint8_t
	{
		Control,
		Memory,
		Branching,
		Arithmetic,
		BitWise
	};
}