#pragma once

#include <climits>
#include <cstdint>

namespace Nominax
{
	inline auto ILog2(std::uint64_t x) noexcept(true) -> std::uint64_t
	{
		--x;
		return sizeof x * CHAR_BIT - __builtin_clzll(x);
	}
}