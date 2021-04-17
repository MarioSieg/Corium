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
	using PanicRoutine = void();
	using SignalRoutine = void(std::sig_atomic_t);

	[[noreturn]] extern void DefaultSignalHandler(std::sig_atomic_t);
	[[noreturn]] extern void DefaultPanicHandler();

	inline constinit PanicRoutine* CurrentPanicHandler{&DefaultPanicHandler};

	extern auto QuerySignalStatus() noexcept -> std::sig_atomic_t;
	extern void InstallSignalHandlers();
	extern void UninstallSignalHandlers();

	using InterruptAccumulator = std::int32_t;
	static_assert(std::is_trivial_v<InterruptAccumulator>);

	using InterruptRoutine = auto (InterruptAccumulator, void*) -> bool;
	static_assert(std::is_function_v<InterruptRoutine>);

	enum class TerminateResult {
		Success,
		Exception,
		Error
	};

	enum class SystemInterrupt: InterruptAccumulator {
		NullptrDeref		= std::numeric_limits<InterruptAccumulator>::min() + 7,		
		Io					= std::numeric_limits<InterruptAccumulator>::min() + 6,
		JitFault			= std::numeric_limits<InterruptAccumulator>::min() + 5,
		StackOverflow		= std::numeric_limits<InterruptAccumulator>::min() + 4,
		IntrinsicTrap		= std::numeric_limits<InterruptAccumulator>::min() + 3,
		BadAlloc			= std::numeric_limits<InterruptAccumulator>::min() + 2,
		Internal			= std::numeric_limits<InterruptAccumulator>::min() + 1,
		Unknown				= std::numeric_limits<InterruptAccumulator>::min(),

		Min = Unknown,
		Max = NullptrDeref
	};

	constexpr auto operator ==(const SystemInterrupt left, const std::underlying_type_t<SystemInterrupt> right) noexcept -> bool {
		return static_cast<std::underlying_type_t<SystemInterrupt>>(left) == right;
	}

	constexpr auto operator !=(const SystemInterrupt left, const std::underlying_type_t<SystemInterrupt> right) noexcept -> bool {
		return static_cast<std::underlying_type_t<SystemInterrupt>>(left) != right;
	}

	[[nodiscard]] extern auto InterruptEnumeratorName(SystemInterrupt interrupt) noexcept -> std::string_view;
	[[nodiscard]] extern auto BasicErrorInfo(SystemInterrupt interrupt) noexcept -> std::string_view;
	[[nodiscard]] extern auto DetailedErrorInfo(SystemInterrupt interrupt) -> std::string;
	[[nodiscard]] extern auto InterruptCvt(InterruptAccumulator interrupt) noexcept -> SystemInterrupt;
	[[nodiscard]] extern auto TerminateTypeCvt(InterruptAccumulator interrupt) noexcept -> TerminateResult;
}
