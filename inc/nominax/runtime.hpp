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

	using c32 = char32_t;
	static_assert(sizeof(c32) == 4);

	constexpr auto operator""_u32(const unsigned long long int x_) noexcept -> u32 {
		return static_cast<u32>(x_);
	}

	constexpr auto operator""_i32(const unsigned long long int x_) noexcept -> i32 {
		return static_cast<i32>(x_);
	}

	constexpr auto operator""_f32(const long double x_) noexcept -> f32 {
		return static_cast<f32>(x_);
	}

	using u64 = std::uint64_t;
	static_assert(sizeof(u64) == 8);
	static_assert(std::is_integral_v<u64> && std::is_unsigned_v<u64>);

	using i64 = std::int64_t;
	static_assert(sizeof(i64) == 8);
	static_assert(std::is_integral_v<i64> && std::is_signed_v<i64>);

	using f64 = double;
	static_assert(sizeof(f64) == 8);
	static_assert(std::is_floating_point_v<f64>);

	constexpr auto operator""_u64(const unsigned long long int x_) noexcept -> u64 {
		return static_cast<u64>(x_);
	}

	constexpr auto operator""_i64(const unsigned long long int x_) noexcept -> i64 {
		return static_cast<i64>(x_);
	}

	constexpr auto operator""_f64(const long double x_) noexcept -> f64 {
		return static_cast<f32>(x_);
	}
	
}