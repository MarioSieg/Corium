#pragma once

#include <cstdint>
#include <type_traits>

namespace nominax {
	using u32 = std::uint32_t;
	static_assert(sizeof(u32) == 4);
	static_assert(std::is_integral_v<u32> && std::is_unsigned_v<u32>);

	using i32 = std::int32_t;
	static_assert(sizeof(i32) == 4);
	static_assert(std::is_integral_v<i32> && std::is_signed_v<i32>);

	using f32 = float;
	static_assert(sizeof(f32) == 4);
	static_assert(std::is_floating_point_v<f32>);

	using u64 = std::uint64_t;
	static_assert(sizeof(u64) == 8);
	static_assert(std::is_integral_v<u64> && std::is_unsigned_v<u64>);

	using i64 = std::int64_t;
	static_assert(sizeof(i64) == 8);
	static_assert(std::is_integral_v<i64> && std::is_signed_v<i64>);

	using f64 = double;
	static_assert(sizeof(f64) == 8);
	static_assert(std::is_floating_point_v<f64>);

	using c32 = char32_t;
	static_assert(sizeof(c32) == 4);

	using intrinsic_routine = auto () -> bool;
	static_assert(std::is_function_v<intrinsic_routine>);
}