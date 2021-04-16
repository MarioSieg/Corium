#include "../inc/nominax/interrupts.hpp"

#include <algorithm>
#include <sstream>

namespace {
	constinit volatile std::sig_atomic_t signal_status{0};
}

namespace nominax {
	auto sig_status() noexcept -> std::sig_atomic_t {
		return ::signal_status;
	}

	void com_sig_handler(const std::sig_atomic_t sig_sta_) {
		::signal_status = sig_sta_;
		sys_abort_handler();
		std::abort();
	}

	void com_abr_handler() {
		std::abort();
	}

	void sig_install() {
		std::signal(SIGINT, &com_sig_handler);
		std::signal(SIGILL, &com_sig_handler);
		std::signal(SIGFPE, &com_sig_handler);
		std::signal(SIGSEGV, &com_sig_handler);
		std::signal(SIGTERM, &com_sig_handler);
		std::signal(SIGBREAK, &com_sig_handler);
		std::signal(SIGABRT_COMPAT, &com_sig_handler);
	}
	
	void sig_uninstall() {
		std::signal(SIGINT, SIG_DFL);
		std::signal(SIGILL, SIG_DFL);
		std::signal(SIGFPE, SIG_DFL);
		std::signal(SIGSEGV, SIG_DFL);
		std::signal(SIGTERM, SIG_DFL);
		std::signal(SIGBREAK, SIG_DFL);
		std::signal(SIGABRT_COMPAT, SIG_DFL);
	}

	auto interrupt_enumerator_name(const interrupt int_) noexcept -> std::string_view {
		switch (int_) {
			case interrupt::nullptr_deref:			return "interrupt::nullptr_deref";
			case interrupt::io:						return "interrupt::io";
			case interrupt::jit_fault:				return "interrupt::jit_fault";
			case interrupt::stack_overflow:			return "interrupt::stack_overflow";
			case interrupt::intrinsic_trap:			return "interrupt::intrinsic_trap";
			case interrupt::bad_alloc:				return "interrupt::bad_alloc";
			case interrupt::internal:				return "interrupt::internal";
			default: case interrupt::unknown:		return "interrupt::unknown";
		}
	}

	auto basic_error_info(const interrupt int_) noexcept -> std::string_view {
		switch (int_) {
			case interrupt::nullptr_deref:			return "NullPointerError";
			case interrupt::io:						return "IOError";
			case interrupt::jit_fault:				return "JITCompilationError";
			case interrupt::stack_overflow:			return "StackOverflowError";
			case interrupt::intrinsic_trap:			return "IntrinsicError";
			case interrupt::bad_alloc:				return "OutOfMemoryError";
			case interrupt::internal:				return "InternalError";
			default: case interrupt::unknown:		return "UnknownError";
		}
	}

	auto detailed_error_info(const interrupt int_) -> std::string {
		std::stringstream ss;
		ss << basic_error_info(int_) << '\n';
		ss << interrupt_enumerator_name(int_) << " : " << std::hex << "0x" << static_cast<std::underlying_type_t<decltype(int_)>>(int_) << '\n';
		return ss.str();
	}

	auto interrupt_cvt(const interrupt_accumulator iac_) noexcept -> interrupt {
		return static_cast<interrupt>(std::clamp(iac_, static_cast<std::underlying_type_t<interrupt>>(interrupt::min_), static_cast<std::underlying_type_t<interrupt>>(interrupt::max_)));
	}
	
	auto terminate_type_cvt(const interrupt_accumulator iac_) noexcept -> terminate_type {
		return iac_ == 0 ? terminate_type::success : iac_ < 0 ? terminate_type::error : terminate_type::exception;
	}
}
