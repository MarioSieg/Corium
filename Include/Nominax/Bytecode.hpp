#pragma once

#include <array>
#include <optional>
#include <variant>

#include "IDB.hpp"
#include "Record.hpp"
#include "SysIntrin.hpp"

namespace Nominax {
	struct CustomIntrinsicID final {
		std::uint64_t ID;

		constexpr auto operator ==(CustomIntrinsicID rhs) const noexcept -> bool;
		constexpr auto operator !=(CustomIntrinsicID rhs) const noexcept -> bool;
		constexpr auto operator <(CustomIntrinsicID rhs) const noexcept -> bool;
		constexpr auto operator >(CustomIntrinsicID rhs) const noexcept -> bool;
		constexpr auto operator <=(CustomIntrinsicID rhs) const noexcept -> bool;
		constexpr auto operator >=(CustomIntrinsicID rhs) const noexcept -> bool;
	};

	constexpr auto CustomIntrinsicID::operator ==(const CustomIntrinsicID rhs) const noexcept -> bool {
		return this->ID == rhs.ID;
	}

	constexpr auto CustomIntrinsicID::operator !=(const CustomIntrinsicID rhs) const noexcept -> bool {
		return this->ID != rhs.ID;
	}

	constexpr auto CustomIntrinsicID::operator <(const CustomIntrinsicID rhs) const noexcept -> bool {
		return this->ID < rhs.ID;
	}

	constexpr auto CustomIntrinsicID::operator >(const CustomIntrinsicID rhs) const noexcept -> bool {
		return this->ID > rhs.ID;
	}

	constexpr auto CustomIntrinsicID::operator <=(const CustomIntrinsicID rhs) const noexcept -> bool {
		return this->ID <= rhs.ID;
	}

	constexpr auto CustomIntrinsicID::operator >=(const CustomIntrinsicID rhs) const noexcept -> bool {
		return this->ID >= rhs.ID;
	}
	
	/* 64-bit byte code signal data contains either an instruction or an immediate value. */
	union alignas(alignof(std::uint64_t)) Signal {
		Record64 R64;
		Instruction Instr;
		SystemIntrinsicID IntrinID;
		CustomIntrinsicID CustomIntrinID;
		std::uint64_t OpCode;
		void* Ptr;

		explicit constexpr Signal(Record64 value) noexcept;
		explicit constexpr Signal(Instruction value) noexcept;
		explicit constexpr Signal(SystemIntrinsicID value) noexcept;
		explicit constexpr Signal(void* value) noexcept;
		explicit constexpr Signal(std::int64_t value) noexcept;
		explicit constexpr Signal(std::uint64_t value) noexcept;
		explicit constexpr Signal(double value) noexcept;
		explicit constexpr Signal(char32_t value) noexcept;
	};

	constexpr Signal::Signal(const Record64 value) noexcept : R64 {value} {}
	constexpr Signal::Signal(const Instruction value) noexcept : Instr {value} {}
	constexpr Signal::Signal(const SystemIntrinsicID value) noexcept : IntrinID{value} {}
	constexpr Signal::Signal(void* const value) noexcept : Ptr {value} {}
	constexpr Signal::Signal(const std::int64_t value) noexcept : R64 {value} {}
	constexpr Signal::Signal(const std::uint64_t value) noexcept : R64 {value} {}
	constexpr Signal::Signal(const double value) noexcept : R64 {value} {}
	constexpr Signal::Signal(const char32_t value) noexcept : R64 {value} {}

	constexpr auto operator""_sig_u(const unsigned long long int value) noexcept -> Signal {
		return Signal {static_cast<std::uint64_t>(value)};
	}

	constexpr auto operator""_sig_i(const unsigned long long int value) noexcept -> Signal {
		return Signal {static_cast<std::int64_t>(value)};
	}

	constexpr auto operator""_sig_f(const long double value) noexcept -> Signal {
		return Signal {static_cast<double>(value)};
	}

	static_assert(std::is_same_v<std::underlying_type_t<Instruction>, std::uint64_t>);
	static_assert(sizeof(Instruction) == sizeof(std::uint64_t));
	static_assert(sizeof(Signal) == sizeof(std::uint64_t));
	static_assert(std::is_standard_layout_v<Signal>);

	using intrinsic_routine = auto (Record64*) -> bool;
	static_assert(std::is_function_v<intrinsic_routine>);

	/* std::visit auto overload helper */
	template <typename... Ts> struct overloaded : Ts... {
		using Ts::operator()...;
	};
	
	template <typename... Ts> overloaded(Ts&&...) -> overloaded<Ts...>;

	template <typename T>
	concept is_bytecode_element = 
		std::is_same_v<T, Instruction>
		|| std::is_same_v<T, SystemIntrinsicID>
		|| std::is_same_v<T, CustomIntrinsicID>
		|| std::is_same_v<T, std::uint64_t>
		|| std::is_same_v<T, std::int64_t>
		|| std::is_same_v<T, double>
		|| std::is_same_v<T, char32_t>;

	/* Represents an entry in a bytecode steam. This get's converted to a csignal for execution. */
	struct DynamicSignal final {
		using Variant = std::variant<Instruction, SystemIntrinsicID, CustomIntrinsicID, std::uint64_t, std::int64_t, double, char32_t>;

		explicit constexpr DynamicSignal(Variant&& data) noexcept;
		explicit constexpr DynamicSignal(Instruction value) noexcept;
		explicit constexpr DynamicSignal(std::uint64_t value) noexcept;
		explicit constexpr DynamicSignal(std::int64_t value) noexcept;
		explicit constexpr DynamicSignal(double value) noexcept;
		explicit constexpr DynamicSignal(char32_t value) noexcept;
		explicit constexpr DynamicSignal(SystemIntrinsicID value) noexcept;
		explicit constexpr DynamicSignal(CustomIntrinsicID value) noexcept;
		constexpr DynamicSignal(const DynamicSignal&) noexcept = default;
		constexpr DynamicSignal(DynamicSignal&&) noexcept = default;
		constexpr auto operator =(const DynamicSignal&) noexcept -> DynamicSignal& = default;
		constexpr auto operator =(DynamicSignal&&) noexcept -> DynamicSignal& = default;
		~DynamicSignal() = default;

		[[nodiscard]]
		explicit constexpr operator Signal() const;

		template <typename T> requires is_bytecode_element<T>
		[[nodiscard]]
		constexpr auto Unwrap() const -> std::optional<T>;

		template <typename T> requires is_bytecode_element<T>
		[[nodiscard]]
		constexpr auto Contains() const noexcept -> bool;

		template <typename T> requires is_bytecode_element<T>
		[[nodiscard]]
		constexpr auto Contains(T&& compareTo) const -> bool;
		
		Variant DataCollection{};
	};

	constexpr DynamicSignal::DynamicSignal(Variant&& data) noexcept : DataCollection{data} {}
	constexpr DynamicSignal::DynamicSignal(const Instruction value) noexcept : DataCollection{value} {}
	constexpr DynamicSignal::DynamicSignal(const std::uint64_t value) noexcept : DataCollection{value} {}
	constexpr DynamicSignal::DynamicSignal(const std::int64_t value) noexcept : DataCollection{value} {}
	constexpr DynamicSignal::DynamicSignal(const double value) noexcept : DataCollection{value} {}
	constexpr DynamicSignal::DynamicSignal(const char32_t data_) noexcept : DataCollection{data_} {}
	constexpr DynamicSignal::DynamicSignal(const SystemIntrinsicID value) noexcept : DataCollection{value} {}
	constexpr DynamicSignal::DynamicSignal(const CustomIntrinsicID value) noexcept : DataCollection{value} {}

	template <typename T> requires is_bytecode_element<T>
	constexpr auto DynamicSignal::Unwrap() const -> std::optional<T> {
		return std::holds_alternative<T>(this->DataCollection) ? std::optional<T>{std::get<T>(this->DataCollection)} : std::nullopt;
	}

	template <typename T> requires is_bytecode_element<T>
	constexpr auto DynamicSignal::Contains() const noexcept -> bool {
		return std::holds_alternative<T>(this->DataCollection);
	}

	template <typename T> requires is_bytecode_element<T>
	constexpr auto DynamicSignal::Contains(T&& compareTo) const -> bool {
		return std::holds_alternative<T>(this->DataCollection) && std::get<T>(this->DataCollection) == compareTo;
	}

	constexpr DynamicSignal::operator Signal() const {
		return std::visit(overloaded {
			[](const Instruction value) noexcept {
				return Signal{value};
			},
			[](const SystemIntrinsicID value) noexcept {
				return Signal{value};
			},
			[](const CustomIntrinsicID value) noexcept {
				return Signal{value.ID};
			},
			[](const std::uint64_t value) noexcept {
				return Signal{value};
			},
			[](const std::int64_t value) noexcept {
				return Signal{value};
			},
			[](const double value) noexcept {
				return Signal{value};
			},
			[](const char32_t value) noexcept {
				return Signal{value};
			},
		}, this->DataCollection);
	}
}
