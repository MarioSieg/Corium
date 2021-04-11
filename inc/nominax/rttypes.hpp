#pragma once

#include <cstdint>
#include <type_traits>

namespace nominax {

	using u32 = std::uint32_t;
	static_assert(sizeof(u32) == 4);

	using i32 = std::int32_t;
	static_assert(sizeof(i32) == 4);

	using f32 = float;
	static_assert(sizeof(f32) == 4);

	using u64 = std::uint64_t;
	static_assert(sizeof(u64) == 8);

	using i64 = std::int64_t;
	static_assert(sizeof(i64) == 8);

	using f64 = double;
	static_assert(sizeof(f64) == 8);

	using c32 = char32_t;
	static_assert(sizeof(c32) == 4);

	using interrupt_accumulator = std::int_fast32_t;
	static_assert(std::is_trivial_v<interrupt_accumulator>);

	using interrupt_routine = auto (interrupt_accumulator, volatile std::sig_atomic_t&, void*) noexcept -> bool;
	static_assert(std::is_function_v<interrupt_routine>);

	using intrinsic_routine = auto () -> bool;
	static_assert(std::is_function_v<intrinsic_routine>);
}