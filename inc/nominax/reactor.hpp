#pragma once

#include <chrono>
#include <csignal>
#include <cstddef>

#include "bytecode.hpp"
#include "interrupts.hpp"

namespace nominax {
	enum class reactor_validation_result {
		ok = 0,
		null_ptr,
		zero_size,
		missing_code_prologue,
		missing_stack_prologue,
		null_intrinsic_routine
	};
	
	/// <summary>
	/// Contains all input data for the VM reactor.
	/// </summary>
	struct reactor_input final {
		volatile std::sig_atomic_t*		test_signal_status		{nullptr};
		const csignal*					code_chunk				{nullptr};
		std::size_t						code_chunk_size			{0};
		intrinsic_routine**				intrinsic_table			{nullptr};
		std::size_t						intrinsic_table_size	{0};
		interrupt_routine*				interrupt_handler		{nullptr};
		record64*						stack					{nullptr};
		std::size_t						stack_size				{0};
		void*							user_data				{nullptr};

		[[nodiscard]]
		auto validate() const noexcept -> reactor_validation_result;
	};

	/// <summary>
	/// Contains all the output data from the VM reactor.
	/// </summary>
	struct reactor_output final {
		const reactor_input* input{nullptr};
		reactor_validation_result validation_result{};
		terminate_type terminate_result{};
		interrupt system_interrupt{};
		std::chrono::high_resolution_clock::time_point pre{};
		std::chrono::high_resolution_clock::time_point post{};
		std::chrono::high_resolution_clock::duration duration{};
		interrupt_accumulator interrupt{};
		std::ptrdiff_t ip_diff{};
		std::ptrdiff_t sp_diff{};
	};

	[[nodiscard]]
	__attribute__((hot)) extern auto execute_reactor(const reactor_input& input_) -> reactor_output;
}
