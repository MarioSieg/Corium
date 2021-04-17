#include "tstbase.hpp"
#include "../inc/nominax/reactor.hpp"

using namespace Nominax;

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
	const auto x = DynamicSignal{Instruction::cintrin};
	ASSERT_TRUE(x.Contains<Instruction>());
	ASSERT_TRUE(x.Contains(Instruction::cintrin));
}

TEST(bytecode_elements, intrinsic_data) {
	const auto x = DynamicSignal{SystemIntrinsicID::atan2};
	ASSERT_TRUE(x.Contains<SystemIntrinsicID>());
	ASSERT_TRUE(x.Contains(SystemIntrinsicID::atan2));
}

TEST(bytecode_elements, cintrinsic_data) {
	const auto x = DynamicSignal{CustomIntrinsicID{233113}};
	ASSERT_TRUE(x.Contains<CustomIntrinsicID>());
	ASSERT_TRUE(x.Contains(CustomIntrinsicID{233113}));
}

TEST(bytecode_elements, std::uint64_t_data) {
	const auto x = DynamicSignal{UINT64_C(12345)};
	ASSERT_TRUE(x.Contains<std::uint64_t>());
	ASSERT_TRUE(x.Contains(UINT64_C(12345)));
}

TEST(bytecode_elements, std::int64_t_data) {
	const auto x = DynamicSignal{INT64_C(-12345)};
	ASSERT_TRUE(x.Contains<std::int64_t>());
	ASSERT_TRUE(x.Contains(INT64_C(-12345)));
}

TEST(bytecode_elements, double_data) {
	const auto x = DynamicSignal{12345.0};
	ASSERT_TRUE(x.Contains<double>());
	ASSERT_TRUE(x.Contains(12345.0));
}

TEST(bytecode_elements, c32_data) {
	const auto x = DynamicSignal{static_cast<c32>('A')};
	ASSERT_TRUE(x.Contains<c32>());
	ASSERT_TRUE(x.Contains(static_cast<c32>('A')));
}

TEST(bytecode_elements, instruction_data_cvt_sig) {
	const auto x = static_cast<Signal>(DynamicSignal{Instruction::cintrin});
	ASSERT_EQ(x.Instr, Instruction::cintrin);
}

TEST(bytecode_elements, intrinsic_data_cvt_sig) {
	const auto x = static_cast<Signal>(DynamicSignal{SystemIntrinsicID::atan2});
	ASSERT_EQ(x.IntrinID, SystemIntrinsicID::atan2);
}

TEST(bytecode_elements, cintrinsic_data_cvt_sig) {
	const auto x = static_cast<Signal>(DynamicSignal{CustomIntrinsicID{4}});
	ASSERT_EQ(x.CustomIntrinID, CustomIntrinsicID{4});
}

TEST(bytecode_elements, std::uint64_t_data_cvt_sig) {
	const auto x = static_cast<Signal>(DynamicSignal{UINT64_C(0xFF'FF'FF'FF'FF'FF'FF'FF)});
	ASSERT_EQ(x.R64.std::uint64_t, 0xFF'FF'FF'FF'FF'FF'FF'FF);
}

TEST(bytecode_elements, std::int64_t_data_cvt_sig) {
	const auto x = static_cast<Signal>(DynamicSignal{INT64_C(-0x80'FF'FF'FF'FF'FF'FF'FF)});
	ASSERT_EQ(x.R64.std::int64_t, -0x80'FF'FF'FF'FF'FF'FF'FF);
}

TEST(bytecode_elements, double_data_cvt_sig) {
	const auto x = static_cast<Signal>(DynamicSignal{std::numeric_limits<double>::max()});
	ASSERT_EQ(x.R64.double, std::numeric_limits<double>::max());
}

TEST(bytecode_elements, c32_data_cvt_sig) {
	const auto x = static_cast<Signal>(DynamicSignal{static_cast<c32>('X')});
	ASSERT_EQ(x.R64.C32, 'X');
}
