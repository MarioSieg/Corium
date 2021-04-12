#pragma once

#include <type_traits>

#include "runtime.hpp"

namespace nominax {
	/* 32-bit memory record. Contains either: u32, i32, f32, c32 */
	union alignas(alignof(i32)) record32 {
		i32 i;
		u32 u;
		f32 f;
		c32 c;

		constexpr record32() noexcept;
		explicit constexpr record32(i32 x_) noexcept;
		explicit constexpr record32(u32 x_) noexcept;
		explicit constexpr record32(f32 x_) noexcept;
		explicit constexpr record32(c32 x_) noexcept;
		explicit constexpr operator bool() const noexcept;
		constexpr auto operator ==(record32 rhs_) const noexcept -> bool;
		constexpr auto operator !=(record32 rhs_) const noexcept -> bool;
		constexpr auto operator <(record32 rhs_) const noexcept -> bool;
		constexpr auto operator >(record32 rhs_) const noexcept -> bool;
		constexpr auto operator <=(record32 rhs_) const noexcept -> bool;
		constexpr auto operator >=(record32 rhs_) const noexcept -> bool;
	};

	__attribute__((always_inline)) constexpr record32::record32() noexcept : u{0} {}
	__attribute__((always_inline)) constexpr record32::record32(const i32 x_) noexcept : i{x_} {}
	__attribute__((always_inline)) constexpr record32::record32(const u32 x_) noexcept : u{x_} {}
	__attribute__((always_inline)) constexpr record32::record32(const f32 x_) noexcept : f{x_} {}
	__attribute__((always_inline)) constexpr record32::record32(const c32 x_) noexcept : c{x_} {}

	constexpr auto operator""_rec32_u(const unsigned long long int x_) noexcept -> record32 {
		return record32{static_cast<u32>(x_)};
	}
	
	constexpr auto operator""_rec32_i(const unsigned long long int x_) noexcept -> record32 {
		return record32{static_cast<i32>(x_)};
	}

	constexpr auto operator""_rec32_f(const long double x_) noexcept -> record32 {
		return record32{static_cast<f32>(x_)};
	}

	__attribute__((always_inline)) constexpr record32::operator bool() const noexcept {
		return static_cast<bool>(this->u);
	}

	__attribute__((always_inline)) constexpr auto record32::operator ==(const record32 rhs_) const noexcept -> bool {
		return this->u == rhs_.u;
	}

	__attribute__((always_inline)) constexpr auto record32::operator !=(const record32 rhs_) const noexcept -> bool {
		return !(*this == rhs_);
	}

	__attribute__((always_inline)) constexpr auto record32::operator <(const record32 rhs_) const noexcept -> bool {
		return this->u < rhs_.u;
	}

	__attribute__((always_inline)) constexpr auto record32::operator >(const record32 rhs_) const noexcept -> bool {
		return this->u > rhs_.u;
	}

	__attribute__((always_inline)) constexpr auto record32::operator <=(const record32 rhs_) const noexcept -> bool {
		return this->u <= rhs_.u;
	}

	__attribute__((always_inline)) constexpr auto record32::operator >=(const record32 rhs_) const noexcept -> bool {
		return this->u >= rhs_.u;
	}

	static_assert(sizeof(record32) == sizeof(i32));
	static_assert(alignof(record32) == alignof(i32));
	static_assert(std::is_standard_layout_v<record32>);
	static_assert(std::is_default_constructible_v<record32>);

	/* 64-bit memory record. Contains either: record32, void* (be careful), u64, i64, f64 */
	union alignas(alignof(i64)) record64 {
		record32 r32;
		void* ptr;
		u64 u;
		i64 i;
		f64 f;
		c32 c;

		constexpr record64() noexcept;
		explicit constexpr record64(record32 x_) noexcept;
		explicit constexpr record64(void* x_) noexcept;
		explicit constexpr record64(i64 x_) noexcept;
		explicit constexpr record64(u64 x_) noexcept;
		explicit constexpr record64(f64 x_) noexcept;
		explicit constexpr record64(c32 x_) noexcept;
		explicit constexpr operator bool() const noexcept;
		constexpr auto operator ==(record64 rhs_) const noexcept -> bool;
		constexpr auto operator !=(record64 rhs_) const noexcept -> bool;
		constexpr auto operator <(record64 rhs_) const noexcept -> bool;
		constexpr auto operator >(record64 rhs_) const noexcept -> bool;
		constexpr auto operator <=(record64 rhs_) const noexcept -> bool;
		constexpr auto operator >=(record64 rhs_) const noexcept -> bool;
		static constexpr auto nop_padding() noexcept -> record64;
	};

	__attribute__((always_inline)) constexpr record64::record64() noexcept : u{0} {}
	__attribute__((always_inline)) constexpr record64::record64(const record32 x_) noexcept : r32{x_} {}
	__attribute__((always_inline)) constexpr record64::record64(void* const x_) noexcept : ptr{x_} {}
	__attribute__((always_inline)) constexpr record64::record64(const i64 x_) noexcept : i{x_} {}
	__attribute__((always_inline)) constexpr record64::record64(const u64 x_) noexcept : u{x_} {}
	__attribute__((always_inline)) constexpr record64::record64(const f64 x_) noexcept : f{x_} {}
	__attribute__((always_inline)) constexpr record64::record64(const c32 x_) noexcept : c{x_} {}

	constexpr auto operator""_rec64_u(const unsigned long long int x_) noexcept -> record64 {
		return record64{static_cast<u64>(x_)};
	}

	constexpr auto operator""_rec64_i(const unsigned long long int x_) noexcept -> record64 {
		return record64{static_cast<i64>(x_)};
	}

	constexpr auto operator""_rec64_f(const long double x_) noexcept -> record64 {
		return record64{static_cast<f64>(x_)};
	}

	__attribute__((always_inline)) constexpr record64::operator bool() const noexcept {
		return static_cast<bool>(this->u);
	}

	__attribute__((always_inline)) constexpr auto record64::operator ==(const record64 rhs_) const noexcept -> bool {
		return this->u == rhs_.u;
	}

	__attribute__((always_inline)) constexpr auto record64::operator !=(const record64 rhs_) const noexcept -> bool {
		return !(*this == rhs_);
	}

	__attribute__((always_inline)) constexpr auto record64::operator <(const record64 rhs_) const noexcept -> bool {
		return this->u < rhs_.u;
	}

	__attribute__((always_inline)) constexpr auto record64::operator >(const record64 rhs_) const noexcept -> bool {
		return this->u > rhs_.u;
	}

	__attribute__((always_inline)) constexpr auto record64::operator <=(const record64 rhs_) const noexcept -> bool {
		return this->u <= rhs_.u;
	}

	__attribute__((always_inline)) constexpr auto record64::operator >=(const record64 rhs_) const noexcept -> bool {
		return this->u >= rhs_.u;
	}

	__attribute__((always_inline)) constexpr auto record64::nop_padding() noexcept -> record64 {
		return 0xFF'FF'FF'FF'FF'FF'FF'FF_rec64_u;
	}

	static_assert(sizeof(record64) == sizeof(i64));
	static_assert(alignof(record64) == alignof(i64));
	static_assert(std::is_standard_layout_v<record64>);
	static_assert(std::is_default_constructible_v<record64>);
	static_assert(sizeof(record32) < sizeof(record64));
}
