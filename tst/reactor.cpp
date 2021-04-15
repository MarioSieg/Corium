#include <array>
#include <numbers>

#include "tstbase.hpp"
#include "../inc/nominax/reactor.hpp"
#include "../inc/nominax/reactor_internals.hpp"
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

static constinit volatile std::sig_atomic_t test_signal_status;

static constinit interrupt_routine* test_interrupt_handler {+[](interrupt_accumulator, void*) noexcept -> bool {
	return true;
}};

static reactor_input default_test_input{
	.test_signal_status = &test_signal_status,
	.code_chunk = nullptr,
	.code_chunk_size = 0,
	.intrinsic_table = test_intrinsic_routine_table.data(),
	.intrinsic_table_size = test_intrinsic_routine_table.size(),
	.interrupt_handler = test_interrupt_handler,
	.stack = test_stack.data(),
	.stack_size = test_stack.size(),
	.user_data = nullptr
};

static constexpr std::array<csignal, 3> default_test_code = {
	csignal{instruction::nop}, // first padding
	csignal{instruction::inter},
	csignal{INT64_C(5)},
};

TEST(reactor_internals, rol) {
	ASSERT_EQ(rol(3, 1), std::rotl<u64>(3, 1));
	ASSERT_EQ(rol(0, 0), std::rotl<u64>(0, 0));
	ASSERT_EQ(rol(1, 1), std::rotl<u64>(1, 1));
}

TEST(reactor_internals, ror) {
	ASSERT_EQ(ror(1, 3), std::rotr<u64>(1, 3));
}

#if NOMINAX_ARCH_X86_32 || NOMINAX_ARCH_X86_64

TEST(reactor_internals, query_pi64_from_x87fpu) {
	ASSERT_DOUBLE_EQ(query_pi64_from_x87fpu(), std::numbers::pi);
}

TEST(reactor_internals, query_pi32_from_x87fpu) {
	ASSERT_DOUBLE_EQ(query_pi32_from_x87fpu(), std::numbers::pi_v<f32>);
}

#endif

TEST(reactor_execution, __intrin__$cos) {
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::cos},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::sin},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::tan},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::acos},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::asin},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::atan},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 9> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::push},
		csignal{0.15},
		csignal{instruction::intrin},
		csignal{intrinsic::atan2},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::cosh},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::sinh},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::tanh},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{1.6},
		csignal{instruction::intrin},
		csignal{intrinsic::acosh},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::asinh},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::atanh},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::exp},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::log},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::log10},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::exp2},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{1.332},
		csignal{instruction::intrin},
		csignal{intrinsic::ilogb},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::log2},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 9> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::push},
		csignal{0.15},
		csignal{instruction::intrin},
		csignal{intrinsic::pow},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::sqrt},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::cbrt},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 9> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::push},
		csignal{0.15},
		csignal{instruction::intrin},
		csignal{intrinsic::hypot},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::ceil},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::floor},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::round},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::rint},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 9> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(4)},
		csignal{instruction::push},
		csignal{INT64_C(7)},
		csignal{instruction::intrin},
		csignal{intrinsic::max},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 9> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(4)},
		csignal{instruction::push},
		csignal{INT64_C(7)},
		csignal{instruction::intrin},
		csignal{intrinsic::min},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 9> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::push},
		csignal{0.15},
		csignal{instruction::intrin},
		csignal{intrinsic::fmax},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 9> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::push},
		csignal{0.15},
		csignal{instruction::intrin},
		csignal{intrinsic::fmin},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 9> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::push},
		csignal{0.15},
		csignal{instruction::intrin},
		csignal{intrinsic::fdim},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(223233)},
		csignal{instruction::intrin},
		csignal{intrinsic::abs},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 7> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{0.35},
		csignal{instruction::intrin},
		csignal{intrinsic::fabs},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 5> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::inter},
		csignal{INT64_C(5)},
		csignal{instruction::inter},
		csignal{INT64_C(-12345)},
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
	const std::array<csignal, 9> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::sto},
		csignal{UINT64_C(3)},
		csignal{3.1415},
		csignal{instruction::mov},
		csignal{UINT64_C(8)},
		csignal{UINT64_C(3)},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 9> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::sto},
		csignal{UINT64_C(1)},
		csignal{INT64_C(5657334)},
		csignal{instruction::sto},
		csignal{UINT64_C(31)},
		csignal{3.1415},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 7> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(1224)},
		csignal{instruction::push},
		csignal{-0.6666},
		csignal{instruction::inter},
		csignal{INT64_C(-3)},
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
    ASSERT_EQ(o.interrupt_code, interrupt::er_stack_overflow);
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
    ASSERT_EQ(o.interrupt_code, interrupt::er_stack_overflow);
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
    ASSERT_EQ(o.interrupt_code, interrupt::er_stack_overflow);
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
    ASSERT_EQ(o.interrupt_code, interrupt::er_stack_overflow);
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
    ASSERT_EQ(o.interrupt_code, interrupt::er_stack_overflow);
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
    ASSERT_EQ(o.interrupt_code, interrupt::er_stack_overflow);
	ASSERT_EQ(o.terminate_result, terminate_type::error);
}

#endif

TEST(reactor_execution, __pop__) {
	std::array<csignal, 9> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(1224)},
		csignal{instruction::push},
		csignal{-0.6666},
		csignal{instruction::pop},
		csignal{instruction::pop},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{UINT64_C(1224)},
		csignal{instruction::push},
		csignal{-0.6666},
		csignal{instruction::pop2},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 9> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::dupl},
		csignal{instruction::push},
		csignal{INT64_C(-2)},
		csignal{instruction::dupl},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(3)},
		csignal{instruction::push},
		csignal{INT64_C(-666)},
		csignal{instruction::swap},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 9> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::dupl2},
		csignal{instruction::push},
		csignal{INT64_C(0xFF)},
		csignal{instruction::dupl2},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 10> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(0)},
		csignal{instruction::iinc},
		csignal{instruction::iinc},
		csignal{instruction::iinc},
		csignal{instruction::iinc},
		csignal{instruction::iinc},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 10> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::idec},
		csignal{instruction::idec},
		csignal{instruction::idec},
		csignal{instruction::idec},
		csignal{instruction::idec},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 6> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::pushz},
		csignal{instruction::pushz},
		csignal{instruction::pushz},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 6> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::ipusho},
		csignal{instruction::pushz},
		csignal{instruction::ipusho},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::iadd},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::isub},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::imul},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(10)},
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::idiv},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(10)},
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::imod},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(0b1101'1101)},
		csignal{instruction::push},
		csignal{INT64_C(0b0111'0111)},
		csignal{instruction::iand},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(0b1101'1101)},
		csignal{instruction::push},
		csignal{INT64_C(0b0111'0111)},
		csignal{instruction::ior},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(0b1101'1101)},
		csignal{instruction::push},
		csignal{INT64_C(0b0111'0111)},
		csignal{instruction::ixor},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 6> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(0b1101'1101)},
		csignal{instruction::icom},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(1)},
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::isal},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(1)},
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::isar},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(1)},
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::irol},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code = {
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(1)},
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::iror},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 6> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(10)},
		csignal{instruction::ineg},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{4.25},
		csignal{instruction::push},
		csignal{2.50},
		csignal{instruction::fadd},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{4.25},
		csignal{instruction::push},
		csignal{2.50},
		csignal{instruction::fmod},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{4.25},
		csignal{instruction::push},
		csignal{2.50},
		csignal{instruction::fsub},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{4.25},
		csignal{instruction::push},
		csignal{2.50},
		csignal{instruction::fmul},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{4.25},
		csignal{instruction::push},
		csignal{2.50},
		csignal{instruction::fdiv},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 6> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{2.25},
		csignal{instruction::fneg},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 10> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{.0},
		csignal{instruction::finc},
		csignal{instruction::finc},
		csignal{instruction::finc},
		csignal{instruction::finc},
		csignal{instruction::finc},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 10> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{2.},
		csignal{instruction::fdec},
		csignal{instruction::fdec},
		csignal{instruction::fdec},
		csignal{instruction::fdec},
		csignal{instruction::fdec},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 6> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::fpusho},
		csignal{instruction::pushz},
		csignal{instruction::fpusho},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
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
	const std::array<csignal, 9> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::jmp},
		csignal{UINT64_C(5)},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::push},
		csignal{INT64_C(10)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 9> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::jmprel},
		csignal{UINT64_C(3)},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::push},
		csignal{INT64_C(10)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 11> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::pushz},
		csignal{instruction::jz},
		csignal{UINT64_C(6)},					// first padding does not count
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::ipusho},
		csignal{instruction::jz},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 11> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::ipusho},
		csignal{instruction::jnz},
		csignal{UINT64_C(6)},					// first padding does not count
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::pushz},
		csignal{instruction::jz},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 11> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::ipusho},
		csignal{instruction::jo_cmpi},
		csignal{UINT64_C(6)},					// first padding does not count
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::pushz},
		csignal{instruction::jo_cmpi},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 11> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::pushz},
		csignal{instruction::jno_cmpi},
		csignal{UINT64_C(6)},					// first padding does not count
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::ipusho},
		csignal{instruction::jno_cmpi},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 11> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::fpusho},
		csignal{instruction::jo_cmpf},
		csignal{UINT64_C(6)},					// first padding does not count
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::pushz},
		csignal{instruction::jo_cmpf},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 11> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::pushz},
		csignal{instruction::jno_cmpf},
		csignal{UINT64_C(6)},					// first padding does not count
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::fpusho},
		csignal{instruction::jno_cmpf},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 16> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{INT64_C(12345679)},
		csignal{instruction::dupl},
		csignal{instruction::je_cmpi},
		csignal{UINT64_C(8)},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::push},
		csignal{INT64_C(123424224)},
		csignal{instruction::push},
		csignal{INT64_C(0xFF'FF)},
		csignal{instruction::je_cmpi},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 16> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{1234567.0},
		csignal{instruction::dupl},
		csignal{instruction::je_cmpf},
		csignal{UINT64_C(8)},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::push},
		csignal{123424224.0},
		csignal{instruction::push},
		csignal{0.22233},
		csignal{instruction::je_cmpf},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 17> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{INT64_C(1234567)},
		csignal{instruction::push},
		csignal{INT64_C(213131232)},
		csignal{instruction::jne_cmpi},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::push},
		csignal{INT64_C(0xFF'FF)},
		csignal{instruction::push},
		csignal{INT64_C(0xFF'FF)},
		csignal{instruction::jne_cmpi},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 17> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{1234567.},
		csignal{instruction::push},
		csignal{213131232.},
		csignal{instruction::jne_cmpf},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(-1)},
		csignal{instruction::push},
		csignal{3.1415},
		csignal{instruction::push},
		csignal{3.1415},
		csignal{instruction::jne_cmpf},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 17> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::ja_cmpi},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
		csignal{instruction::push},
		csignal{INT64_C(3)},
		csignal{instruction::push},
		csignal{INT64_C(53)},
		csignal{instruction::ja_cmpi},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 17> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{5.0},
		csignal{instruction::push},
		csignal{2.0},
		csignal{instruction::ja_cmpf},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
		csignal{instruction::push},
		csignal{3.0},
		csignal{instruction::push},
		csignal{53.0},
		csignal{instruction::ja_cmpf},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 17> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::jl_cmpi},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
		csignal{instruction::push},
		csignal{INT64_C(53)},
		csignal{instruction::push},
		csignal{INT64_C(3)},
		csignal{instruction::jl_cmpi},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 17> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{2.0},
		csignal{instruction::push},
		csignal{5.0},
		csignal{instruction::jl_cmpf},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(0)},
		csignal{instruction::push},
		csignal{53.0},
		csignal{instruction::push},
		csignal{3.0},
		csignal{instruction::jl_cmpf},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 23> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::jae_cmpi},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(-3)},
		csignal{instruction::ipusho},
		csignal{instruction::ipusho},
		csignal{instruction::jae_cmpi},
		csignal{UINT64_C(15)},
		csignal{instruction::inter},
		csignal{INT64_C(-5)},
		csignal{instruction::push},
		csignal{INT64_C(3)},
		csignal{instruction::push},
		csignal{INT64_C(53)},
		csignal{instruction::jae_cmpi},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 23> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{5.0},
		csignal{instruction::push},
		csignal{2.0},
		csignal{instruction::jae_cmpf},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(-3)},
		csignal{instruction::ipusho},
		csignal{instruction::ipusho},
		csignal{instruction::jae_cmpf},
		csignal{UINT64_C(15)},
		csignal{instruction::inter},
		csignal{INT64_C(-5)},
		csignal{instruction::push},
		csignal{3.0},
		csignal{instruction::push},
		csignal{53.0},
		csignal{instruction::jae_cmpf},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 23> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{INT64_C(2)},
		csignal{instruction::push},
		csignal{INT64_C(5)},
		csignal{instruction::jle_cmpi},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(-3)},
		csignal{instruction::ipusho},
		csignal{instruction::ipusho},
		csignal{instruction::jle_cmpi},
		csignal{UINT64_C(15)},
		csignal{instruction::inter},
		csignal{INT64_C(-5)},
		csignal{instruction::push},
		csignal{INT64_C(53)},
		csignal{instruction::push},
		csignal{INT64_C(3)},
		csignal{instruction::jle_cmpi},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
	const std::array<csignal, 23> code{
		csignal{instruction::nop},		// first padding
		csignal{instruction::push},
		csignal{2.0},
		csignal{instruction::push},
		csignal{5.0},
		csignal{instruction::jle_cmpf},
		csignal{UINT64_C(9)},
		csignal{instruction::inter},
		csignal{INT64_C(-3)},
		csignal{instruction::ipusho},
		csignal{instruction::ipusho},
		csignal{instruction::jle_cmpf},
		csignal{UINT64_C(15)},
		csignal{instruction::inter},
		csignal{INT64_C(-5)},
		csignal{instruction::push},
		csignal{53.0},
		csignal{instruction::push},
		csignal{3.0},
		csignal{instruction::jle_cmpf},
		csignal{UINT64_C(0)},
		csignal{instruction::inter},
		csignal{INT64_C(-0xFF)},
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
		.test_signal_status = &test_signal_status,
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
		.test_signal_status = &test_signal_status,
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
		.test_signal_status = &test_signal_status,
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
		.test_signal_status = &test_signal_status,
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
		.test_signal_status = &test_signal_status,
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
		.test_signal_status = &test_signal_status,
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
	constexpr std::array<csignal, 3> code = {
		csignal{instruction::nop},
		csignal{instruction::inter},
		csignal{INT64_C(5)},
	};
	
	const auto input = reactor_input{
		.test_signal_status = &test_signal_status,
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
	constexpr std::array<csignal, 1> code = {
		csignal{instruction::nop},
	};

	const auto input = reactor_input{
		.test_signal_status = &test_signal_status,
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
	constexpr std::array<csignal, 2> code = {
		csignal{instruction::nop},
		csignal{INT64_C(5)},
	};

	const auto input = reactor_input{
		.test_signal_status = &test_signal_status,
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
		.test_signal_status = reinterpret_cast<volatile std::sig_atomic_t*>(0xFF),
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
