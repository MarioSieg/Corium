#pragma once

#include <string_view>

#include "runtime.hpp"

/*	interrupt < 0 =>
 *		hard error => can not recover => exit program => show error message
 *	interrupt = 0 =>
 *		success => exit program
 *	interrupt > 0 =>
 *		throw exception => call interrupt handler => call exception handler => if ok => continue execution else => exit program => show error message
 */

namespace nominax {

	using interrupt_accumulator = i32;
	static_assert(std::is_trivial_v<interrupt_accumulator>);

	using interrupt_routine = auto (interrupt_accumulator, void*) -> bool;
	static_assert(std::is_function_v<interrupt_routine>);

	enum class terminate_type {
		success,
		exception,
		error
	};

	enum interrupt: interrupt_accumulator {
		ex_nullptr_deref		= 0x00'00'00'01,	// exception			
		ex_io					= 0x00'00'00'02,	// exception

		er_jit_fault			= -0x7F'FF'FF'FA,	// error
		er_stack_overflow		= -0x7F'FF'FF'FB,	// error
		er_intrinsic_trap		= -0x7F'FF'FF'FC,	// error
		er_bad_alloc			= -0x7F'FF'FF'FD,	// error
		er_internal				= -0x7F'FF'FF'FE,	// error
		er_unknown				= -0x7F'FF'FF'FF,	// error
	};

	[[nodiscard]] constexpr auto get_error_message(const interrupt int_) noexcept -> std::string_view {
		switch (int_) {
			case ex_nullptr_deref:		return "NullPointerException [ex_nullptr_deref : 0x00000001]";
			case ex_io:					return "IOException [ex_io : 0x00000002]";
			
			case er_jit_fault:			return "JITCompilationError [er_jit_fault : -0x7FFFFFFA]";
			case er_stack_overflow:		return "StackOverflowError [er_stack_overflow : -0x7FFFFFFB]";
			case er_intrinsic_trap:		return "IntrinsicRoutineTrapError [er_intrinsic_trap : -0x7FFFFFFC]";
			case er_bad_alloc:			return "OutOfMemoryError [er_bad_alloc : -0x7FFFFFFD]";
			case er_internal:			return "UnknownInternalError [er_internal : -0x7FFFFFFE]";
			default: case er_unknown:	return "UnknownError [er_unknown : -0x7FFFFFFF]";
		}
	}

	[[nodiscard]] constexpr auto convert_to_system_interrupt_or_unknown(const interrupt_accumulator iac_) noexcept -> interrupt {
		switch (iac_) {
			case ex_nullptr_deref:		return ex_nullptr_deref;
			case ex_io:					return ex_io;

			case er_jit_fault:			return er_jit_fault;
			case er_stack_overflow:		return er_stack_overflow;
			case er_intrinsic_trap:		return er_intrinsic_trap;
			case er_bad_alloc:			return er_bad_alloc;
			case er_internal:			return er_internal;
			default: case er_unknown:	return er_unknown;
		}
	}
	
	[[nodiscard]] constexpr auto convert_terminate_type(const interrupt_accumulator iac_) noexcept -> terminate_type {
		if (iac_ == 0) [[likely]] {
			return terminate_type::success;
		}
		if (iac_ > 0) [[unlikely]] {
			return terminate_type::exception;
		}
		return terminate_type::error;
	}
}
