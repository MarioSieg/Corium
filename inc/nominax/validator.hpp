#pragma once

#include <span>

#include "bytecode.hpp"

namespace nominax {
	enum class validation_result_error {
		ok = 0,
		not_enough_arguments,
		too_many_arguments,
		invalid_operand_type
	};

	struct validation_result final {
		validation_result_error error{};
		std::size_t index{};
	};

	[[nodiscard]] extern auto perform_bytecode_validation_for_instruction(instruction instr_, std::span<dy_signal> args_) -> validation_result_error;
}
