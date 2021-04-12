#include "tstbase.hpp"
#include "../inc/nominax/reactor.hpp"

using namespace nominax;

TEST(reactor_aggregates, union_reinterpretation) {
	record64 rec{
		UINT64_C(0xFF'FF'FF'FF)
	};
	ASSERT_EQ(rec.u, 0xFF'FF'FF'FF);
	
	rec.i = -1234;
	ASSERT_EQ(rec.i, -1234);
	
	rec.f = 3.14;
	ASSERT_EQ(rec.f, 3.14);

	rec.c = '!';
	ASSERT_EQ(rec.c, '!');

	rec.ptr = &rec;
	ASSERT_EQ(rec.ptr, &rec);

	constexpr csignal sig{
		instruction::mov
	};
	ASSERT_EQ(sig.instr, instruction::mov);
	ASSERT_EQ(sig.op, static_cast<opcode>(instruction::mov));
	ASSERT_EQ(sig.r64.u, static_cast<std::uint64_t>(instruction::mov));
}