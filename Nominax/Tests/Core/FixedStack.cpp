#include "../TestBase.hpp"

TEST(Common, FixedStackConstructAllocateValid)
{
	FixedStack stack{ 1 };
	ASSERT_EQ(stack.Size(), 2);
	ASSERT_EQ(stack.Buffer()[0], Record::Padding());
	ASSERT_EQ(stack.Buffer()[1].U64, 0);
	ASSERT_EQ(*stack.begin(), Record::Padding());
	ASSERT_EQ(stack.end()[-1].U64, 0);
}

TEST(Common, FixedStackConstructAllocateInvalid)
{
	ASSERT_ANY_THROW(FixedStack{ 0 });
}

TEST(Common, FixedStackConstructMoveConstructor)
{
	FixedStack a{ 32 };
	ASSERT_EQ(a.Size(), 33);
	a.begin()[1].I32 = -10;

	FixedStack b{ std::move(a) };
	ASSERT_EQ(b.Size(), 33);
	ASSERT_EQ(b.begin()[1].I32, -10);
}

TEST(Common, FixedStackConstructMoveAssignment)
{
	FixedStack a{ 32 };
	ASSERT_EQ(a.Size(), 33);
	a.begin()[1].I32 = -10;

	FixedStack b{ 3 };
	b = std::move(a);
	ASSERT_EQ(b.Size(), 33);
	ASSERT_EQ(b.begin()[1].I32, -10);
}

