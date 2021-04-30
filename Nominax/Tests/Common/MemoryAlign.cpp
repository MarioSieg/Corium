#include "../TestBase.hpp"

TEST(Common, IsAlignmentValid)
{
	ASSERT_TRUE(IsAlignmentValid(alignof(int)));
	ASSERT_TRUE(IsAlignmentValid(alignof(short)));
	ASSERT_TRUE(IsAlignmentValid(alignof(float)));
	ASSERT_TRUE(IsAlignmentValid(alignof(long)));
	ASSERT_TRUE(IsAlignmentValid(alignof(long long)));
	ASSERT_TRUE(IsAlignmentValid(2));
	ASSERT_FALSE(IsAlignmentValid(3));
	ASSERT_TRUE(IsAlignmentValid(4));
	ASSERT_FALSE(IsAlignmentValid(6));
	ASSERT_FALSE(IsAlignmentValid(10));
	ASSERT_FALSE(IsAlignmentValid(1+alignof(int)));
	ASSERT_FALSE(IsAlignmentValid(1-alignof(short)));
	ASSERT_FALSE(IsAlignmentValid(1+alignof(float)));
	ASSERT_FALSE(IsAlignmentValid(2+alignof(long)));
	ASSERT_FALSE(IsAlignmentValid(2-alignof(long long)));
}

TEST(Common, IsAlignedTo)
{
	void* ptr{nullptr};
#if NOMINAX_32_BIT
	ASSERT_TRUE(IsAlignedTo(ptr, 4));
#else
	ASSERT_TRUE(IsAlignedTo(ptr, 8));
#endif

	alignas(16) void* a{ nullptr };
	ASSERT_TRUE(IsAlignedTo(a, 16));

	alignas(32) void* b{ nullptr };
	ASSERT_TRUE(IsAlignedTo(b, 16));

	alignas(64) void* c{ nullptr };
	ASSERT_TRUE(IsAlignedTo(c, 16));

	alignas(128) void* d{ nullptr };
	ASSERT_TRUE(IsAlignedTo(d, 16));
}

TEST(Common, ComputeMissingAlignmentOffset)
{
	ASSERT_EQ(ComputeMissingAlignmentOffset(8, 8), 0);
	ASSERT_EQ(ComputeMissingAlignmentOffset(4, 8), 4);
	ASSERT_EQ(ComputeMissingAlignmentOffset(8, 16), 8);
}

TEST(Common, ComputeMinAlignmentRequiredForSize)
{
	ASSERT_EQ(ComputeMinAlignmentRequiredForSize(32), alignof(std::max_align_t));
	ASSERT_EQ(ComputeMinAlignmentRequiredForSize(4), 4);
	ASSERT_EQ(ComputeMinAlignmentRequiredForSize(1), 2);
	ASSERT_EQ(ComputeMinAlignmentRequiredForSize(8), 8);
}