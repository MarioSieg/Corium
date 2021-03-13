// Nominax Runtime System
// Copyright (c) 2021 Mario Sieg <mt3000@gmx.de>, Germany
// See README.md and LICENSE!

#pragma once

#include <array>
#include <cstdint>

namespace Nominax {
	using u32 = std::uint32_t;
	using i32 = std::int32_t;
	using f32 = float;
	using c32 = char32_t;

	union alignas(alignof(u32)) Record {
		u32 u;
		i32 i;
		f32 f;
		c32 c;
		std::array<uint8_t, sizeof(u32)> bytes;

		constexpr explicit Record(u32 x) noexcept;
		constexpr explicit Record(i32 x) noexcept;
		constexpr explicit Record(f32 x) noexcept;
		constexpr explicit Record(c32 x) noexcept;
		constexpr explicit operator u32() const noexcept;
		constexpr explicit operator i32() const noexcept;
		constexpr explicit operator f32() const noexcept;
		constexpr explicit operator c32() const noexcept;
	};

	constexpr Record::Record(const u32 x) noexcept : u(x) {}
	constexpr Record::Record(const i32 x) noexcept : i(x) {}
	constexpr Record::Record(const f32 x) noexcept : f(x) {}
	constexpr Record::Record(const c32 x) noexcept : c(x) {}
	constexpr Record::operator u32() const noexcept { return this->u; }
	constexpr Record::operator i32() const noexcept { return this->i; }
	constexpr Record::operator f32() const noexcept { return this->f; }
	constexpr Record::operator c32() const noexcept { return this->c; }
}
