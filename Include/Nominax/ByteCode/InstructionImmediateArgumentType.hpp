#pragma once

#include <cstdint>

namespace Nominax 
{
	/// <summary>
	/// All types of immediate arguments a instruction could have.
	/// </summary>
	enum class InstructionImmediateArgumentType : std::uint8_t
	{
		None,
		I64,
		F64,
		U64,
		I64OrU64,
		I64OrU64OrF64,
		RelativeJumpAddress64,
		AbsoluteJumpAddress64,
		SystemIntrinsicId,
		CustomIntrinsicId
	};
}