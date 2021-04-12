#pragma once

#include <cstddef>

namespace nominax {
	[[nodiscard]]
	constexpr auto b2gb(const std::size_t bytes_) noexcept -> std::size_t {
		return bytes_ / 1024 / 1024 / 1024;
	}

	[[nodiscard]]
	constexpr auto b2mb(const std::size_t bytes_) noexcept -> std::size_t {
		return bytes_ / 1024 / 1024;
	}

	[[nodiscard]]
	constexpr auto b2kb(const std::size_t bytes_) noexcept -> std::size_t {
		return bytes_ / 1024;
	}

	[[nodiscard]]
	constexpr auto gb2b(const std::size_t bytes_) noexcept -> std::size_t {
		return bytes_ * 1024 * 1024 * 1024;
	}

	[[nodiscard]]
	constexpr auto mb2b(const std::size_t bytes_) noexcept -> std::size_t {
		return bytes_ * 1024 * 1024;
	}

	[[nodiscard]]
	constexpr auto kb2b(const std::size_t bytes_) noexcept -> std::size_t {
		return bytes_ * 1024;
	}

	constexpr auto operator ""_kb(const unsigned long long int x) noexcept -> unsigned long long int {
		return x * 1024;
	}

	constexpr auto operator ""_mb(const unsigned long long int x) noexcept -> unsigned long long int {
		return x * 1024 * 1024;
	}

	constexpr auto operator ""_gb(const unsigned long long int x) noexcept -> unsigned long long int {
		return x * 1024 * 1024 * 1024;
	}
}
