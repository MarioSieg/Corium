#include "../Include/Nominax/Validator.hpp"

namespace Nominax {
	auto perform_bytecode_validation_for_instruction(const Instruction instr_, const std::span<DynamicSignal> args_) -> validation_result_error {
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
			const DynamicSignal& arg = args_[i];
			
			// required operand type:
			const idb::instruction_imm_arg_type required_type = type_table[i];

			// true if the data types are equal, else false
			bool correct_type;
			
			switch (required_type) {
				case idb::instruction_imm_arg_type::i64: 
					correct_type = arg.Contains<std::int64_t>();
				break;
				case idb::instruction_imm_arg_type::u64:
				case idb::instruction_imm_arg_type::rel64:
				case idb::instruction_imm_arg_type::abs64:
					correct_type = arg.Contains<std::uint64_t>();
				break;
				case idb::instruction_imm_arg_type::intrin64:
					correct_type = arg.Contains<SystemIntrinsicID>() || arg.Contains<CustomIntrinsicID>();
				break;
				case idb::instruction_imm_arg_type::f64: 
					correct_type = arg.Contains<double>();
				break;
				case idb::instruction_imm_arg_type::i64_u64:
					correct_type = arg.Contains<std::int64_t>() || arg.Contains<std::uint64_t>();
				break;
				case idb::instruction_imm_arg_type::i64_u64_f64: 
					correct_type = arg.Contains<std::int64_t>() || arg.Contains<std::uint64_t>() || arg.Contains<double>();
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
