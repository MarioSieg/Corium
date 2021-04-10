#pragma once

#include <cstdint>
#include <limits>
#include <type_traits>

#include "rttypes.hpp"

namespace nominax {
	union alignas(alignof(i32)) record32 {
		i32 i;
		u32 u;
		f32 f;
		c32 c;

		constexpr record32() noexcept;
		explicit constexpr record32(i32 x) noexcept;
		explicit constexpr record32(u32 x) noexcept;
		explicit constexpr record32(f32 x) noexcept;
		explicit constexpr record32(c32 x) noexcept;
		explicit constexpr operator bool() const noexcept;
		constexpr auto operator ==(record32 rhs) const noexcept -> bool;
		constexpr auto operator !=(record32 rhs) const noexcept -> bool;
		constexpr auto operator <(record32 rhs) const noexcept -> bool;
		constexpr auto operator >(record32 rhs) const noexcept -> bool;
		constexpr auto operator <=(record32 rhs) const noexcept -> bool;
		constexpr auto operator >=(record32 rhs) const noexcept -> bool;
	};

	constexpr record32::record32() noexcept : u{0} {}
	constexpr record32::record32(const i32 x) noexcept : i{x} {}
	constexpr record32::record32(const u32 x) noexcept : u{x} {}
	constexpr record32::record32(const f32 x) noexcept : f{x} {}
	constexpr record32::record32(const c32 x) noexcept : c{x} {}

	constexpr record32::operator bool() const noexcept {
		return static_cast<bool>(this->u);
	}

	constexpr auto record32::operator ==(const record32 rhs) const noexcept -> bool {
		return this->u == rhs.u;
	}

	constexpr auto record32::operator !=(const record32 rhs) const noexcept -> bool {
		return !(*this == rhs);
	}

	constexpr auto record32::operator <(const record32 rhs) const noexcept -> bool {
		return this->u < rhs.u;
	}

	constexpr auto record32::operator >(const record32 rhs) const noexcept -> bool {
		return this->u > rhs.u;
	}

	constexpr auto record32::operator <=(const record32 rhs) const noexcept -> bool {
		return this->u <= rhs.u;
	}

	constexpr auto record32::operator >=(const record32 rhs) const noexcept -> bool {
		return this->u >= rhs.u;
	}

	constexpr record32 rec_nop_padding{0xFF'FF'FF'FF};
	constexpr record32 rec_mask_u8_lo{0x00'00'00'FF};
	constexpr record32 rec_mask_u8_hi{0xFF'00'00'00};
	constexpr record32 rec_mask_u16_lo{0x00'00'FF'FF};
	constexpr record32 rec_mask_u16_hi{0xFF'FF'00'00};
	constexpr record32 rec_mask_u24_lo{0xFF'FF'FF'00};
	constexpr record32 rec_mask_u24_hi{0x00'FF'FF'FF};
	constexpr record32 rec_true{true};
	constexpr record32 rec_false{false};
	constexpr record32 rec_min_i32{std::numeric_limits<i32>::min()};
	constexpr record32 rec_max_i32{std::numeric_limits<i32>::max()};
	constexpr record32 rec_min_u32{std::numeric_limits<u32>::min()};
	constexpr record32 rec_max_u32{std::numeric_limits<u32>::max()};
	constexpr record32 rec_min_f32{std::numeric_limits<f32>::min()};
	constexpr record32 rec_max_f32{std::numeric_limits<f32>::max()};
	constexpr record32 rec_min_c32{std::numeric_limits<c32>::min()};
	constexpr record32 rec_max_c32{std::numeric_limits<c32>::max()};

	static_assert(sizeof(record32) == sizeof(u32));
	static_assert(alignof(record32) == alignof(u32));
	static_assert(std::is_standard_layout_v<record32>);
	static_assert(std::is_default_constructible_v<record32>);

	using interrupt_accumulator = std::int_fast32_t;
	static_assert(std::is_trivial_v<interrupt_accumulator>);

	using interrupt_routine = auto (interrupt_accumulator, volatile std::sig_atomic_t&, void*) noexcept -> bool;
	static_assert(std::is_function_v<interrupt_routine>);

	using intrinsic_routine = auto () noexcept -> bool;
	static_assert(std::is_function_v<intrinsic_routine>);
}
