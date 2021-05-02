#pragma once

#include "../Common/RtTypes.hpp"

namespace Nominax
{
	/// <summary>
	/// 8 bit unsigned integer.
	/// Use for assembly interfaces only.
	/// </summary>
	// ReSharper disable once CppInconsistentNaming
	using BYTE = U8;

	/// <summary>
	/// 16 bit unsigned integer.
	/// Use for assembly interfaces only.
	/// </summary>
	// ReSharper disable once CppInconsistentNaming
	using WORD = U16;

	/// <summary>
	/// 32 bit unsigned integer.
	/// Use for assembly interfaces only.
	/// </summary>
	// ReSharper disable once CppInconsistentNaming
	using DOUBLEWORD = U32;
	
	/// <summary>
	/// 64 bit unsigned integer.
	/// Use for assembly interfaces only.
	/// </summary>
	// ReSharper disable once CppInconsistentNaming
	using QUADWORD = U64;
}