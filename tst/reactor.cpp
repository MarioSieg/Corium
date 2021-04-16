#include <array>
#include <cmath>
#include <numbers>

#include "tstbase.hpp"
#include "../inc/nominax/reactor.hpp"
#include "../inc/nominax/sysintrin.hpp"

using namespace nominax;

static constexpr intrinsic_routine* test_intrinsic_routine {+[]([[maybe_unused]] record64*) noexcept -> bool {
	return true;
}};

static constinit std::array<intrinsic_routine*, 3> test_intrinsic_routine_table {
	test_intrinsic_routine,
	test_intrinsic_routine,
	test_intrinsic_routine
};

static constexpr auto test_stack_size = 32; // 32 records

static constinit std::array<record64, test_stack_size> test_stack {record64::nop_padding()};

static constinit volatile std::sig_atomic_t signal_status;

static constinit interrupt_routine* test_interrupt_handler {+[](interrupt_accumulator, void*) noexcept -> bool {
	return true;
}};

static reactor_input default_test_input{
	.signal_status = &signal_status,
	.code_chunk = nullptr,
	.code_chunk_size = 0,
	.intrinsic_table = test_intrinsic_routine_table.data(),
	.intrinsic_table_size = test_intrinsic_routine_table.size(),
	.interrupt_handler = test_interrupt_handler,
	.stack = test_stack.data(),
	.stack_size = test_stack.size(),
	.user_data = nullptr
};

static constexpr std::array<rt_signal, 3> default_test_code = {
	rt_signal{instruction::nop}, // first padding
	rt_signal{instruction::inter},
	rt_signal{INT64_C(5)},
};

TEST(reactor_execution, __intrin__$cos) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::cos},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::cos(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$sin) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::sin},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{ default_test_input };
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{ execute_reactor(input) };
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::sin(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$tan) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::tan},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::tan(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$acos) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::acos},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{ default_test_input };
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{ execute_reactor(input) };
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::acos(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$asin) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::asin},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::asin(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$atan) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::atan},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::atan(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$atan2) {
	const std::array<rt_signal, 9> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::push},
		rt_signal{0.15},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::atan2},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::atan2(0.35, 0.15));
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 0.15);
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 2);
}

TEST(reactor_execution, __intrin__$cosh) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::cosh},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::cosh(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$sinh) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::sinh},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::sinh(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$tanh) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::tanh},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::tanh(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$acosh) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{1.6},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::acosh},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::acosh(1.6));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$asinh) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::asinh},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::asinh(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$atanh) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::atanh},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::atanh(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$exp) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::exp},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::exp(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$log) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::log},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::log(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$log10) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::log10},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::log10(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$exp2) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::exp2},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::exp2(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$ilogb) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{1.332},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::ilogb},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::ilogb(1.332));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$log2) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::log2},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::log2(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$pow) {
	const std::array<rt_signal, 9> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::push},
		rt_signal{0.15},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::pow},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::pow(0.35, 0.15));
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 0.15);
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 2);
}


TEST(reactor_execution, __intrin__$sqrt) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::sqrt},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::sqrt(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$cbrt) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::cbrt},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::cbrt(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$hypot) {
	const std::array<rt_signal, 9> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::push},
		rt_signal{0.15},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::hypot},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::hypot(0.35, 0.15));
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 0.15);
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 2);
}

TEST(reactor_execution, __intrin__$ceil) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::ceil},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::ceil(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$floor) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::floor},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::floor(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$round) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::round},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::round(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$rint) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::rint},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::rint(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$max) {
	const std::array<rt_signal, 9> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(4)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(7)},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::max},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, std::max<i64>(4, 7));
	ASSERT_EQ(o.input->stack[2].i, 7);
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 2);
}

TEST(reactor_execution, __intrin__$min) {
	const std::array<rt_signal, 9> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(4)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(7)},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::min},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, std::min<i64>(4, 7));
	ASSERT_EQ(o.input->stack[2].i, 7);
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 2);
}

TEST(reactor_execution, __intrin__$fmax) {
	const std::array<rt_signal, 9> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::push},
		rt_signal{0.15},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::fmax},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::max(0.35, 0.15));
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 0.15);
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 2);
}

TEST(reactor_execution, __intrin__$fmin) {
	const std::array<rt_signal, 9> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::push},
		rt_signal{0.15},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::fmin},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::fmin(0.35, 0.15));
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 0.15);
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 2);
}

TEST(reactor_execution, __intrin__$fdim) {
	const std::array<rt_signal, 9> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::push},
		rt_signal{0.15},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::fdim},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::fdim(0.35, 0.15));
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 0.15);
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 2);
}


TEST(reactor_execution, __intrin__$abs) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(223233)},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::abs},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, std::abs(223233));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __intrin__$fabs) {
	const std::array<rt_signal, 7> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{0.35},
		rt_signal{instruction::intrin},
		rt_signal{intrinsic::fabs},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::fabs(0.35));
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __int__) {
	const std::array<rt_signal, 5> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::inter},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-12345)},
	};

	auto input{default_test_input};

	int user{1234567};
	input.user_data = &user;

	static constinit interrupt_accumulator accum;
	static constinit void* usr;
	static constinit int calls;

	input.interrupt_handler = +[](const interrupt_accumulator x, void* const y) noexcept -> bool {
		accum = x;
		usr = y;
		++calls;
		return true;
	};

	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(calls, 2);
	ASSERT_EQ(accum, -12345);
	ASSERT_TRUE(usr != nullptr);
	ASSERT_EQ(*static_cast<int*>(usr), 1234567);
	ASSERT_EQ(*static_cast<int*>(o.input->user_data), 1234567);
    ASSERT_EQ(o.interrupt_code, -12345);
	ASSERT_EQ(o.ip_diff, code.size() - 1);
}

TEST(reactor_execution, __mov__) {
	const std::array<rt_signal, 9> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::sto},
		rt_signal{UINT64_C(3)},
		rt_signal{3.1415},
		rt_signal{instruction::mov},
		rt_signal{UINT64_C(8)},
		rt_signal{UINT64_C(3)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[3].f, 3.1415);
	ASSERT_EQ(o.input->stack[8].f, 3.1415);
}

TEST(reactor_execution, __sto__) {
	const std::array<rt_signal, 9> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::sto},
		rt_signal{UINT64_C(1)},
		rt_signal{INT64_C(5657334)},
		rt_signal{instruction::sto},
		rt_signal{UINT64_C(31)},
		rt_signal{3.1415},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 5657334);
	ASSERT_EQ(o.input->stack[31].f, 3.1415);
}

TEST(reactor_execution, __push__) {
	const std::array<rt_signal, 7> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(1224)},
		rt_signal{instruction::push},
		rt_signal{-0.6666},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-3)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 1224);
	ASSERT_EQ(o.input->stack[2].f, -0.6666);
}

#if NOMINAX_STACK_OVERFLOW_CHECKS

/*
 * Jump instruction which push do not required any checks. since they recycle stack space.
 */

TEST(reactor_execution, __push_no_stack_overflow__) {
	const std::array<csignal, 9> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(123)},
		csignal{instruction::push},
		csignal{INT64_C(123)},
		csignal{instruction::push},
		csignal{INT64_C(123)},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
	};
	// only can use 3 elements, 1st is reserved:
	std::array<record64, 4> stack{record64::nop_padding()};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	input.stack = stack.data();
	input.stack_size = stack.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 123);
	ASSERT_EQ(o.input->stack[2].i, 123);
	ASSERT_EQ(o.input->stack[3].i, 123);
	ASSERT_EQ(o.sp_diff, 3);
    ASSERT_EQ(o.interrupt_code, 0);
	ASSERT_EQ(o.terminate_result, terminate_type::success);
}

TEST(reactor_execution, __push_stack_overflow__) {
	const std::array<csignal, 11> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(123)},
		csignal{instruction::push},
		csignal{INT64_C(123)},
		csignal{instruction::push},
		csignal{INT64_C(123)},
		csignal{instruction::push},
		csignal{INT64_C(123)},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
	};
	// only can use 3 elements, 1st is reserved:
	std::array<record64, 4> stack{record64::nop_padding()};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	input.stack = stack.data();
	input.stack_size = stack.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 123);
	ASSERT_EQ(o.input->stack[2].i, 123);
	ASSERT_EQ(o.input->stack[3].i, 123);
	ASSERT_EQ(o.sp_diff, 3);
    ASSERT_EQ(o.interrupt_code, interrupt::stack_overflow);
	ASSERT_EQ(o.terminate_result, terminate_type::error);
}

TEST(reactor_execution, __dupl_stack_overflow__) {
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(123)},
		csignal{instruction::dupl},
		csignal{instruction::dupl},
		csignal{instruction::dupl},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
	};
	// only can use 3 elements, 1st is reserved:
	std::array<record64, 4> stack{record64::nop_padding()};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	input.stack = stack.data();
	input.stack_size = stack.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 123);
	ASSERT_EQ(o.input->stack[2].i, 123);
	ASSERT_EQ(o.input->stack[3].i, 123);
	ASSERT_EQ(o.sp_diff, 3);
    ASSERT_EQ(o.interrupt_code, interrupt::stack_overflow);
	ASSERT_EQ(o.terminate_result, terminate_type::error);
}

TEST(reactor_execution, __dupl2_stack_overflow__) {
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(123)},
		csignal{instruction::dupl2},
		csignal{instruction::dupl2},
		csignal{instruction::dupl2},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
	};
	// only can use 3 elements, 1st is reserved:
	std::array<record64, 4> stack{record64::nop_padding()};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	input.stack = stack.data();
	input.stack_size = stack.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 123);
	ASSERT_EQ(o.input->stack[2].i, 123);
	ASSERT_EQ(o.input->stack[3].i, 123);
	ASSERT_EQ(o.sp_diff, 3);
    ASSERT_EQ(o.interrupt_code, interrupt::stack_overflow);
	ASSERT_EQ(o.terminate_result, terminate_type::error);
}

TEST(reactor_execution, __cintrin__) {
	static constinit int calls;
	std::array<intrinsic_routine*, 3> custom_intrinsics{
		+[](record64*) -> bool {
			++calls;
			return true;
		},
		+[](record64* sp_) -> bool {
			(*++sp_).f = 3.223;
			(*++sp_).c = ':';
			(*++sp_).c = ')';
			++calls;
			return true;
		},
		+[](record64*) -> bool {
			++calls;
			return true;
		},
	};
	const std::array<csignal, 11> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.12345},
		csignal{instruction::cintrin},
		csignal{UINT64_C(0)},
		csignal{instruction::cintrin},
		csignal{UINT64_C(1)},
		csignal{instruction::cintrin},
		csignal{UINT64_C(2)},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
	};
	std::array<record64, 6> stack{ record64::nop_padding() };
	auto input{ default_test_input };
	input.stack = stack.data();
	input.stack_size = stack.size();
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	input.intrinsic_table = custom_intrinsics.data();
	input.intrinsic_table_size = custom_intrinsics.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{ execute_reactor(input) };
	ASSERT_EQ(o.input->stack[1].f, 0.12345);
	ASSERT_EQ(o.input->stack[2].f, 3.223);
	ASSERT_EQ(o.input->stack[3].c, ':');
	ASSERT_EQ(o.input->stack[4].c, ')');
	ASSERT_EQ(o.sp_diff, 1); // pop all!
    ASSERT_EQ(o.interrupt_code, 0);
	ASSERT_EQ(o.terminate_result, terminate_type::success);
	ASSERT_EQ(calls, custom_intrinsics.size());
}

TEST(reactor_execution, __pushz_stack_overflow__) {
	const std::array<csignal, 7> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::pushz},
		csignal{instruction::pushz},
		csignal{instruction::pushz},
		csignal{instruction::pushz},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
	};
	// only can use 3 elements, 1st is reserved:
	std::array<record64, 4> stack{record64::nop_padding()};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	input.stack = stack.data();
	input.stack_size = stack.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 0);
	ASSERT_EQ(o.input->stack[2].i, 0);
	ASSERT_EQ(o.input->stack[3].i, 0);
	ASSERT_EQ(o.sp_diff, 3);
    ASSERT_EQ(o.interrupt_code, interrupt::stack_overflow);
	ASSERT_EQ(o.terminate_result, terminate_type::error);
}

TEST(reactor_execution, __ipusho_stack_overflow__) {
	const std::array<csignal, 7> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::ipusho},
		csignal{instruction::ipusho},
		csignal{instruction::ipusho},
		csignal{instruction::ipusho},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
	};
	// only can use 3 elements, 1st is reserved:
	std::array<record64, 4> stack{record64::nop_padding()};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	input.stack = stack.data();
	input.stack_size = stack.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 1);
	ASSERT_EQ(o.input->stack[2].i, 1);
	ASSERT_EQ(o.input->stack[3].i, 1);
	ASSERT_EQ(o.sp_diff, 3);
    ASSERT_EQ(o.interrupt_code, interrupt::stack_overflow);
	ASSERT_EQ(o.terminate_result, terminate_type::error);
}

TEST(reactor_execution, __fpusho_stack_overflow__) {
	const std::array<csignal, 7> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::fpusho},
		csignal{instruction::fpusho},
		csignal{instruction::fpusho},
		csignal{instruction::fpusho},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
	};
	// only can use 3 elements, 1st is reserved:
	std::array<record64, 4> stack{record64::nop_padding()};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	input.stack = stack.data();
	input.stack_size = stack.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 1.0);
	ASSERT_EQ(o.input->stack[2].f, 1.0);
	ASSERT_EQ(o.input->stack[3].f, 1.0);
	ASSERT_EQ(o.sp_diff, 3);
    ASSERT_EQ(o.interrupt_code, interrupt::stack_overflow);
	ASSERT_EQ(o.terminate_result, terminate_type::error);
}

#endif

TEST(reactor_execution, __pop__) {
	std::array<rt_signal, 9> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(1224)},
		rt_signal{instruction::push},
		rt_signal{-0.6666},
		rt_signal{instruction::pop},
		rt_signal{instruction::pop},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 1224);
	ASSERT_EQ(o.input->stack[2].f, -0.6666);
	ASSERT_EQ(o.sp_diff, 0);

	code[6].instr = instruction::nop;
	o = execute_reactor(input);
	ASSERT_EQ(o.input->stack[1].i, 1224);
	ASSERT_EQ(o.input->stack[2].f, -0.6666);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __pop2__) {
	std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{UINT64_C(1224)},
		rt_signal{instruction::push},
		rt_signal{-0.6666},
		rt_signal{instruction::pop2},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 1224);
	ASSERT_EQ(o.input->stack[2].f, -0.6666);
	ASSERT_EQ(o.sp_diff, 0);
}

TEST(reactor_execution, __dupl__) {
	const std::array<rt_signal, 9> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::dupl},
		rt_signal{instruction::push},
		rt_signal{INT64_C(-2)},
		rt_signal{instruction::dupl},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 5);
	ASSERT_EQ(o.input->stack[2].i, 5);
	ASSERT_EQ(o.input->stack[3].i, -2);
	ASSERT_EQ(o.input->stack[4].i, -2);
}

TEST(reactor_execution, __swap__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(3)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(-666)},
		rt_signal{instruction::swap},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, -666);
	ASSERT_EQ(o.input->stack[2].i, 3);
	ASSERT_EQ(o.sp_diff, 2);
}

TEST(reactor_execution, __dupl2__) {
	const std::array<rt_signal, 9> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::dupl2},
		rt_signal{instruction::push},
		rt_signal{INT64_C(0xFF)},
		rt_signal{instruction::dupl2},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 5);
	ASSERT_EQ(o.input->stack[2].i, 5);
	ASSERT_EQ(o.input->stack[3].i, 5);
	ASSERT_EQ(o.input->stack[4].i, 0xFF);
	ASSERT_EQ(o.input->stack[5].i, 0xFF);
	ASSERT_EQ(o.input->stack[6].i, 0xFF);
}

TEST(reactor_execution, __iinc__) {
	const std::array<rt_signal, 10> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(0)},
		rt_signal{instruction::iinc},
		rt_signal{instruction::iinc},
		rt_signal{instruction::iinc},
		rt_signal{instruction::iinc},
		rt_signal{instruction::iinc},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[0], record64::nop_padding());
	ASSERT_EQ(o.input->stack[1].i, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __idec__) {
	const std::array<rt_signal, 10> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::idec},
		rt_signal{instruction::idec},
		rt_signal{instruction::idec},
		rt_signal{instruction::idec},
		rt_signal{instruction::idec},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);
	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[0], record64::nop_padding());
	ASSERT_EQ(o.input->stack[1].i, -3);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __pushz__) {
	const std::array<rt_signal, 6> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::pushz},
		rt_signal{instruction::pushz},
		rt_signal{instruction::pushz},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 0);
	ASSERT_EQ(o.input->stack[2].u, 0);
	ASSERT_EQ(o.input->stack[3].f, 0.0F);
}

TEST(reactor_execution, __ipusho__) {
	const std::array<rt_signal, 6> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::ipusho},
		rt_signal{instruction::pushz},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 1);
	ASSERT_EQ(o.input->stack[2].u, 0);
	ASSERT_EQ(o.input->stack[3].u, 1);
}

TEST(reactor_execution, __iadd__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::iadd},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 2 + 5);
	ASSERT_EQ(o.input->stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __isub__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::isub},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 2 - 5);
	ASSERT_EQ(o.input->stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __imul__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::imul},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 2 * 5);
	ASSERT_EQ(o.input->stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __idiv__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(10)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::idiv},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 10 / 5);
	ASSERT_EQ(o.input->stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __imod__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(10)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::imod},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 10 % 5);
	ASSERT_EQ(o.input->stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __iand__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(0b1101'1101)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(0b0111'0111)},
		rt_signal{instruction::iand},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 0b1101'1101 & 0b0111'0111);
	ASSERT_EQ(o.input->stack[2].u, 0b0111'0111);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __ior__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(0b1101'1101)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(0b0111'0111)},
		rt_signal{instruction::ior},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 0b1101'1101 | 0b0111'0111);
	ASSERT_EQ(o.input->stack[2].u, 0b0111'0111);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __ixor__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(0b1101'1101)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(0b0111'0111)},
		rt_signal{instruction::ixor},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 0b1101'1101 ^ 0b0111'0111);
	ASSERT_EQ(o.input->stack[2].u, 0b0111'0111);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __icom__) {
	const std::array<rt_signal, 6> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(0b1101'1101)},
		rt_signal{instruction::icom},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, ~0b1101'1101);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __isal__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(1)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::isal},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 1 << 2);
	ASSERT_EQ(o.input->stack[2].u, 2);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __isar__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(1)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::isar},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 1 >> 2);
	ASSERT_EQ(o.input->stack[2].u, 2);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __irol__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(1)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::irol},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].u, std::rotl<u64>(1, 2));
	ASSERT_EQ(o.input->stack[2].u, 2);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __iror__) {
	const std::array<rt_signal, 8> code = {
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(1)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::iror},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].u, std::rotr<u64>(1, 2));
	ASSERT_EQ(o.input->stack[2].u, 2);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __ineg__) {
	const std::array<rt_signal, 6> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(10)},
		rt_signal{instruction::ineg},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, -10);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fadd__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{4.25},
		rt_signal{instruction::push},
		rt_signal{2.50},
		rt_signal{instruction::fadd},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, 6.75);
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 2.50);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fmod_) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{4.25},
		rt_signal{instruction::push},
		rt_signal{2.50},
		rt_signal{instruction::fmod},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, std::fmod(4.25, 2.50));
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 2.50);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fsub__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{4.25},
		rt_signal{instruction::push},
		rt_signal{2.50},
		rt_signal{instruction::fsub},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, 1.75);
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 2.50);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fmul__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{4.25},
		rt_signal{instruction::push},
		rt_signal{2.50},
		rt_signal{instruction::fmul},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, 10.625);
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 2.50);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fdiv__) {
	const std::array<rt_signal, 8> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{4.25},
		rt_signal{instruction::push},
		rt_signal{2.50},
		rt_signal{instruction::fdiv},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, 1.7);
	ASSERT_DOUBLE_EQ(o.input->stack[2].f, 2.50);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fneg__) {
	const std::array<rt_signal, 6> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{2.25},
		rt_signal{instruction::fneg},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, -2.25);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __finc__) {
	const std::array<rt_signal, 10> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{.0},
		rt_signal{instruction::finc},
		rt_signal{instruction::finc},
		rt_signal{instruction::finc},
		rt_signal{instruction::finc},
		rt_signal{instruction::finc},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[0], record64::nop_padding());
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, 5.);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fdec__) {
	const std::array<rt_signal, 10> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::push},
		rt_signal{2.},
		rt_signal{instruction::fdec},
		rt_signal{instruction::fdec},
		rt_signal{instruction::fdec},
		rt_signal{instruction::fdec},
		rt_signal{instruction::fdec},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[0], record64::nop_padding());
	ASSERT_DOUBLE_EQ(o.input->stack[1].f, -3.);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fpusho__) {
	const std::array<rt_signal, 6> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::fpusho},
		rt_signal{instruction::pushz},
		rt_signal{instruction::fpusho},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 1.);
	ASSERT_EQ(o.input->stack[2].u, 0);
	ASSERT_EQ(o.input->stack[3].f, 1.);
}

TEST(reactor_execution, __jmp__) {
	const std::array<rt_signal, 9> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::jmp},
		rt_signal{UINT64_C(5)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(10)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);
	
	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 10);
	ASSERT_EQ(o.ip_diff, 8);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jmprel__) {
	const std::array<rt_signal, 9> code{
		rt_signal{instruction::nop}, // first padding
		rt_signal{instruction::jmprel},
		rt_signal{UINT64_C(3)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(10)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 10);
	ASSERT_EQ(o.ip_diff, 8);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jz__) {
	const std::array<rt_signal, 11> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::pushz},
		rt_signal{instruction::jz},
		rt_signal{UINT64_C(6)},					// first padding does not count
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::jz},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].u, 1);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 10);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jnz__) {
	const std::array<rt_signal, 11> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::ipusho},
		rt_signal{instruction::jnz},
		rt_signal{UINT64_C(6)},					// first padding does not count
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::pushz},
		rt_signal{instruction::jz},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].u, 0);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 10);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jo_cmpi__) {
	const std::array<rt_signal, 11> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::ipusho},
		rt_signal{instruction::jo_cmpi},
		rt_signal{UINT64_C(6)},					// first padding does not count
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::pushz},
		rt_signal{instruction::jo_cmpi},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].u, 0);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 10);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jno_cmpi__) {
	const std::array<rt_signal, 11> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::pushz},
		rt_signal{instruction::jno_cmpi},
		rt_signal{UINT64_C(6)},					// first padding does not count
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::jno_cmpi},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].u, 1);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 10);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jo_cmpf__) {
	const std::array<rt_signal, 11> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::fpusho},
		rt_signal{instruction::jo_cmpf},
		rt_signal{UINT64_C(6)},					// first padding does not count
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::pushz},
		rt_signal{instruction::jo_cmpf},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 0.F);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 10);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jno_cmpf__) {
	const std::array<rt_signal, 11> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::pushz},
		rt_signal{instruction::jno_cmpf},
		rt_signal{UINT64_C(6)},					// first padding does not count
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::fpusho},
		rt_signal{instruction::jno_cmpf},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 1.0);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 10);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __je_cmpi__) {
	const std::array<rt_signal, 16> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(12345679)},
		rt_signal{instruction::dupl},
		rt_signal{instruction::je_cmpi},
		rt_signal{UINT64_C(8)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(123424224)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(0xFF'FF)},
		rt_signal{instruction::je_cmpi},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 123424224);
	ASSERT_EQ(o.input->stack[2].i, 0xFF'FF);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 15);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __je_cmpf__) {
	const std::array<rt_signal, 16> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{1234567.0},
		rt_signal{instruction::dupl},
		rt_signal{instruction::je_cmpf},
		rt_signal{UINT64_C(8)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::push},
		rt_signal{123424224.0},
		rt_signal{instruction::push},
		rt_signal{0.22233},
		rt_signal{instruction::je_cmpf},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 123424224.0);
	ASSERT_EQ(o.input->stack[2].f, 0.22233);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 15);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jne_cmpi__) {
	const std::array<rt_signal, 17> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(1234567)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(213131232)},
		rt_signal{instruction::jne_cmpi},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(0xFF'FF)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(0xFF'FF)},
		rt_signal{instruction::jne_cmpi},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 0xFF'FF);
	ASSERT_EQ(o.input->stack[2].i, 0xFF'FF);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 16);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jne_cmpf__) {
	const std::array<rt_signal, 17> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{1234567.},
		rt_signal{instruction::push},
		rt_signal{213131232.},
		rt_signal{instruction::jne_cmpf},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-1)},
		rt_signal{instruction::push},
		rt_signal{3.1415},
		rt_signal{instruction::push},
		rt_signal{3.1415},
		rt_signal{instruction::jne_cmpf},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 3.1415);
	ASSERT_EQ(o.input->stack[2].f, 3.1415);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 16);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __ja_cmpi__) {
	const std::array<rt_signal, 17> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::ja_cmpi},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(0)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(3)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(53)},
		rt_signal{instruction::ja_cmpi},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 3);
	ASSERT_EQ(o.input->stack[2].i, 53);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 16);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __ja_cmpf__) {
	const std::array<rt_signal, 17> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{5.0},
		rt_signal{instruction::push},
		rt_signal{2.0},
		rt_signal{instruction::ja_cmpf},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(0)},
		rt_signal{instruction::push},
		rt_signal{3.0},
		rt_signal{instruction::push},
		rt_signal{53.0},
		rt_signal{instruction::ja_cmpf},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 3.0);
	ASSERT_EQ(o.input->stack[2].f, 53.0);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 16);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jl_cmpi__) {
	const std::array<rt_signal, 17> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::jl_cmpi},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(0)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(53)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(3)},
		rt_signal{instruction::jl_cmpi},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 53);
	ASSERT_EQ(o.input->stack[2].i, 3);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 16);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jl_cmpf__) {
	const std::array<rt_signal, 17> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{2.0},
		rt_signal{instruction::push},
		rt_signal{5.0},
		rt_signal{instruction::jl_cmpf},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(0)},
		rt_signal{instruction::push},
		rt_signal{53.0},
		rt_signal{instruction::push},
		rt_signal{3.0},
		rt_signal{instruction::jl_cmpf},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 53.0);
	ASSERT_EQ(o.input->stack[2].f, 3.0);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 16);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jae_cmpi__) {
	const std::array<rt_signal, 23> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::jae_cmpi},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-3)},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::jae_cmpi},
		rt_signal{UINT64_C(15)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-5)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(3)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(53)},
		rt_signal{instruction::jae_cmpi},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 3);
	ASSERT_EQ(o.input->stack[2].i, 53);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 22);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jae_cmpf__) {
	const std::array<rt_signal, 23> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{5.0},
		rt_signal{instruction::push},
		rt_signal{2.0},
		rt_signal{instruction::jae_cmpf},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-3)},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::jae_cmpf},
		rt_signal{UINT64_C(15)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-5)},
		rt_signal{instruction::push},
		rt_signal{3.0},
		rt_signal{instruction::push},
		rt_signal{53.0},
		rt_signal{instruction::jae_cmpf},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 3.0);
	ASSERT_EQ(o.input->stack[2].f, 53.0);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 22);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jle_cmpi__) {
	const std::array<rt_signal, 23> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{INT64_C(2)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(5)},
		rt_signal{instruction::jle_cmpi},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-3)},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::jle_cmpi},
		rt_signal{UINT64_C(15)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-5)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(53)},
		rt_signal{instruction::push},
		rt_signal{INT64_C(3)},
		rt_signal{instruction::jle_cmpi},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 53);
	ASSERT_EQ(o.input->stack[2].i, 3);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 22);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_execution, __jle_cmpf__) {
	const std::array<rt_signal, 23> code{
		rt_signal{instruction::nop},		// first padding
		rt_signal{instruction::push},
		rt_signal{2.0},
		rt_signal{instruction::push},
		rt_signal{5.0},
		rt_signal{instruction::jle_cmpf},
		rt_signal{UINT64_C(9)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-3)},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::ipusho},
		rt_signal{instruction::jle_cmpf},
		rt_signal{UINT64_C(15)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-5)},
		rt_signal{instruction::push},
		rt_signal{53.0},
		rt_signal{instruction::push},
		rt_signal{3.0},
		rt_signal{instruction::jle_cmpf},
		rt_signal{UINT64_C(0)},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(-0xFF)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].f, 53.0);
	ASSERT_EQ(o.input->stack[2].f, 3.0);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 22);
    ASSERT_EQ(o.interrupt_code, -0xFF);
}

TEST(reactor_input_validation, valid_pointers) {
	const auto input = reactor_input{
		.signal_status = &signal_status,
		.code_chunk = default_test_code.data(),
		.code_chunk_size = default_test_code.size(),
		.intrinsic_table = test_intrinsic_routine_table.data(),
		.intrinsic_table_size = test_intrinsic_routine_table.size(),
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data(),
		.stack_size = test_stack.size(),
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);
}

TEST(reactor_input_validation, null_pointers) {
	const auto input = reactor_input{
		.signal_status = &signal_status,
		.code_chunk = nullptr,
		.code_chunk_size = 0,
		.intrinsic_table = test_intrinsic_routine_table.data(),
		.intrinsic_table_size = 0,
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data(),
		.stack_size = test_stack.size(),
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::null_ptr);
}

TEST(reactor_input_validation, zero_sizes) {
	const auto input = reactor_input{
		.signal_status = &signal_status,
		.code_chunk = default_test_code.data(),
		.code_chunk_size = 0,
		.intrinsic_table = test_intrinsic_routine_table.data(),
		.intrinsic_table_size = 0,
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data(),
		.stack_size = test_stack.size(),
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::zero_size);
}

TEST(reactor_input_validation, invalid_intrinsic_routines) {
	std::array<intrinsic_routine*, 1> intrinsic_routines{
		nullptr
	};
	const auto input = reactor_input{
		.signal_status = &signal_status,
		.code_chunk = default_test_code.data(),
		.code_chunk_size = default_test_code.size(),
		.intrinsic_table = intrinsic_routines.data(),
		.intrinsic_table_size = intrinsic_routines.size(),
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data(),
		.stack_size = test_stack.size(),
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::null_intrinsic_routine);
}

TEST(reactor_input_validation, valid_intrinsic_routines) {
	const auto input = reactor_input{
		.signal_status = &signal_status,
		.code_chunk = default_test_code.data(),
		.code_chunk_size = default_test_code.size(),
		.intrinsic_table = test_intrinsic_routine_table.data(),
		.intrinsic_table_size = test_intrinsic_routine_table.size(),
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data(),
		.stack_size = test_stack.size(),
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);
}

TEST(reactor_input_validation, missing_code_prologue) {
	const auto input = reactor_input{
		.signal_status = &signal_status,
		.code_chunk = default_test_code.data() + 1,
		.code_chunk_size = default_test_code.size() - 1,
		.intrinsic_table = test_intrinsic_routine_table.data(),
		.intrinsic_table_size = test_intrinsic_routine_table.size(),
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data(),
		.stack_size = test_stack.size(),
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::missing_code_prologue);
}

TEST(reactor_input_validation, missing_code_epilogue$1) {
	constexpr std::array<rt_signal, 3> code = {
		rt_signal{instruction::nop},
		rt_signal{instruction::inter},
		rt_signal{INT64_C(5)},
	};
	
	const auto input = reactor_input{
		.signal_status = &signal_status,
		.code_chunk = code.data(),
		.code_chunk_size = code.size(),
		.intrinsic_table = test_intrinsic_routine_table.data(),
		.intrinsic_table_size = test_intrinsic_routine_table.size(),
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data(),
		.stack_size = test_stack.size(),
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);
}

TEST(reactor_input_validation, missing_code_epilogue$2) {
	constexpr std::array<rt_signal, 1> code = {
		rt_signal{instruction::nop},
	};

	const auto input = reactor_input{
		.signal_status = &signal_status,
		.code_chunk = code.data(),
		.code_chunk_size = code.size(),
		.intrinsic_table = test_intrinsic_routine_table.data(),
		.intrinsic_table_size = test_intrinsic_routine_table.size(),
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data(),
		.stack_size = test_stack.size(),
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::missing_code_epilogue);
}

TEST(reactor_input_validation, missing_code_epilogue$3) {
	constexpr std::array<rt_signal, 2> code = {
		rt_signal{instruction::nop},
		rt_signal{INT64_C(5)},
	};

	const auto input = reactor_input{
		.signal_status = &signal_status,
		.code_chunk = code.data(),
		.code_chunk_size = code.size(),
		.intrinsic_table = test_intrinsic_routine_table.data(),
		.intrinsic_table_size = test_intrinsic_routine_table.size(),
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data(),
		.stack_size = test_stack.size(),
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::missing_code_epilogue);
}

TEST(reactor_input_validation, missing_stack_prologue) {
	const auto input = reactor_input{
		.signal_status = reinterpret_cast<volatile std::sig_atomic_t*>(0xFF),
		.code_chunk = default_test_code.data(),
		.code_chunk_size = default_test_code.size(),
		.intrinsic_table = test_intrinsic_routine_table.data(),
		.intrinsic_table_size = test_intrinsic_routine_table.size(),
		.interrupt_handler = test_interrupt_handler,
		.stack = test_stack.data() + 1,
		.stack_size = test_stack.size() - 1,
		.user_data = nullptr
	};
	ASSERT_EQ(input.validate(), reactor_validation_result::missing_stack_prologue);
}
