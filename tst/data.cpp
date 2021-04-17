#include "TestBase.hpp"

TEST(ReactorAggregates, UnionReinterpretation) {
	Record64 rec{
		UINT64_C(0xFF'FF'FF'FF)
	};
	ASSERT_EQ(rec.U64, 0xFF'FF'FF'FF);
	
	rec.I64 = -1234;
	ASSERT_EQ(rec.I64, -1234);
	
	rec.F64 = 3.14;
	ASSERT_EQ(rec.F64, 3.14);

	rec.C32 = '!';
	ASSERT_EQ(rec.C32, '!');

	rec.Ptr = &rec;
	ASSERT_EQ(rec.Ptr, &rec);

	constexpr Signal sig{
		Instruction::Mov
	};
	ASSERT_EQ(sig.Instr, Instruction::Mov);
	ASSERT_EQ(sig.OpCode, static_cast<std::uint64_t>(Instruction::Mov));
	ASSERT_EQ(sig.R64.U64, static_cast<std::uint64_t>(Instruction::Mov));
}