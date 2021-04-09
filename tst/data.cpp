#include "tstbase.hpp"

#include <x86intrin.h>

#include "../inc/nominax/reactor.hpp"

using namespace nominax;

TEST(reactor_aggregates, union_reinterpretation) {
	record32 rec{
		0xFF'FF'FF'FFU
	};
	ASSERT_EQ(rec.u, 0xFF'FF'FF'FF);
	
	rec.i = -1234;
	ASSERT_EQ(rec.i, -1234);
	
	rec.f = 3.14F;
	ASSERT_EQ(rec.f, 3.14F);

	rec.c = '!';
	ASSERT_EQ(rec.c, '!');

	constexpr signal32 sig{
		instruction::mov
	};
	ASSERT_EQ(sig.instr, instruction::mov);
	ASSERT_EQ(sig.op, static_cast<std::uint32_t>(instruction::mov));
	ASSERT_EQ(sig.r32.u, static_cast<std::uint32_t>(instruction::mov));
}