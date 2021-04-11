#pragma once

#include <cstdint>

namespace nominax {
	using u64 = std::uint64_t;
	static_assert(sizeof(u64) == 8);

	using i64 = std::int64_t;
	static_assert(sizeof(i64) == 8);

	using f64 = double;
	static_assert(sizeof(f64) == 8);

	using c32 = char32_t;
	static_assert(sizeof(c32) == 4);
}