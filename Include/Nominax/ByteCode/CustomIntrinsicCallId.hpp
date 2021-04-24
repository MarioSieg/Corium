#pragma once

#include <cstdint>

namespace Nominax 
{
	/// <summary>
	/// Call id for custom intrinsic routine.
	/// </summary>
	enum class alignas(alignof(std::uint64_t)) CustomIntrinsicCallId : std::uint64_t;
}