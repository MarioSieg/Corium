#pragma once

#include <chrono>
#include <csignal>
#include <cstddef>

#include "Bytecode.hpp"
#include "Interrupts.hpp"

namespace Nominax {
	enum class ReactorValidationResult {
		Ok = 0,
		NullPtr,
		ZeroSize,
		MissingCodePrologue,
		MissingCodeEpilogue,
		MissingStackPrologue,
		NullIntrinsicRoutine
	};
	
	/// <summary>
	/// Contains all input data for the VM reactor.
	/// </summary>
	struct ReactorInput final {
		volatile std::sig_atomic_t*		SignalStatus			{nullptr};
		const Signal*					CodeChunk				{nullptr};
		std::size_t						CodeChunkSize			{0};
		intrinsic_routine**				IntrinsicTable			{nullptr};
		std::size_t						IntrinsicTableSize		{0};
		InterruptRoutine*				InterruptHandler		{nullptr};
		Record64*						Stack					{nullptr};
		std::size_t						StackSize				{0};
		void*							UserData				{nullptr};

		[[nodiscard]]
		auto Validate() const noexcept -> ReactorValidationResult;
	};

	/// <summary>
	/// Contains all the output data from the VM reactor.
	/// </summary>
	struct ReactorOutput final {
		const ReactorInput* Input{nullptr};
		ReactorValidationResult ValidationResult{};
		TerminateResult TerminateResult{};
		SystemInterrupt SystemInterrupt{};
		std::chrono::high_resolution_clock::time_point Pre{};
		std::chrono::high_resolution_clock::time_point Post{};
		std::chrono::high_resolution_clock::duration Duration{};
		InterruptAccumulator InterruptCode{};
		std::ptrdiff_t IpDiff{};
		std::ptrdiff_t SpDiff{};
	};

	[[nodiscard]] __attribute__((hot)) extern auto ExecuteChecked(const ReactorInput& input) -> ReactorOutput;
}
