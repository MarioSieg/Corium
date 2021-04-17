#pragma once

#include <array>
#include <optional>
#include <variant>

#include "idb.hpp"
#include "record.hpp"
#include "sysintrin.hpp"

namespace nominax {
	struct cintrinsic final {
		std::uint64_t id;

		constexpr auto operator ==(cintrinsic rhs_) const noexcept -> bool;
		constexpr auto operator !=(cintrinsic rhs_) const noexcept -> bool;
		constexpr auto operator <(cintrinsic rhs_) const noexcept -> bool;
		constexpr auto operator >(cintrinsic rhs_) const noexcept -> bool;
		constexpr auto operator <=(cintrinsic rhs_) const noexcept -> bool;
		constexpr auto operator >=(cintrinsic rhs_) const noexcept -> bool;
	};

	constexpr auto cintrinsic::operator ==(const cintrinsic rhs_) const noexcept -> bool {
		return this->id == rhs_.id;
	}

	constexpr auto cintrinsic::operator !=(const cintrinsic rhs_) const noexcept -> bool {
		return this->id != rhs_.id;
	}

	constexpr auto cintrinsic::operator <(const cintrinsic rhs_) const noexcept -> bool {
		return this->id < rhs_.id;
	}

	constexpr auto cintrinsic::operator >(const cintrinsic rhs_) const noexcept -> bool {
		return this->id > rhs_.id;
	}

	constexpr auto cintrinsic::operator <=(const cintrinsic rhs_) const noexcept -> bool {
		return this->id <= rhs_.id;
	}

	constexpr auto cintrinsic::operator >=(const cintrinsic rhs_) const noexcept -> bool {
		return this->id >= rhs_.id;
	}
	
	/* 64-bit byte code signal data contains either an instruction or an immediate value. */
	union alignas(alignof(std::uint64_t)) rt_signal {
		record64 r64;
		instruction instr;
		intrinsic intrin;
		cintrinsic cintrin;
		std::uint64_t op;
		void* ptr;

		explicit constexpr rt_signal(record64 x_) noexcept;
		explicit constexpr rt_signal(instruction x_) noexcept;
		explicit constexpr rt_signal(intrinsic x_) noexcept;
		explicit constexpr rt_signal(void* x_) noexcept;
		explicit constexpr rt_signal(i64 x_) noexcept;
		explicit constexpr rt_signal(u64 x_) noexcept;
		explicit constexpr rt_signal(f64 x_) noexcept;
		explicit constexpr rt_signal(c32 x_) noexcept;
	};

	constexpr rt_signal::rt_signal(const record64 x_) noexcept : r64 {x_} {}
	constexpr rt_signal::rt_signal(const instruction x_) noexcept : instr {x_} {}
	constexpr rt_signal::rt_signal(const intrinsic x_) noexcept : intrin{x_} {}
	constexpr rt_signal::rt_signal(void* const x_) noexcept : ptr {x_} {}
	constexpr rt_signal::rt_signal(const i64 x_) noexcept : r64 {x_} {}
	constexpr rt_signal::rt_signal(const u64 x_) noexcept : r64 {x_} {}
	constexpr rt_signal::rt_signal(const f64 x_) noexcept : r64 {x_} {}
	constexpr rt_signal::rt_signal(const c32 x_) noexcept : r64 {x_} {}

	constexpr auto operator""_sig_u(const unsigned long long int x_) noexcept -> rt_signal {
		return rt_signal {static_cast<u64>(x_)};
	}

	constexpr auto operator""_sig_i(const unsigned long long int x_) noexcept -> rt_signal {
		return rt_signal {static_cast<i64>(x_)};
	}

	constexpr auto operator""_sig_f(const long double x_) noexcept -> rt_signal {
		return rt_signal {static_cast<f64>(x_)};
	}

	static_assert(std::is_same_v<std::underlying_type_t<instruction>, std::uint64_t>);
	static_assert(sizeof(instruction) == sizeof(u64));
	static_assert(sizeof(rt_signal) == sizeof(u64));
	static_assert(std::is_standard_layout_v<rt_signal>);

	using intrinsic_routine = auto (record64*) -> bool;
	static_assert(std::is_function_v<intrinsic_routine>);

	/* std::visit auto overload helper */
	template <typename... Ts> struct overloaded : Ts... {
		using Ts::operator()...;
	};
	
	template <typename... Ts> overloaded(Ts&&...) -> overloaded<Ts...>;

	template <typename T>
	concept is_bytecode_element = 
		std::is_same_v<T, instruction>
		|| std::is_same_v<T, intrinsic>
		|| std::is_same_v<T, cintrinsic>
		|| std::is_same_v<T, u64>
		|| std::is_same_v<T, i64>
		|| std::is_same_v<T, f64>
		|| std::is_same_v<T, c32>;

	/* Represents an entry in a bytecode steam. This get's converted to a csignal for execution. */
	struct dy_signal final {
		using data_union = std::variant<instruction, intrinsic, cintrinsic, u64, i64, f64, c32>;

		explicit constexpr dy_signal(data_union&& data_) noexcept;
		explicit constexpr dy_signal(instruction data_) noexcept;
		explicit constexpr dy_signal(u64 data_) noexcept;
		explicit constexpr dy_signal(i64 data_) noexcept;
		explicit constexpr dy_signal(f64 data_) noexcept;
		explicit constexpr dy_signal(c32 data_) noexcept;
		explicit constexpr dy_signal(intrinsic data_) noexcept;
		explicit constexpr dy_signal(cintrinsic data_) noexcept;
		constexpr dy_signal(const dy_signal&) noexcept = default;
		constexpr dy_signal(dy_signal&&) noexcept = default;
		constexpr auto operator =(const dy_signal&) noexcept -> dy_signal& = default;
		constexpr auto operator =(dy_signal&&) noexcept -> dy_signal& = default;
		~dy_signal() = default;

		[[nodiscard]]
		explicit constexpr operator rt_signal() const;

		template <typename T> requires is_bytecode_element<T>
		[[nodiscard]]
		constexpr auto unwrap() const -> std::optional<T>;

		template <typename T> requires is_bytecode_element<T>
		[[nodiscard]]
		constexpr auto contains() const noexcept -> bool;

		template <typename T> requires is_bytecode_element<T>
		[[nodiscard]]
		constexpr auto contains(T&& cmp_) const -> bool;
		
		data_union data;
	};

	constexpr dy_signal::dy_signal(data_union&& data_) noexcept : data{data_} {}
	constexpr dy_signal::dy_signal(const instruction data_) noexcept : data{data_} {}
	constexpr dy_signal::dy_signal(const u64 data_) noexcept : data{data_} {}
	constexpr dy_signal::dy_signal(const i64 data_) noexcept : data{data_} {}
	constexpr dy_signal::dy_signal(const f64 data_) noexcept : data{data_} {}
	constexpr dy_signal::dy_signal(const c32 data_) noexcept : data{data_} {}
	constexpr dy_signal::dy_signal(const intrinsic data_) noexcept : data{data_} {}
	constexpr dy_signal::dy_signal(const cintrinsic data_) noexcept : data{data_} {}

	template <typename T> requires is_bytecode_element<T>
	constexpr auto dy_signal::unwrap() const -> std::optional<T> {
		return std::holds_alternative<T>(this->data) ? std::optional<T>{std::get<T>(this->data)} : std::nullopt;
	}

	template <typename T> requires is_bytecode_element<T>
	constexpr auto dy_signal::contains() const noexcept -> bool {
		return std::holds_alternative<T>(this->data);
	}

	template <typename T> requires is_bytecode_element<T>
	constexpr auto dy_signal::contains(T&& cmp_) const -> bool {
		return std::holds_alternative<T>(this->data) && std::get<T>(this->data) == cmp_;
	}

	constexpr dy_signal::operator rt_signal() const {
		return std::visit(overloaded {
			[](const instruction x_) noexcept {
				return rt_signal{x_};
			},
			[](const intrinsic x_) noexcept {
				return rt_signal{x_};
			},
			[](const cintrinsic x_) noexcept {
				return rt_signal{x_.id};
			},
			[](const u64 x_) noexcept {
				return rt_signal{x_};
			},
			[](const i64 x_) noexcept {
				return rt_signal{x_};
			},
			[](const f64 x_) noexcept {
				return rt_signal{x_};
			},
			[](const c32 x_) noexcept {
				return rt_signal{x_};
			},
		}, this->data);
	}
}
