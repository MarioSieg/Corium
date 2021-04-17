#pragma once

#include <type_traits>

namespace Nominax {
	/// <summary>
	/// 32-bit memory record.
	/// Contains either: U32, I32, F32, C32
	/// </summary>
	union alignas(alignof(std::int32_t)) Record32 {
		std::int32_t I32;
		std::uint32_t U32;
		float F32;
		char32_t C32;

		constexpr Record32() noexcept;
		explicit constexpr Record32(std::int32_t value) noexcept;
		explicit constexpr Record32(std::uint32_t value) noexcept;
		explicit constexpr Record32(float value) noexcept;
		explicit constexpr Record32(char32_t value) noexcept;
		explicit constexpr operator bool() const noexcept;
		constexpr auto operator ==(Record32 other) const noexcept -> bool;
		constexpr auto operator !=(Record32 other) const noexcept -> bool;
		constexpr bool operator <(Record32 other) const noexcept;
		constexpr bool operator >(Record32 other) const noexcept;
		constexpr auto operator <=(Record32 other) const noexcept -> bool;
		constexpr auto operator >=(Record32 other) const noexcept -> bool;
	};

    constexpr Record32::Record32() noexcept : U32{0} {}
    constexpr Record32::Record32(const std::int32_t value) noexcept : I32{value} {}
    constexpr Record32::Record32(const std::uint32_t value) noexcept : U32{value} {}
    constexpr Record32::Record32(const float value) noexcept : F32{value} {}
    constexpr Record32::Record32(const char32_t value) noexcept : C32{value} {}

	constexpr auto operator""_rec32_u(const unsigned long long int value) noexcept -> Record32 {
		return Record32{static_cast<std::uint32_t>(value)};
	}
	
	constexpr auto operator""_rec32_i(const unsigned long long int value) noexcept -> Record32 {
		return Record32{static_cast<std::int32_t>(value)};
	}

	constexpr auto operator""_rec32_f(const long double value) noexcept -> Record32 {
		return Record32{static_cast<float>(value)};
	}

	constexpr Record32::operator bool() const noexcept {
		return this->U32;
	}

	constexpr auto Record32::operator ==(const Record32 other) const noexcept -> bool {
		return this->U32 == other.U32;
	}

	constexpr auto Record32::operator !=(const Record32 other) const noexcept -> bool {
		return !(*this == other);
	}

	constexpr auto Record32::operator <(const Record32 other) const noexcept -> bool {
		return this->U32 < other.U32;
	}

	constexpr auto Record32::operator >(const Record32 other) const noexcept -> bool {
		return this->U32 > other.U32;
	}

	constexpr auto Record32::operator <=(const Record32 other) const noexcept -> bool {
		return this->U32 <= other.U32;
	}

	constexpr auto Record32::operator >=(const Record32 other) const noexcept -> bool {
		return this->U32 >= other.U32;
	}

	static_assert(sizeof(Record32) == sizeof(std::int32_t));
	static_assert(alignof(Record32) == alignof(std::int32_t));
	static_assert(std::is_standard_layout_v<Record32>);
	static_assert(std::is_default_constructible_v<Record32>);

	/// <summary>
	/// 64-bit memory record.
	/// Contains either: Record32, void*, U64, I64, F64
	/// </summary>
	union alignas(alignof(std::int64_t)) Record64 {
		Record32 R32;
		void* Ptr;
		std::uint64_t U64;
		std::int64_t I64;
		double F64;
		char32_t C32;

		constexpr Record64() noexcept;
		explicit constexpr Record64(Record32 value) noexcept;
		explicit constexpr Record64(void* value) noexcept;
		explicit constexpr Record64(std::int64_t value) noexcept;
		explicit constexpr Record64(std::uint64_t value) noexcept;
		explicit constexpr Record64(double value) noexcept;
		explicit constexpr Record64(char32_t value) noexcept;
		explicit constexpr operator bool() const noexcept;
		constexpr auto operator ==(Record64 other) const noexcept -> bool;
		constexpr auto operator !=(Record64 other) const noexcept -> bool;
		constexpr auto operator <(Record64 other) const noexcept -> bool;
		constexpr auto operator >(Record64 other) const noexcept -> bool;
		constexpr auto operator <=(Record64 other) const noexcept -> bool;
		constexpr auto operator >=(Record64 other) const noexcept -> bool;
		static constexpr auto Padding() noexcept -> Record64;
	};

    constexpr Record64::Record64() noexcept : U64{0} {}
    constexpr Record64::Record64(const Record32 value) noexcept : R32{value} {}
    constexpr Record64::Record64(void* const value) noexcept : Ptr{value} {}
    constexpr Record64::Record64(const std::int64_t value) noexcept : I64{value} {}
    constexpr Record64::Record64(const std::uint64_t value) noexcept : U64{value} {}
    constexpr Record64::Record64(const double value) noexcept : F64{value} {}
    constexpr Record64::Record64(const char32_t value) noexcept : C32{value} {}

	constexpr auto operator""_rec64_u(const unsigned long long int value) noexcept -> Record64 {
		return Record64{static_cast<std::uint64_t>(value)};
	}

	constexpr auto operator""_rec64_i(const unsigned long long int value) noexcept -> Record64 {
		return Record64{static_cast<std::int64_t>(value)};
	}

	constexpr auto operator""_rec64_f(const long double value) noexcept -> Record64 {
		return Record64{static_cast<double>(value)};
	}

	constexpr Record64::operator bool() const noexcept {
		return this->U64;
	}

	constexpr auto Record64::operator ==(const Record64 other) const noexcept -> bool {
		return this->U64 == other.U64;
	}

	constexpr auto Record64::operator !=(const Record64 other) const noexcept -> bool {
		return !(*this == other);
	}

	constexpr auto Record64::operator <(const Record64 other) const noexcept -> bool {
		return this->U64 < other.U64;
	}

	constexpr auto Record64::operator >(const Record64 other) const noexcept -> bool {
		return this->U64 > other.U64;
	}

	constexpr auto Record64::operator <=(const Record64 other) const noexcept -> bool {
		return this->U64 <= other.U64;
	}

	constexpr auto Record64::operator >=(const Record64 other) const noexcept -> bool {
		return this->U64 >= other.U64;
	}

	constexpr auto Record64::Padding() noexcept -> Record64 {
		return 0xFF'FF'FF'FF'FF'FF'FF'FF_rec64_u;
	}

	static_assert(sizeof(Record64) == sizeof(std::int64_t));
	static_assert(alignof(Record64) == alignof(std::int64_t));
	static_assert(std::is_standard_layout_v<Record64>);
	static_assert(std::is_default_constructible_v<Record64>);
	static_assert(sizeof(Record32) < sizeof(Record64));
}
