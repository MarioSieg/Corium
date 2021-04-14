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
	union alignas(alignof(std::uint64_t)) csignal {
		record64 r64;
		instruction instr;
		intrinsic intrin;
		cintrinsic cintrin;
		std::uint64_t op;
		void* ptr;

		explicit constexpr csignal(record64 x_) noexcept;
		explicit constexpr csignal(instruction x_) noexcept;
		explicit constexpr csignal(intrinsic x_) noexcept;
		explicit constexpr csignal(void* x_) noexcept;
		explicit constexpr csignal(i64 x_) noexcept;
		explicit constexpr csignal(u64 x_) noexcept;
		explicit constexpr csignal(f64 x_) noexcept;
		explicit constexpr csignal(c32 x_) noexcept;
	};

	constexpr csignal::csignal(const record64 x_) noexcept : r64 {x_} {}
	constexpr csignal::csignal(const instruction x_) noexcept : instr {x_} {}
	constexpr csignal::csignal(const intrinsic x_) noexcept : intrin{x_} {}
	constexpr csignal::csignal(void* const x_) noexcept : ptr {x_} {}
	constexpr csignal::csignal(const i64 x_) noexcept : r64 {x_} {}
	constexpr csignal::csignal(const u64 x_) noexcept : r64 {x_} {}
	constexpr csignal::csignal(const f64 x_) noexcept : r64 {x_} {}
	constexpr csignal::csignal(const c32 x_) noexcept : r64 {x_} {}

	constexpr auto operator""_sig_u(const unsigned long long int x_) noexcept -> csignal {
		return csignal {static_cast<u64>(x_)};
	}

	constexpr auto operator""_sig_i(const unsigned long long int x_) noexcept -> csignal {
		return csignal {static_cast<i64>(x_)};
	}

	constexpr auto operator""_sig_f(const long double x_) noexcept -> csignal {
		return csignal {static_cast<f64>(x_)};
	}

	static_assert(std::is_same_v<std::underlying_type_t<instruction>, std::uint64_t>);
	static_assert(sizeof(instruction) == alignof(u64));
	static_assert(alignof(instruction) == alignof(u64));
	static_assert(sizeof(csignal) == alignof(u64));
	static_assert(alignof(csignal) == alignof(u64));
	static_assert(std::is_standard_layout_v<csignal>);

	using intrinsic_routine = auto (record64*) -> bool;
	static_assert(std::is_function_v<intrinsic_routine>);

	/* std::visit auto overload helper */
	template <typename... Ts> struct overloaded : Ts... {
		using Ts::operator()...;
	};
	
	template <typename... Ts> overloaded(Ts&&...) -> overloaded<Ts...>;

	template <typename... Ts>
	concept bytecode_element_rule = requires(Ts&&... xs_) {
		requires !((sizeof(Ts) + ... + 0) % sizeof(u64)) || !((sizeof(Ts) + ... + 0) % sizeof(u32));
		requires !((alignof(Ts) + ... + 0) % alignof(u64)) || !((alignof(Ts) + ... + 0) % alignof(u32));
		requires std::is_trivially_copy_constructible_v<Ts...>;
		requires std::is_trivially_copy_assignable_v<Ts...>;
		requires std::is_standard_layout_v<Ts...>;
		requires std::is_constructible_v<Ts..., Ts...>;
	};

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
	struct bytecode_element final {
		using data_union = std::variant<instruction, intrinsic, cintrinsic, u64, i64, f64, c32>;

		explicit constexpr bytecode_element(data_union&& data_) noexcept;
		explicit constexpr bytecode_element(instruction data_) noexcept;
		explicit constexpr bytecode_element(u64 data_) noexcept;
		explicit constexpr bytecode_element(i64 data_) noexcept;
		explicit constexpr bytecode_element(f64 data_) noexcept;
		explicit constexpr bytecode_element(c32 data_) noexcept;
		explicit constexpr bytecode_element(intrinsic data_) noexcept;
		explicit constexpr bytecode_element(cintrinsic data_) noexcept;
		constexpr bytecode_element(const bytecode_element&) noexcept = default;
		constexpr bytecode_element(bytecode_element&&) noexcept = default;
		constexpr auto operator =(const bytecode_element&) noexcept -> bytecode_element& = default;
		constexpr auto operator =(bytecode_element&&) noexcept -> bytecode_element& = default;
		~bytecode_element() = default;

		[[nodiscard]]
		explicit constexpr operator csignal() const;

		template <typename T> requires bytecode_element_rule<T> && is_bytecode_element<T>
		[[nodiscard]]
		constexpr auto unwrap() const -> std::optional<T>;

		template <typename T> requires bytecode_element_rule<T> && is_bytecode_element<T>
		[[nodiscard]]
		constexpr auto contains() const noexcept -> bool;

		template <typename T> requires bytecode_element_rule<T> && is_bytecode_element<T>
		[[nodiscard]]
		constexpr auto contains(T&& cmp_) const -> bool;
		
		data_union data;
	};

	constexpr bytecode_element::bytecode_element(data_union&& data_) noexcept : data{data_} {}
	constexpr bytecode_element::bytecode_element(const instruction data_) noexcept : data{data_} {}
	constexpr bytecode_element::bytecode_element(const u64 data_) noexcept : data{data_} {}
	constexpr bytecode_element::bytecode_element(const i64 data_) noexcept : data{data_} {}
	constexpr bytecode_element::bytecode_element(const f64 data_) noexcept : data{data_} {}
	constexpr bytecode_element::bytecode_element(const c32 data_) noexcept : data{data_} {}
	constexpr bytecode_element::bytecode_element(const intrinsic data_) noexcept : data{data_} {}
	constexpr bytecode_element::bytecode_element(const cintrinsic data_) noexcept : data{data_} {}

	template <typename T> requires bytecode_element_rule<T> && is_bytecode_element<T>
	constexpr auto bytecode_element::unwrap() const -> std::optional<T> {
		return std::holds_alternative<T>(this->data) ? std::optional<T>{std::get<T>(this->data)} : std::nullopt;
	}

	template <typename T> requires bytecode_element_rule<T> && is_bytecode_element<T>
	constexpr auto bytecode_element::contains() const noexcept -> bool {
		return std::holds_alternative<T>(this->data);
	}

	template <typename T> requires bytecode_element_rule<T> && is_bytecode_element<T>
	constexpr auto bytecode_element::contains(T&& cmp_) const -> bool {
		return std::holds_alternative<T>(this->data) && std::get<T>(this->data) == cmp_;
	}

	constexpr bytecode_element::operator csignal() const {
		return std::visit(overloaded {
			[](const instruction x_) noexcept {
				return csignal{x_};
			},
			[](const intrinsic x_) noexcept {
				return csignal{x_};
			},
			[](const cintrinsic x_) noexcept {
				return csignal{x_.id};
			},
			[](const u64 x_) noexcept {
				return csignal{x_};
			},
			[](const i64 x_) noexcept {
				return csignal{x_};
			},
			[](const f64 x_) noexcept {
				return csignal{x_};
			},
			[](const c32 x_) noexcept {
				return csignal{x_};
			},
		}, this->data);
	}
}
