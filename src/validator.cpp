#include "../inc/nominax/validator.hpp"

namespace nominax {
	auto perform_bytecode_validation_for_instruction(const instruction instr_, const std::span<dy_signal> args_) -> validation_result_error {
		const auto instr_idx = static_cast<std::size_t>(instr_);
		const std::uint8_t required_arg_count = idb::imm_arg_counts[instr_idx];

		// check if we submitted not enough arguments:
		if (args_.size() < required_arg_count) [[unlikely]] {
			return validation_result_error::not_enough_arguments;
		}

		// check if we submitted too many arguments:
		if (args_.size() > required_arg_count) [[unlikely]] {
			return validation_result_error::too_many_arguments;
		}
		
		// fetch the type table:
		const std::array<idb::instruction_imm_arg_type, idb::max_imm_args>& type_table = idb::imm_arg_types[instr_idx];

		// this loop checks each submitted operand type with the required operand type.
		for (std::size_t i = 0; i < args_.size(); ++i) [[likely]] {
			// submitted operand:
			const dy_signal& arg = args_[i];
			
			// required operand type:
			const idb::instruction_imm_arg_type required_type = type_table[i];

			// true if the data types are equal, else false
			bool correct_type;
			
			switch (required_type) {
				case idb::instruction_imm_arg_type::i64: 
					correct_type = arg.contains<i64>();
				break;
				case idb::instruction_imm_arg_type::u64:
				case idb::instruction_imm_arg_type::rel64:
				case idb::instruction_imm_arg_type::abs64:
					correct_type = arg.contains<u64>();
				break;
				case idb::instruction_imm_arg_type::intrin64:
					correct_type = arg.contains<intrinsic>() || arg.contains<cintrinsic>();
				break;
				case idb::instruction_imm_arg_type::f64: 
					correct_type = arg.contains<f64>();
				break;
				case idb::instruction_imm_arg_type::i64_u64:
					correct_type = arg.contains<i64>() || arg.contains<u64>();
				break;
				case idb::instruction_imm_arg_type::i64_u64_f64: 
					correct_type = arg.contains<i64>() || arg.contains<u64>() || arg.contains<f64>();
				break;
				default:
					correct_type = false;
			}

			// if the types where not equal, return error:
			if (!correct_type) [[unlikely]] {
				return validation_result_error::invalid_operand_type;
			}
		}

		return validation_result_error::ok;
	}
}
