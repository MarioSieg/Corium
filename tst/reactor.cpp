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

static constexpr std::array<signal64, 3> default_test_code = {
	signal64{instruction::nop}, // first padding
	signal64{instruction::inter},
	signal64{INT64_C(5)},
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
	const std::array<signal64, 5> code = {
		signal64{instruction::nop}, // first padding
		signal64{instruction::inter},
		signal64{INT64_C(5)},
		signal64{instruction::inter},
		signal64{INT64_C(-12345)},
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
	const std::array<signal64, 9> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::sto},
		signal64{UINT64_C(3)},
		signal64{3.1415},
		signal64{instruction::mov},
		signal64{UINT64_C(8)},
		signal64{UINT64_C(3)},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 9> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::sto},
		signal64{UINT64_C(1)},
		signal64{INT64_C(5657334)},
		signal64{instruction::sto},
		signal64{UINT64_C(31)},
		signal64{3.1415},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 7> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(1224)},
		signal64{instruction::push},
		signal64{-0.6666},
		signal64{instruction::inter},
		signal64{INT64_C(-3)},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input->stack[1].i, 1224);
	ASSERT_EQ(o.input->stack[2].f, -0.6666);
}

TEST(reactor_execution, __pop__) {
	std::array<signal64, 9> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(1224)},
		signal64{instruction::push},
		signal64{-0.6666F},
		signal64{instruction::pop},
		signal64{instruction::pop},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{UINT64_C(1224)},
		signal64{instruction::push},
		signal64{-0.6666F},
		signal64{instruction::pop2},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 9> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(5)},
		signal64{instruction::dupl},
		signal64{instruction::push},
		signal64{INT64_C(-2)},
		signal64{instruction::dupl},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 9> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(5)},
		signal64{instruction::dupl2},
		signal64{instruction::push},
		signal64{INT64_C(0xFF)},
		signal64{instruction::dupl2},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 10> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(0)},
		signal64{instruction::iinc},
		signal64{instruction::iinc},
		signal64{instruction::iinc},
		signal64{instruction::iinc},
		signal64{instruction::iinc},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 10> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(2)},
		signal64{instruction::idec},
		signal64{instruction::idec},
		signal64{instruction::idec},
		signal64{instruction::idec},
		signal64{instruction::idec},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 6> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::pushz},
		signal64{instruction::pushz},
		signal64{instruction::pushz},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 6> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::ipusho},
		signal64{instruction::pushz},
		signal64{instruction::ipusho},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(2)},
		signal64{instruction::push},
		signal64{INT64_C(5)},
		signal64{instruction::iadd},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(2)},
		signal64{instruction::push},
		signal64{INT64_C(5)},
		signal64{instruction::isub},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(2)},
		signal64{instruction::push},
		signal64{INT64_C(5)},
		signal64{instruction::imul},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(10)},
		signal64{instruction::push},
		signal64{INT64_C(5)},
		signal64{instruction::idiv},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(10)},
		signal64{instruction::push},
		signal64{INT64_C(5)},
		signal64{instruction::imod},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(0b1101'1101)},
		signal64{instruction::push},
		signal64{INT64_C(0b0111'0111)},
		signal64{instruction::iand},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(0b1101'1101)},
		signal64{instruction::push},
		signal64{INT64_C(0b0111'0111)},
		signal64{instruction::ior},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(0b1101'1101)},
		signal64{instruction::push},
		signal64{INT64_C(0b0111'0111)},
		signal64{instruction::ixor},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 6> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(0b1101'1101)},
		signal64{instruction::icom},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(1)},
		signal64{instruction::push},
		signal64{INT64_C(2)},
		signal64{instruction::isal},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(1)},
		signal64{instruction::push},
		signal64{INT64_C(2)},
		signal64{instruction::isar},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(1)},
		signal64{instruction::push},
		signal64{INT64_C(2)},
		signal64{instruction::irol},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code = {
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(1)},
		signal64{instruction::push},
		signal64{INT64_C(2)},
		signal64{instruction::iror},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 6> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{INT64_C(10)},
		signal64{instruction::ineg},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{4.25},
		signal64{instruction::push},
		signal64{2.50},
		signal64{instruction::fadd},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{4.25},
		signal64{instruction::push},
		signal64{2.50},
		signal64{instruction::fsub},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{4.25},
		signal64{instruction::push},
		signal64{2.50},
		signal64{instruction::fmul},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 8> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{4.25},
		signal64{instruction::push},
		signal64{2.50},
		signal64{instruction::fdiv},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 6> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{2.25},
		signal64{instruction::fneg},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 10> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{.0},
		signal64{instruction::finc},
		signal64{instruction::finc},
		signal64{instruction::finc},
		signal64{instruction::finc},
		signal64{instruction::finc},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 10> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::push},
		signal64{2.},
		signal64{instruction::fdec},
		signal64{instruction::fdec},
		signal64{instruction::fdec},
		signal64{instruction::fdec},
		signal64{instruction::fdec},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 6> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::fpusho},
		signal64{instruction::pushz},
		signal64{instruction::fpusho},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
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
	const std::array<signal64, 9> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::jmp},
		signal64{UINT64_C(5)},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::push},
		signal64{INT64_C(10)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 9> code{
		signal64{instruction::nop}, // first padding
		signal64{instruction::jmprel},
		signal64{UINT64_C(3)},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::push},
		signal64{INT64_C(10)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 11> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::pushz},
		signal64{instruction::jz},
		signal64{UINT64_C(6)},					// first padding does not count
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::ipusho},
		signal64{instruction::jz},
		signal64{UINT64_C(0)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 11> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::ipusho},
		signal64{instruction::jnz},
		signal64{UINT64_C(6)},					// first padding does not count
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::pushz},
		signal64{instruction::jz},
		signal64{UINT64_C(9)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 11> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::ipusho},
		signal64{instruction::jo_cmpi},
		signal64{UINT64_C(6)},					// first padding does not count
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::pushz},
		signal64{instruction::jo_cmpi},
		signal64{UINT64_C(0)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 11> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::pushz},
		signal64{instruction::jno_cmpi},
		signal64{UINT64_C(6)},					// first padding does not count
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::ipusho},
		signal64{instruction::jno_cmpi},
		signal64{UINT64_C(0)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 11> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::fpusho},
		signal64{instruction::jo_cmpf},
		signal64{UINT64_C(6)},					// first padding does not count
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::pushz},
		signal64{instruction::jo_cmpf},
		signal64{UINT64_C(0)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 11> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::pushz},
		signal64{instruction::jno_cmpf},
		signal64{UINT64_C(6)},					// first padding does not count
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::fpusho},
		signal64{instruction::jno_cmpf},
		signal64{UINT64_C(0)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 16> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::push},
		signal64{INT64_C(12345679)},
		signal64{instruction::dupl},
		signal64{instruction::je_cmpi},
		signal64{UINT64_C(8)},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::push},
		signal64{INT64_C(123424224)},
		signal64{instruction::push},
		signal64{INT64_C(0xFF'FF)},
		signal64{instruction::je_cmpi},
		signal64{UINT64_C(0)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 16> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::push},
		signal64{1234567.0},
		signal64{instruction::dupl},
		signal64{instruction::je_cmpf},
		signal64{UINT64_C(8)},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::push},
		signal64{123424224.0},
		signal64{instruction::push},
		signal64{0.22233},
		signal64{instruction::je_cmpf},
		signal64{UINT64_C(0)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 17> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::push},
		signal64{INT64_C(1234567)},
		signal64{instruction::push},
		signal64{INT64_C(213131232)},
		signal64{instruction::jne_cmpi},
		signal64{UINT64_C(9)},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::push},
		signal64{INT64_C(0xFF'FF)},
		signal64{instruction::push},
		signal64{INT64_C(0xFF'FF)},
		signal64{instruction::jne_cmpi},
		signal64{UINT64_C(0)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
	const std::array<signal64, 17> code{
		signal64{instruction::nop},		// first padding
		signal64{instruction::push},
		signal64{1234567.},
		signal64{instruction::push},
		signal64{213131232.},
		signal64{instruction::jne_cmpf},
		signal64{UINT64_C(9)},
		signal64{instruction::inter},
		signal64{INT64_C(-1)},
		signal64{instruction::push},
		signal64{3.1415},
		signal64{instruction::push},
		signal64{3.1415},
		signal64{instruction::jne_cmpf},
		signal64{UINT64_C(0)},
		signal64{instruction::inter},
		signal64{INT64_C(-0xFF)},
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
