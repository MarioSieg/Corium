#pragma once

#include <cstddef>

namespace Nominax {
	[[nodiscard]]
	constexpr auto Bytes2Gigabytes(const std::size_t bytes) noexcept -> std::size_t {
		return bytes / 1024 / 1024 / 1024;
	}

	[[nodiscard]]
	constexpr auto Bytes2Megabytes(const std::size_t bytes) noexcept -> std::size_t {
		return bytes / 1024 / 1024;
	}

	[[nodiscard]]
	constexpr auto Bytes2Kilobytes(const std::size_t bytes) noexcept -> std::size_t {
		return bytes / 1024;
	}

	[[nodiscard]]
	constexpr auto Gigabytes2Bytes(const std::size_t gigabytes) noexcept -> std::size_t {
		return gigabytes * 1024 * 1024 * 1024;
	}

	[[nodiscard]]
	constexpr auto Megabytes2Bytes(const std::size_t megabytes) noexcept -> std::size_t {
		return megabytes * 1024 * 1024;
	}

	[[nodiscard]]
	constexpr auto Kilobytes2Bytes(const std::size_t kilobytes) noexcept -> std::size_t {
		return kilobytes * 1024;
	}

	constexpr auto operator ""_kb(const unsigned long long int value) noexcept -> unsigned long long int {
		return value * 1024;
	}

	constexpr auto operator ""_mb(const unsigned long long int value) noexcept -> unsigned long long int {
		return value * 1024 * 1024;
	}

	constexpr auto operator ""_gb(const unsigned long long int value) noexcept -> unsigned long long int {
		return value * 1024 * 1024 * 1024;
	}
}
