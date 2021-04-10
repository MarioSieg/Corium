#pragma once

#include <cstdint>

namespace nominax {
	using u32 = std::uint32_t;
	static_assert(sizeof(u32) == 4);

	using i32 = std::int32_t;
	static_assert(sizeof(i32) == 4);

	using f32 = float;
	static_assert(sizeof(f32) == 4);

	using c32 = char32_t;
	static_assert(sizeof(c32) == 4);
}