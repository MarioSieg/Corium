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

	__attribute__((always_inline)) constexpr record32::record32() noexcept : u{ 0 } {}
	__attribute__((always_inline)) constexpr record32::record32(const i32 x) noexcept : i{ x } {}
	__attribute__((always_inline)) constexpr record32::record32(const u32 x) noexcept : u{ x } {}
	__attribute__((always_inline)) constexpr record32::record32(const f32 x) noexcept : f{ x } {}
	__attribute__((always_inline)) constexpr record32::record32(const c32 x) noexcept : c{ x } {}

	__attribute__((always_inline)) constexpr record32::operator bool() const noexcept {
		return static_cast<bool>(this->u);
	}

	__attribute__((always_inline)) constexpr auto record32::operator ==(const record32 rhs) const noexcept -> bool {
		return this->u == rhs.u;
	}

	__attribute__((always_inline)) constexpr auto record32::operator !=(const record32 rhs) const noexcept -> bool {
		return !(*this == rhs);
	}

	__attribute__((always_inline)) constexpr auto record32::operator <(const record32 rhs) const noexcept -> bool {
		return this->u < rhs.u;
	}

	__attribute__((always_inline)) constexpr auto record32::operator >(const record32 rhs) const noexcept -> bool {
		return this->u > rhs.u;
	}

	__attribute__((always_inline)) constexpr auto record32::operator <=(const record32 rhs) const noexcept -> bool {
		return this->u <= rhs.u;
	}

	__attribute__((always_inline)) constexpr auto record32::operator >=(const record32 rhs) const noexcept -> bool {
		return this->u >= rhs.u;
	}

	static_assert(sizeof(record32) == sizeof(i32));
	static_assert(alignof(record32) == alignof(i32));
	static_assert(std::is_standard_layout_v<record32>);
	static_assert(std::is_default_constructible_v<record32>);

	union alignas(alignof(i64)) record64 {
		record32 rec32;
		void* ptr;
		i64 i;
		u64 u;
		f64 f;
		c32 c;

		constexpr record64() noexcept;
		explicit constexpr record64(record32 x) noexcept;
		explicit constexpr record64(void* x) noexcept;
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
		static constexpr auto nop_padding() noexcept -> record64;
	};

	__attribute__((always_inline)) constexpr record64::record64() noexcept : u{0} {}
	__attribute__((always_inline)) constexpr record64::record64(const record32 x) noexcept : rec32{x} {}
	__attribute__((always_inline)) constexpr record64::record64(void* const x) noexcept : ptr{x} {}
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

	__attribute__((always_inline)) constexpr auto record64::nop_padding() noexcept -> record64 {
		return record64(UINT64_C(0xFF'FF'FF'FF'FF'FF'FF'FF));
	}

	static_assert(sizeof(record64) == sizeof(i64));
	static_assert(alignof(record64) == alignof(i64));
	static_assert(std::is_standard_layout_v<record64>);
	static_assert(std::is_default_constructible_v<record64>);
	static_assert(sizeof(record32) < sizeof(record64));
}
