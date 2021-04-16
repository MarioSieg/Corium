#include "tstbase.hpp"
#include "../inc/nominax/reactor.hpp"

using namespace nominax;

TEST(instruction_db, imm_max_arg_count) {
	const auto max_imm_args = idb::max_imm_args;
	for (const auto val : idb::imm_arg_counts) {
		ASSERT_LE(val, max_imm_args);
	}
}

TEST(instruction_db, imm_arg_count) {
	ASSERT_EQ(idb::imm_arg_counts.size(), idb::imm_arg_types.size());
	for (std::size_t i = 0; i < idb::imm_arg_counts.size(); ++i) {
		std::uint8_t count = 0;
		for (const auto x : idb::imm_arg_types[i]) {
			count += x != idb::instruction_imm_arg_type::none;
		}
		ASSERT_EQ(count, idb::imm_arg_counts[i]);
	}
}

TEST(bytecode_elements, instruction_data) {
	const auto x = bytecode_element{instruction::cintrin};
	ASSERT_TRUE(x.contains<instruction>());
	ASSERT_TRUE(x.contains(instruction::cintrin));
}

TEST(bytecode_elements, intrinsic_data) {
	const auto x = bytecode_element{intrinsic::atan2};
	ASSERT_TRUE(x.contains<intrinsic>());
	ASSERT_TRUE(x.contains(intrinsic::atan2));
}

TEST(bytecode_elements, cintrinsic_data) {
	const auto x = bytecode_element{cintrinsic{233113}};
	ASSERT_TRUE(x.contains<cintrinsic>());
	ASSERT_TRUE(x.contains(cintrinsic{233113}));
}

TEST(bytecode_elements, u64_data) {
	const auto x = bytecode_element{UINT64_C(12345)};
	ASSERT_TRUE(x.contains<u64>());
	ASSERT_TRUE(x.contains(UINT64_C(12345)));
}

TEST(bytecode_elements, i64_data) {
	const auto x = bytecode_element{INT64_C(-12345)};
	ASSERT_TRUE(x.contains<i64>());
	ASSERT_TRUE(x.contains(INT64_C(-12345)));
}

TEST(bytecode_elements, f64_data) {
	const auto x = bytecode_element{12345.0};
	ASSERT_TRUE(x.contains<f64>());
	ASSERT_TRUE(x.contains(12345.0));
}

TEST(bytecode_elements, c32_data) {
	const auto x = bytecode_element{static_cast<c32>('A')};
	ASSERT_TRUE(x.contains<c32>());
	ASSERT_TRUE(x.contains(static_cast<c32>('A')));
}

TEST(bytecode_elements, instruction_data_cvt_sig) {
	const auto x = static_cast<csignal>(bytecode_element{instruction::cintrin});
	ASSERT_EQ(x.instr, instruction::cintrin);
}

TEST(bytecode_elements, intrinsic_data_cvt_sig) {
	const auto x = static_cast<csignal>(bytecode_element{intrinsic::atan2});
	ASSERT_EQ(x.intrin, intrinsic::atan2);
}

TEST(bytecode_elements, cintrinsic_data_cvt_sig) {
	const auto x = static_cast<csignal>(bytecode_element{cintrinsic{4}});
	ASSERT_EQ(x.cintrin, cintrinsic{4});
}

TEST(bytecode_elements, u64_data_cvt_sig) {
	const auto x = static_cast<csignal>(bytecode_element{UINT64_C(0xFF'FF'FF'FF'FF'FF'FF'FF)});
	ASSERT_EQ(x.r64.u, 0xFF'FF'FF'FF'FF'FF'FF'FF);
}

TEST(bytecode_elements, i64_data_cvt_sig) {
	const auto x = static_cast<csignal>(bytecode_element{INT64_C(-0x80'FF'FF'FF'FF'FF'FF'FF)});
	ASSERT_EQ(x.r64.i, -0x80'FF'FF'FF'FF'FF'FF'FF);
}

TEST(bytecode_elements, f64_data_cvt_sig) {
	const auto x = static_cast<csignal>(bytecode_element{std::numeric_limits<f64>::max()});
	ASSERT_EQ(x.r64.f, std::numeric_limits<f64>::max());
}

TEST(bytecode_elements, c32_data_cvt_sig) {
	const auto x = static_cast<csignal>(bytecode_element{static_cast<c32>('X')});
	ASSERT_EQ(x.r64.c, 'X');
}
