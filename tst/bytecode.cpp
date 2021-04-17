#include "TestBase.hpp"

TEST(BytecodeInstructionDB, MaximalImmediateArgumentCount) {
	const auto max = INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS;
	for (const auto val : INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS) {
		ASSERT_LE(val, max);
	}
}

TEST(BytecodeInstructionDB, ImmediateArgumentCount) {
	ASSERT_EQ(INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS.size(), INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES.size());
	for (std::size_t i = 0; i < INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS.size(); ++i) {
		std::uint8_t count = 0;
		for (const auto x : INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES[i]) {
			count += x != InstructionImmediateArgumentType::None;
		}
		ASSERT_EQ(count, INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS[i]);
	}
}

TEST(BytecodeDynamicSignal, InstructionData) {
	const auto x = DynamicSignal{Instruction::CIntrin};
	ASSERT_TRUE(x.Contains<Instruction>());
	ASSERT_TRUE(x.Contains(Instruction::CIntrin));
}

TEST(BytecodeDynamicSignal, IntrinsicData) {
	const auto x = DynamicSignal{SystemIntrinsicId::ATan2};
	ASSERT_TRUE(x.Contains<SystemIntrinsicId>());
	ASSERT_TRUE(x.Contains(SystemIntrinsicId::ATan2));
}

TEST(BytecodeDynamicSignal, CustomIntrinsicData) {
	const auto x = DynamicSignal{CustomIntrinsicId{233113}};
	ASSERT_TRUE(x.Contains<CustomIntrinsicId>());
	ASSERT_TRUE(x.Contains(CustomIntrinsicId{233113}));
}

TEST(BytecodeDynamicSignal, U64Data) {
	const auto x = DynamicSignal{UINT64_C(12345)};
	ASSERT_TRUE(x.Contains<std::uint64_t>());
	ASSERT_TRUE(x.Contains(UINT64_C(12345)));
}

TEST(BytecodeDynamicSignal, I64Data) {
	const auto x = DynamicSignal{INT64_C(-12345)};
	ASSERT_TRUE(x.Contains<std::int64_t>());
	ASSERT_TRUE(x.Contains(INT64_C(-12345)));
}

TEST(BytecodeDynamicSignal, F64Data) {
	const auto x = DynamicSignal{12345.0};
	ASSERT_TRUE(x.Contains<double>());
	ASSERT_TRUE(x.Contains(12345.0));
}

TEST(BytecodeDynamicSignal, C32Data) {
	const auto x = DynamicSignal{static_cast<char32_t>('A')};
	ASSERT_TRUE(x.Contains<char32_t>());
	ASSERT_TRUE(x.Contains(static_cast<char32_t>('A')));
}

TEST(BytecodeDynamicSignal, DynamicSignalWithInstructionToSignal) {
	const auto x = static_cast<Signal>(DynamicSignal{Instruction::CIntrin});
	ASSERT_EQ(x.Instr, Instruction::CIntrin);
}

TEST(BytecodeDynamicSignal, DynamicSignalWithIntrinsicToSignal) {
	const auto x = static_cast<Signal>(DynamicSignal{SystemIntrinsicId::ATan2});
	ASSERT_EQ(x.SystemIntrinId, SystemIntrinsicId::ATan2);
}

TEST(BytecodeDynamicSignal, DynamicSignalWithCustomIntrinsicToSignal) {
	const auto x = static_cast<Signal>(DynamicSignal{CustomIntrinsicId{4}});
	ASSERT_EQ(x.CustomIntrinId, CustomIntrinsicId{4});
}

TEST(BytecodeDynamicSignal, DynamicSignalWithU64ToSignal) {
	const auto x = static_cast<Signal>(DynamicSignal{UINT64_C(0xFF'FF'FF'FF'FF'FF'FF'FF)});
	ASSERT_EQ(x.R64.U64, 0xFF'FF'FF'FF'FF'FF'FF'FF);
}

TEST(BytecodeDynamicSignal, DynamicSignalWithI64ToSignal) {
	const auto x = static_cast<Signal>(DynamicSignal{INT64_C(-0x80'FF'FF'FF'FF'FF'FF'FF)});
	ASSERT_EQ(x.R64.I64, -0x80'FF'FF'FF'FF'FF'FF'FF);
}

TEST(BytecodeDynamicSignal, DynamicSignalWithF64ToSignal) {
	const auto x = static_cast<Signal>(DynamicSignal{std::numeric_limits<double>::max()});
	ASSERT_EQ(x.R64.F64, std::numeric_limits<double>::max());
}

TEST(BytecodeDynamicSignal, DynamicSignalWithC32ToSignal) {
	const auto x = static_cast<Signal>(DynamicSignal{static_cast<char32_t>('X')});
	ASSERT_EQ(x.R64.C32, 'X');
}
