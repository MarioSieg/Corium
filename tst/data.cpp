#include "tstbase.hpp"
#include "../inc/nominax/reactor.hpp"

using namespace Nominax;

TEST(reactor_aggregates, union_reinterpretation) {
	Record64 rec{
		UINT64_C(0xFF'FF'FF'FF)
	};
	ASSERT_EQ(rec.std::uint64_t, 0xFF'FF'FF'FF);
	
	rec.std::int64_t = -1234;
	ASSERT_EQ(rec.std::int64_t, -1234);
	
	rec.double = 3.14;
	ASSERT_EQ(rec.double, 3.14);

	rec.C32 = '!';
	ASSERT_EQ(rec.C32, '!');

	rec.Ptr = &rec;
	ASSERT_EQ(rec.Ptr, &rec);

	constexpr Signal sig{
		Instruction::mov
	};
	ASSERT_EQ(sig.Instr, Instruction::mov);
	ASSERT_EQ(sig.OpCode, static_cast<std::uint64_t>(Instruction::mov));
	ASSERT_EQ(sig.R64.std::uint64_t, static_cast<std::uint64_t>(Instruction::mov));
}