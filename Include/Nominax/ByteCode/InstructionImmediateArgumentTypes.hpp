#pragma once

#include <array>

#include "InstructionImmediateArgumentType.hpp"

namespace Nominax
{
	/// <summary>
	/// Defines the maximal amount of immediate arguments.
	/// </summary>
	constexpr std::size_t INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS{ 4 };

	/// <summary>
	/// Contains all immediate argument types for each instruction.
	/// </summary>
	[[maybe_unused]]
	constexpr std::array INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES
	{
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::I64OrU64OrF64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::SystemIntrinsicId
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::CustomIntrinsicId
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::RelativeJumpAddress64, InstructionImmediateArgumentType::RelativeJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::RelativeJumpAddress64, InstructionImmediateArgumentType::I64OrU64OrF64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::I64OrU64OrF64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::RelativeJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS>
		{
			InstructionImmediateArgumentType::F64,
			InstructionImmediateArgumentType::F64,
			InstructionImmediateArgumentType::F64,
			InstructionImmediateArgumentType::F64,
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
	};
}