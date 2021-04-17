#include "benchbase.hpp"

static void loop_1_billion(benchmark::State& state) {
	const std::vector<Signal> code = {
		Signal{Instruction::nop}, // first padding
		Signal{Instruction::pushz},
		Signal{Instruction::iinc},
		Signal{Instruction::dupl},
		Signal{Instruction::push},
		Signal{1'000'000'000_std::int64_t},
		Signal{Instruction::jl_cmpi},
		Signal{2_std::uint64_t},
		Signal{Instruction::pop},
		Signal{Instruction::inter},
		Signal{0_std::int64_t},
	};

	std::array<Record64, 32> stack = { Record64::Padding() };

	volatile std::sig_atomic_t sig{};
	std::array<intrinsic_routine*, 1> intrins{
		+[](Record64*) -> bool { return true; }
	};

	const reactor_input input{
		.signal_status = &sig,
		.code_chunk = code.data(),
		.code_chunk_size = code.size(),
		.intrinsic_table = intrins.data(),
		.intrinsic_table_size = intrins.size(),
		.interrupt_handler = +[](interrupt_accumulator, void*) -> bool {
			return true;
		},
		.stack = stack.data(),
		.stack_size = stack.size(),
		.user_data = nullptr
	};

	if (input.validate() != reactor_validation_result::ok) {
		state.SkipWithError("Reactor input validation failed!");
		return;
	}
	
	for (auto _ : state) {
		const auto o{execute_reactor(input)};

		if (o.terminate_result != terminate_type::success) {
			state.SkipWithError("Reactor terminated with error or exception!");
			break;
		}

		if (o.sp_diff != 0) {
			state.SkipWithError("Not all stack entries were popped!");
			break;
		}

		if (o.input->stack[1].std::int64_t != 1'000'000'000_std::int64_t) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}

		if (o.input->stack[2].std::int64_t != 1'000'000'000_std::int64_t) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}

		if (o.input->stack[3].std::int64_t != 1'000'000'000_std::int64_t) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}
	}
}

BENCHMARK(loop_1_billion)->Unit(benchmark::TimeUnit::kSecond);

static void loop_5_billion(benchmark::State& state) {
	const std::vector<Signal> code = {
		Signal{Instruction::nop}, // first padding
		Signal{Instruction::pushz},
		Signal{Instruction::iinc},
		Signal{Instruction::dupl},
		Signal{Instruction::push},
		Signal{5'000'000'000_std::int64_t},
		Signal{Instruction::jl_cmpi},
		Signal{2_std::uint64_t},
		Signal{Instruction::pop},
		Signal{Instruction::inter},
		Signal{0_std::int64_t},
	};

	std::array<Record64, 32> stack = { Record64::Padding() };

	volatile std::sig_atomic_t sig{};
	std::array<intrinsic_routine*, 1> intrins{
		+[](Record64*) -> bool { return true; }
	};

	const reactor_input input{
		.signal_status = &sig,
		.code_chunk = code.data(),
		.code_chunk_size = code.size(),
		.intrinsic_table = intrins.data(),
		.intrinsic_table_size = intrins.size(),
		.interrupt_handler = +[](interrupt_accumulator, void*) -> bool {
			return true;
		},
		.stack = stack.data(),
		.stack_size = stack.size(),
		.user_data = nullptr
	};

	if (input.validate() != reactor_validation_result::ok) {
		state.SkipWithError("Reactor input validation failed!");
		return;
	}

	for (auto _ : state) {
		const auto o{ execute_reactor(input) };

		if (o.terminate_result != terminate_type::success) {
			state.SkipWithError("Reactor terminated with error or exception!");
			break;
		}

		if (o.sp_diff != 0) {
			state.SkipWithError("Not all stack entries were popped!");
			break;
		}

		if (o.input->stack[1].std::int64_t != 5'000'000'000_std::int64_t) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}

		if (o.input->stack[2].std::int64_t != 5'000'000'000_std::int64_t) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}

		if (o.input->stack[3].std::int64_t != 5'000'000'000_std::int64_t) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}
	}
}

BENCHMARK(loop_5_billion)->Unit(benchmark::TimeUnit::kSecond);

BENCHMARK_MAIN();