#pragma once

#include <csignal>
#include <limits>
#include <string_view>
#include <type_traits>

/*	interrupt < 0 =>
 *		hard error => can not recover => exit program => show error message
 *	interrupt = 0 =>
 *		success => exit program
 *	interrupt > 0 =>
 *		throw exception => call interrupt handler => call exception handler => if ok => continue execution else => exit program => show error message
 */

namespace Nominax {
	using abort_handler = void();
	using sig_handler = void(std::sig_atomic_t);

	[[noreturn]] extern void com_sig_handler(std::sig_atomic_t);
	[[noreturn]] extern void com_abr_handler();

	inline constinit abort_handler* sys_abort_handler{&com_abr_handler};

	extern auto sig_status() noexcept -> std::sig_atomic_t;
	extern void sig_install();
	extern void sig_uninstall();

	using interrupt_accumulator = std::int32_t;
	static_assert(std::is_trivial_v<interrupt_accumulator>);

	using interrupt_routine = auto (interrupt_accumulator, void*) -> bool;
	static_assert(std::is_function_v<interrupt_routine>);

	enum class terminate_type {
		success,
		exception,
		error
	};

	enum class interrupt: interrupt_accumulator {
		nullptr_deref		= std::numeric_limits<interrupt_accumulator>::min() + 7,		
		io					= std::numeric_limits<interrupt_accumulator>::min() + 6,
		jit_fault			= std::numeric_limits<interrupt_accumulator>::min() + 5,
		stack_overflow		= std::numeric_limits<interrupt_accumulator>::min() + 4,
		intrinsic_trap		= std::numeric_limits<interrupt_accumulator>::min() + 3,
		bad_alloc			= std::numeric_limits<interrupt_accumulator>::min() + 2,
		internal			= std::numeric_limits<interrupt_accumulator>::min() + 1,
		unknown				= std::numeric_limits<interrupt_accumulator>::min(),

		min_ = unknown,
		max_ = nullptr_deref
	};

	constexpr auto operator ==(const interrupt lhs_, const std::underlying_type_t<interrupt> rhs_) noexcept -> bool {
		return static_cast<std::underlying_type_t<interrupt>>(lhs_) == rhs_;
	}

	constexpr auto operator !=(const interrupt lhs_, const std::underlying_type_t<interrupt> rhs_) noexcept -> bool {
		return static_cast<std::underlying_type_t<interrupt>>(lhs_) != rhs_;
	}

	[[nodiscard]] extern auto interrupt_enumerator_name(interrupt int_) noexcept -> std::string_view;
	[[nodiscard]] extern auto basic_error_info(interrupt int_) noexcept -> std::string_view;
	[[nodiscard]] extern auto detailed_error_info(interrupt int_) -> std::string;
	[[nodiscard]] extern auto interrupt_cvt(interrupt_accumulator iac_) noexcept -> interrupt;
	[[nodiscard]] extern auto terminate_type_cvt(interrupt_accumulator iac_) noexcept -> terminate_type;
}
