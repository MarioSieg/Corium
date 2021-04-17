#include "../Include/Nominax/Interrupts.hpp"

#include <algorithm>
#include <sstream>

namespace {
	constinit volatile std::sig_atomic_t signal_status{0};
}

namespace Nominax {
	auto QuerySignalStatus() noexcept -> std::sig_atomic_t {
		return ::signal_status;
	}

	void DefaultSignalHandler(const std::sig_atomic_t sig_sta_) {
		::signal_status = sig_sta_;
		CurrentPanicHandler();
		std::abort();
	}

	void DefaultPanicHandler() {
		std::abort();
	}

	void InstallSignalHandlers() {
		std::signal(SIGINT, &DefaultSignalHandler);
		std::signal(SIGILL, &DefaultSignalHandler);
		std::signal(SIGFPE, &DefaultSignalHandler);
		std::signal(SIGSEGV, &DefaultSignalHandler);
		std::signal(SIGTERM, &DefaultSignalHandler);
        std::signal(SIGABRT, &DefaultSignalHandler);
	}
	
	void UninstallSignalHandlers() {
		std::signal(SIGINT, SIG_DFL);
		std::signal(SIGILL, SIG_DFL);
		std::signal(SIGFPE, SIG_DFL);
		std::signal(SIGSEGV, SIG_DFL);
		std::signal(SIGTERM, SIG_DFL);
        std::signal(SIGABRT, SIG_DFL);
	}

	auto InterruptEnumeratorName(const SystemInterrupt interrupt) noexcept -> std::string_view {
		switch (interrupt) {
			case SystemInterrupt::NullptrDeref:			return "interrupt::nullptr_deref";
			case SystemInterrupt::Io:						return "interrupt::io";
			case SystemInterrupt::JitFault:				return "interrupt::jit_fault";
			case SystemInterrupt::StackOverflow:			return "interrupt::stack_overflow";
			case SystemInterrupt::IntrinsicTrap:			return "interrupt::intrinsic_trap";
			case SystemInterrupt::BadAlloc:				return "interrupt::bad_alloc";
			case SystemInterrupt::Internal:				return "interrupt::internal";
			default: case SystemInterrupt::Unknown:		return "interrupt::unknown";
		}
	}

	auto BasicErrorInfo(const SystemInterrupt interrupt) noexcept -> std::string_view {
		switch (interrupt) {
			case SystemInterrupt::NullptrDeref:			return "NullPointerError";
			case SystemInterrupt::Io:						return "IOError";
			case SystemInterrupt::JitFault:				return "JITCompilationError";
			case SystemInterrupt::StackOverflow:			return "StackOverflowError";
			case SystemInterrupt::IntrinsicTrap:			return "IntrinsicError";
			case SystemInterrupt::BadAlloc:				return "OutOfMemoryError";
			case SystemInterrupt::Internal:				return "InternalError";
			default: case SystemInterrupt::Unknown:		return "UnknownError";
		}
	}

	auto DetailedErrorInfo(const SystemInterrupt interrupt) -> std::string {
		std::stringstream ss;
		ss << BasicErrorInfo(interrupt) << '\n';
		ss << InterruptEnumeratorName(interrupt) << " : " << std::hex << "0x" << static_cast<std::underlying_type_t<decltype(interrupt)>>(interrupt) << '\n';
		return ss.str();
	}

	auto InterruptCvt(const InterruptAccumulator interrupt) noexcept -> SystemInterrupt {
		return static_cast<SystemInterrupt>(std::clamp(interrupt, static_cast<std::underlying_type_t<SystemInterrupt>>(SystemInterrupt::Min), static_cast<std::underlying_type_t<SystemInterrupt>>(SystemInterrupt::Max)));
	}
	
	auto TerminateTypeCvt(const InterruptAccumulator interrupt) noexcept -> TerminateResult {
		return interrupt == 0 ? TerminateResult::Success : interrupt < 0 ? TerminateResult::Error : TerminateResult::Exception;
	}
}
