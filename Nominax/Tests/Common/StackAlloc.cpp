#include "../TestBase.hpp"

TEST(StackAlloc, StackAlloc)
{
	int* ptr{ StackAlloc<int, 2>() };
	ASSERT_NE(ptr, nullptr);
	ptr[0] = 3;
	ptr[1] = -2;
	ASSERT_EQ(ptr[0], 3);
	ASSERT_EQ(ptr[1], -2);
}