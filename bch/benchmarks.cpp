#include "benchbase.hpp"

static void loop_1_billion(benchmark::State& state) {
	const std::vector<rt_signal> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::pushz},
		rt_signal{instruction::iinc},
		rt_signal{instruction::dupl},
		rt_signal{instruction::push},
		rt_signal{1'000'000'000_i64},
		rt_signal{instruction::jl_cmpi},
		rt_signal{2_u64},
		rt_signal{instruction::pop},
		rt_signal{instruction::inter},
		rt_signal{0_i64},
	};

	std::array<record64, 32> stack = { record64::nop_padding() };

	volatile std::sig_atomic_t sig{};
	std::array<intrinsic_routine*, 1> intrins{
		+[](record64*) -> bool { return true; }
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

		if (o.input->stack[1].i != 1'000'000'000_i64) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}

		if (o.input->stack[2].i != 1'000'000'000_i64) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}

		if (o.input->stack[3].i != 1'000'000'000_i64) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}
	}
}

BENCHMARK(loop_1_billion)->Unit(benchmark::TimeUnit::kSecond);

static void loop_5_billion(benchmark::State& state) {
	const std::vector<rt_signal> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::pushz},
		rt_signal{instruction::iinc},
		rt_signal{instruction::dupl},
		rt_signal{instruction::push},
		rt_signal{5'000'000'000_i64},
		rt_signal{instruction::jl_cmpi},
		rt_signal{2_u64},
		rt_signal{instruction::pop},
		rt_signal{instruction::inter},
		rt_signal{0_i64},
	};

	std::array<record64, 32> stack = { record64::nop_padding() };

	volatile std::sig_atomic_t sig{};
	std::array<intrinsic_routine*, 1> intrins{
		+[](record64*) -> bool { return true; }
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

		if (o.input->stack[1].i != 5'000'000'000_i64) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}

		if (o.input->stack[2].i != 5'000'000'000_i64) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}

		if (o.input->stack[3].i != 5'000'000'000_i64) {
			state.SkipWithError("Expected different value on stack!");
			break;
		}
	}
}

BENCHMARK(loop_5_billion)->Unit(benchmark::TimeUnit::kSecond);

BENCHMARK_MAIN();