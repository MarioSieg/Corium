#pragma once

#include <array>

#include "InstructionCategory.hpp"

namespace Nominax
{
	/// <summary>
	/// Contains the categories of all instructions.
	/// </summary>
	[[maybe_unused]]
	constexpr std::array INSTRUCTION_CATEGORIES
	{
		InstructionCategory::Control,
		InstructionCategory::Control,
		InstructionCategory::Control,
		InstructionCategory::Control,
		InstructionCategory::Control,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
	};
}