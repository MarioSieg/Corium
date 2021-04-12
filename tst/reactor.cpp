#include <array>

#include "tstbase.hpp"
#include "../inc/nominax/reactor.hpp"
#include "../inc/nominax/reactor_internals.hpp"

using namespace nominax;

static constexpr intrinsic_routine* test_intrinsic_routine{+[]() noexcept -> bool {
	return true;
}};

static constinit std::array<intrinsic_routine*, 3> test_intrinsic_routine_table{
	test_intrinsic_routine,
	test_intrinsic_routine,
	test_intrinsic_routine
};

static constexpr auto test_stack_size = 32; // 32 records

static constinit std::array<record64, test_stack_size> test_stack{record64::nop_padding()};

static constinit volatile std::sig_atomic_t test_signal_status;

static constinit interrupt_routine* test_interrupt_handler{+[](interrupt_accumulator, void*) noexcept -> bool {
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
	ASSERT_EQ(o.interrupt, -12345);
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
	ASSERT_EQ(o.interrupt, 0);
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
	ASSERT_EQ(o.interrupt, interrupt::er_stack_overflow);
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
	ASSERT_EQ(o.interrupt, interrupt::er_stack_overflow);
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
	ASSERT_EQ(o.interrupt, interrupt::er_stack_overflow);
	ASSERT_EQ(o.terminate_result, terminate_type::error);
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
	ASSERT_EQ(o.interrupt, interrupt::er_stack_overflow);
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
	ASSERT_EQ(o.interrupt, interrupt::er_stack_overflow);
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
	ASSERT_EQ(o.interrupt, interrupt::er_stack_overflow);
	ASSERT_EQ(o.terminate_result, terminate_type::error);
}

#endif

TEST(reactor_execution, __pop__) {
	std::array<csignal, 9> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{INT64_C(1224)},
		csignal{instruction::push},
		csignal{-0.6666F},
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
	ASSERT_EQ(o.input->stack[2].f, -0.6666F);
	ASSERT_EQ(o.sp_diff, 0);

	code[6].instr = instruction::nop;
	o = execute_reactor(input);
	ASSERT_EQ(o.input->stack[1].i, 1224);
	ASSERT_EQ(o.input->stack[2].f, -0.6666F);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __pop2__) {
	std::array<csignal, 8> code{
		csignal{instruction::nop}, // first padding
		csignal{instruction::push},
		csignal{UINT64_C(1224)},
		csignal{instruction::push},
		csignal{-0.6666F},
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
	ASSERT_EQ(o.input->stack[2].f, -0.6666F);
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
	ASSERT_EQ(o.input->stack[1].f, 6.75);
	ASSERT_EQ(o.input->stack[2].f, 2.50);
	ASSERT_EQ(o.sp_diff, 1);
}

// TODO: FMOD

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
	ASSERT_EQ(o.input->stack[1].f, 1.75);
	ASSERT_EQ(o.input->stack[2].f, 2.50);
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
	ASSERT_EQ(o.input->stack[1].f, 10.625);
	ASSERT_EQ(o.input->stack[2].f, 2.50);
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
	ASSERT_EQ(o.input->stack[1].f, 1.7);
	ASSERT_EQ(o.input->stack[2].f, 2.50);
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
	ASSERT_EQ(o.input->stack[1].f, -2.25);
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
	ASSERT_EQ(o.input->stack[1].f, 5.);
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
	ASSERT_EQ(o.input->stack[1].f, -3.);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
	ASSERT_EQ(o.interrupt, -0xFF);
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
