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

static constinit std::array<record32, test_stack_size> test_stack{rec_nop_padding};

static constinit volatile std::sig_atomic_t test_signal_status;

static constinit interrupt_routine* test_interrupt_handler{+[](interrupt_accumulator, volatile std::sig_atomic_t&, void*) noexcept -> bool {
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

static constexpr std::array<signal32, 3> default_test_code = {
	signal32{instruction::nop}, // first padding
	signal32{instruction::inter},
	signal32{5},
};

TEST(reactor_internals, rol) {
	ASSERT_EQ(rol(3, 1), std::rotl<u32>(3, 1));
	ASSERT_EQ(rol(0, 0), std::rotl<u32>(0, 0));
	ASSERT_EQ(rol(1, 1), std::rotl<u32>(1, 1));
}

TEST(reactor_internals, ror) {
	ASSERT_EQ(ror(1, 3), std::rotr<u32>(1, 3));
}

TEST(reactor_execution, __int__) {
	const std::array<signal32, 5> code = {
		signal32{instruction::nop}, // first padding
		signal32{instruction::inter},
		signal32{5},
		signal32{instruction::inter},
		signal32{-12345},
	};

	auto input{default_test_input};

	int user{1234567};
	input.user_data = &user;

	static constinit interrupt_accumulator accum;
	static constinit void* usr;
	static constinit int calls;

	input.interrupt_handler = +[](const interrupt_accumulator x, volatile std::sig_atomic_t&, void* const y) noexcept -> bool {
		accum = x;
		usr = y;
		++calls;
		return true;
	};

	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(calls, 1);
	ASSERT_EQ(accum, 5);
	ASSERT_TRUE(usr != nullptr);
	ASSERT_EQ(*static_cast<int*>(usr), 1234567);
	ASSERT_EQ(*static_cast<int*>(o.input.user_data), 1234567);
	ASSERT_EQ(o.interrupt, -12345);
	ASSERT_EQ(o.ip_diff, code.size() - 1);
}

TEST(reactor_execution, __mov__) {
	const std::array<signal32, 9> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::sto},
		signal32{3},
		signal32{3.1415F},
		signal32{instruction::mov},
		signal32{8},
		signal32{3},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[3].f, 3.1415F);
	ASSERT_EQ(o.input.stack[8].f, 3.1415F);
}

TEST(reactor_execution, __sto__) {
	const std::array<signal32, 9> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::sto},
		signal32{1},
		signal32{5657334},
		signal32{instruction::sto},
		signal32{31},
		signal32{3.1415F},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 5657334);
	ASSERT_EQ(o.input.stack[31].f, 3.1415F);
}

TEST(reactor_execution, __push__) {
	const std::array<signal32, 7> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{1224},
		signal32{instruction::push},
		signal32{-0.6666F},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 1224);
	ASSERT_EQ(o.input.stack[2].f, -0.6666F);
}

TEST(reactor_execution, __pop__) {
	std::array<signal32, 9> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{1224},
		signal32{instruction::push},
		signal32{-0.6666F},
		signal32{instruction::pop},
		signal32{instruction::pop},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 1224);
	ASSERT_EQ(o.input.stack[2].f, -0.6666F);
	ASSERT_EQ(o.sp_diff, 0);

	code[6].instr = instruction::nop;
	o = execute_reactor(input);
	ASSERT_EQ(o.input.stack[1].i, 1224);
	ASSERT_EQ(o.input.stack[2].f, -0.6666F);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __pop2__) {
	std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{1224},
		signal32{instruction::push},
		signal32{-0.6666F},
		signal32{instruction::pop2},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 1224);
	ASSERT_EQ(o.input.stack[2].f, -0.6666F);
	ASSERT_EQ(o.sp_diff, 0);
}

TEST(reactor_execution, __dupl__) {
	const std::array<signal32, 9> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{5},
		signal32{instruction::dupl},
		signal32{instruction::push},
		signal32{-2},
		signal32{instruction::dupl},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 5);
	ASSERT_EQ(o.input.stack[2].i, 5);
	ASSERT_EQ(o.input.stack[3].i, -2);
	ASSERT_EQ(o.input.stack[4].i, -2);
}

TEST(reactor_execution, __dupl2__) {
	const std::array<signal32, 9> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{5},
		signal32{instruction::dupl2},
		signal32{instruction::push},
		signal32{0xFF},
		signal32{instruction::dupl2},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 5);
	ASSERT_EQ(o.input.stack[2].i, 5);
	ASSERT_EQ(o.input.stack[3].i, 5);
	ASSERT_EQ(o.input.stack[4].i, 0xFF);
	ASSERT_EQ(o.input.stack[5].i, 0xFF);
	ASSERT_EQ(o.input.stack[6].i, 0xFF);
}

TEST(reactor_execution, __iinc__) {
	const std::array<signal32, 10> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{0},
		signal32{instruction::iinc},
		signal32{instruction::iinc},
		signal32{instruction::iinc},
		signal32{instruction::iinc},
		signal32{instruction::iinc},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[0], rec_nop_padding);
	ASSERT_EQ(o.input.stack[1].i, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __idec__) {
	const std::array<signal32, 10> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{2},
		signal32{instruction::idec},
		signal32{instruction::idec},
		signal32{instruction::idec},
		signal32{instruction::idec},
		signal32{instruction::idec},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);
	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[0], rec_nop_padding);
	ASSERT_EQ(o.input.stack[1].i, -3);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __pushz__) {
	const std::array<signal32, 6> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::ipushz},
		signal32{instruction::ipushz},
		signal32{instruction::ipushz},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 0);
	ASSERT_EQ(o.input.stack[2].u, 0);
	ASSERT_EQ(o.input.stack[3].f, 0.0F);
}

TEST(reactor_execution, __ipusho__) {
	const std::array<signal32, 6> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::ipusho},
		signal32{instruction::ipushz},
		signal32{instruction::ipusho},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 1);
	ASSERT_EQ(o.input.stack[2].u, 0);
	ASSERT_EQ(o.input.stack[3].u, 1);
}

TEST(reactor_execution, __iadd__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{2},
		signal32{instruction::push},
		signal32{5},
		signal32{instruction::iadd},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 2 + 5);
	ASSERT_EQ(o.input.stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __isub__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{2},
		signal32{instruction::push},
		signal32{5},
		signal32{instruction::isub},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 2 - 5);
	ASSERT_EQ(o.input.stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __imul__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{2},
		signal32{instruction::push},
		signal32{5},
		signal32{instruction::imul},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 2 * 5);
	ASSERT_EQ(o.input.stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __idiv__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{10},
		signal32{instruction::push},
		signal32{5},
		signal32{instruction::idiv},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 10 / 5);
	ASSERT_EQ(o.input.stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __imod__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{10},
		signal32{instruction::push},
		signal32{5},
		signal32{instruction::imod},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 10 % 5);
	ASSERT_EQ(o.input.stack[2].u, 5);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __iand__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{0b1101'1101},
		signal32{instruction::push},
		signal32{0b0111'0111},
		signal32{instruction::iand},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 0b1101'1101 & 0b0111'0111);
	ASSERT_EQ(o.input.stack[2].u, 0b0111'0111);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __ior__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{0b1101'1101},
		signal32{instruction::push},
		signal32{0b0111'0111},
		signal32{instruction::ior},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 0b1101'1101 | 0b0111'0111);
	ASSERT_EQ(o.input.stack[2].u, 0b0111'0111);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __ixor__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{0b1101'1101},
		signal32{instruction::push},
		signal32{0b0111'0111},
		signal32{instruction::ixor},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 0b1101'1101 ^ 0b0111'0111);
	ASSERT_EQ(o.input.stack[2].u, 0b0111'0111);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __icom__) {
	const std::array<signal32, 6> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{0b1101'1101},
		signal32{instruction::icom},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, ~0b1101'1101);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __isal__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{1},
		signal32{instruction::push},
		signal32{2},
		signal32{instruction::isal},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 1 << 2);
	ASSERT_EQ(o.input.stack[2].u, 2);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __isar__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{1},
		signal32{instruction::push},
		signal32{2},
		signal32{instruction::isar},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 1 >> 2);
	ASSERT_EQ(o.input.stack[2].u, 2);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __irol__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{1},
		signal32{instruction::push},
		signal32{2},
		signal32{instruction::irol},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].u, std::rotl<u32>(1, 2));
	ASSERT_EQ(o.input.stack[2].u, 2);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __iror__) {
	const std::array<signal32, 8> code = {
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{1},
		signal32{instruction::push},
		signal32{2},
		signal32{instruction::iror},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].u, std::rotr<u32>(1, 2));
	ASSERT_EQ(o.input.stack[2].u, 2);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __ineg__) {
	const std::array<signal32, 6> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{10},
		signal32{instruction::ineg},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, -10);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fadd__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{4.25F},
		signal32{instruction::push},
		signal32{2.50F},
		signal32{instruction::fadd},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].f, 6.75F);
	ASSERT_EQ(o.input.stack[2].f, 2.50F);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fsub__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{4.25F},
		signal32{instruction::push},
		signal32{2.50F},
		signal32{instruction::fsub},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].f, 1.75F);
	ASSERT_EQ(o.input.stack[2].f, 2.50F);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fmul__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{4.25F},
		signal32{instruction::push},
		signal32{2.50F},
		signal32{instruction::fmul},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].f, 10.625F);
	ASSERT_EQ(o.input.stack[2].f, 2.50F);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fdiv__) {
	const std::array<signal32, 8> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{4.25F},
		signal32{instruction::push},
		signal32{2.50F},
		signal32{instruction::fdiv},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].f, 1.7F);
	ASSERT_EQ(o.input.stack[2].f, 2.50F);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fneg__) {
	const std::array<signal32, 6> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{2.25F},
		signal32{instruction::fneg},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].f, -2.25F);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __finc__) {
	const std::array<signal32, 10> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{.0F},
		signal32{instruction::finc},
		signal32{instruction::finc},
		signal32{instruction::finc},
		signal32{instruction::finc},
		signal32{instruction::finc},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[0], rec_nop_padding);
	ASSERT_EQ(o.input.stack[1].f, 5.F);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fdec__) {
	const std::array<signal32, 10> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::push},
		signal32{2.F},
		signal32{instruction::fdec},
		signal32{instruction::fdec},
		signal32{instruction::fdec},
		signal32{instruction::fdec},
		signal32{instruction::fdec},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[0], rec_nop_padding);
	ASSERT_EQ(o.input.stack[1].f, -3.F);
	ASSERT_EQ(o.sp_diff, 1);
}

TEST(reactor_execution, __fpusho__) {
	const std::array<signal32, 6> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::fpusho},
		signal32{instruction::ipushz},
		signal32{instruction::fpusho},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].f, 1.F);
	ASSERT_EQ(o.input.stack[2].u, 0);
	ASSERT_EQ(o.input.stack[3].f, 1.F);
}

TEST(reactor_execution, __jmp__) {
	const std::array<signal32, 9> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::jmp},
		signal32{5U},
		signal32{instruction::inter},
		signal32{-1},
		signal32{instruction::push},
		signal32{10},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);
	
	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 10);
	ASSERT_EQ(o.ip_diff, 8);
}

TEST(reactor_execution, __jmprel__) {
	const std::array<signal32, 9> code{
		signal32{instruction::nop}, // first padding
		signal32{instruction::jmprel},
		signal32{3U},
		signal32{instruction::inter},
		signal32{-1},
		signal32{instruction::push},
		signal32{10},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].i, 10);
	ASSERT_EQ(o.ip_diff, 8);
}

TEST(reactor_execution, __jz__) {
	const std::array<signal32, 11> code{
		signal32{instruction::nop},		// first padding
		signal32{instruction::ipushz},
		signal32{instruction::jz},
		signal32{6U},					// first padding does not count
		signal32{instruction::inter},
		signal32{-1},
		signal32{instruction::ipusho},
		signal32{instruction::jz},
		signal32{0U},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].u, 1);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 10);
}

TEST(reactor_execution, __jnz__) {
	const std::array<signal32, 11> code{
		signal32{instruction::nop},		// first padding
		signal32{instruction::ipusho},
		signal32{instruction::jnz},
		signal32{6U},					// first padding does not count
		signal32{instruction::inter},
		signal32{-1},
		signal32{instruction::ipushz},
		signal32{instruction::jz},
		signal32{9U},
		signal32{instruction::inter},
		signal32{-1},
	};
	auto input{default_test_input};
	input.code_chunk = code.data();
	input.code_chunk_size = code.size();
	ASSERT_EQ(input.validate(), reactor_validation_result::ok);

	const auto o{execute_reactor(input)};
	ASSERT_EQ(o.input.stack[1].u, 0);
	ASSERT_EQ(o.sp_diff, 0);
	ASSERT_EQ(o.ip_diff, 10);
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
