#pragma once

#include <cstdint>
#include <limits>
#include <type_traits>

#include "rttypes.hpp"

namespace nominax {
	union alignas(alignof(i64)) record64 {
		i64 i;
		u64 u;
		f64 f;
		c32 c;

		constexpr record64() noexcept;
		explicit constexpr record64(i64 x) noexcept;
		explicit constexpr record64(u64 x) noexcept;
		explicit constexpr record64(f64 x) noexcept;
		explicit constexpr record64(c32 x) noexcept;
		explicit constexpr operator bool() const noexcept;
		constexpr auto operator ==(record64 rhs) const noexcept -> bool;
		constexpr auto operator !=(record64 rhs) const noexcept -> bool;
		constexpr auto operator <(record64 rhs) const noexcept -> bool;
		constexpr auto operator >(record64 rhs) const noexcept -> bool;
		constexpr auto operator <=(record64 rhs) const noexcept -> bool;
		constexpr auto operator >=(record64 rhs) const noexcept -> bool;
	};

	__attribute__((always_inline)) constexpr record64::record64() noexcept : u{0} {}
	__attribute__((always_inline)) constexpr record64::record64(const i64 x) noexcept : i{x} {}
	__attribute__((always_inline)) constexpr record64::record64(const u64 x) noexcept : u{x} {}
	__attribute__((always_inline)) constexpr record64::record64(const f64 x) noexcept : f{x} {}
	__attribute__((always_inline)) constexpr record64::record64(const c32 x) noexcept : c{x} {}

	__attribute__((always_inline)) constexpr record64::operator bool() const noexcept {
		return static_cast<bool>(this->u);
	}

	__attribute__((always_inline)) constexpr auto record64::operator ==(const record64 rhs) const noexcept -> bool {
		return this->u == rhs.u;
	}

	__attribute__((always_inline)) constexpr auto record64::operator !=(const record64 rhs) const noexcept -> bool {
		return !(*this == rhs);
	}

	__attribute__((always_inline)) constexpr auto record64::operator <(const record64 rhs) const noexcept -> bool {
		return this->u < rhs.u;
	}

	__attribute__((always_inline)) constexpr auto record64::operator >(const record64 rhs) const noexcept -> bool {
		return this->u > rhs.u;
	}

	__attribute__((always_inline)) constexpr auto record64::operator <=(const record64 rhs) const noexcept -> bool {
		return this->u <= rhs.u;
	}

	__attribute__((always_inline)) constexpr auto record64::operator >=(const record64 rhs) const noexcept -> bool {
		return this->u >= rhs.u;
	}

	constexpr record64 rec_nop_padding{UINT64_C(0xFF'FF'FF'FF'FF'FF'FF'FF)};
	constexpr record64 rec_mask_u8_lo{UINT64_C(0x00'00'00'00'00'00'00'FF)};
	constexpr record64 rec_mask_u8_hi{UINT64_C(0xFF'00'00'00'00'00'00'00)};
	constexpr record64 rec_mask_u16_lo{UINT64_C(0x00'00'00'00'00'00'FF'FF)};
	constexpr record64 rec_mask_u16_hi{UINT64_C(0xFF'FF'00'00'00'00'00'00)};
	constexpr record64 rec_mask_u24_lo{UINT64_C(0x00'00'00'00'00'FF'FF'FF)};
	constexpr record64 rec_mask_u24_hi{UINT64_C(0xFF'FF'FF'00'00'00'00'00)};
	constexpr record64 rec_true{static_cast<u64>(true)};
	constexpr record64 rec_false{static_cast<u64>(false)};
	constexpr record64 rec_min_i32{std::numeric_limits<i64>::min()};
	constexpr record64 rec_max_i32{std::numeric_limits<i64>::max()};
	constexpr record64 rec_min_u32{std::numeric_limits<u64>::min()};
	constexpr record64 rec_max_u32{std::numeric_limits<u64>::max()};
	constexpr record64 rec_min_f32{std::numeric_limits<f64>::min()};
	constexpr record64 rec_max_f32{std::numeric_limits<f64>::max()};
	constexpr record64 rec_min_c32{std::numeric_limits<c32>::min()};
	constexpr record64 rec_max_c32{std::numeric_limits<c32>::max()};

	static_assert(sizeof(record64) == sizeof(u64));
	static_assert(alignof(record64) == alignof(u64));
	static_assert(std::is_standard_layout_v<record64>);
	static_assert(std::is_default_constructible_v<record64>);

	using interrupt_accumulator = std::int_fast32_t;
	static_assert(std::is_trivial_v<interrupt_accumulator>);

	using interrupt_routine = auto (interrupt_accumulator, volatile std::sig_atomic_t&, void*) noexcept -> bool;
	static_assert(std::is_function_v<interrupt_routine>);

	using intrinsic_routine = auto () -> bool;
	static_assert(std::is_function_v<intrinsic_routine>);
}
