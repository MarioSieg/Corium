#include "../TestBase.hpp"

TEST(OSI, QuerySystemMemoryTotal)
{
	ASSERT_NE(OSI::QuerySystemMemoryTotal(), 0);
}

TEST(OSI, QueryProcessMemoryUsed)
{
	ASSERT_NE(OSI::QueryProcessMemoryUsed(), 0);
}

TEST(OSI, QueryCpuName)
{
	ASSERT_FALSE(std::empty(OSI::QueryCpuName()));
}

TEST(OSI, QueryPageSize)
{
	ASSERT_NE(OSI::QueryPageSize(), 0);
}

TEST(OSI, MemoryMap)
{
	auto* const region {static_cast<int*>(OSI::MemoryMap(sizeof(int) * 2, MemoryPageProtectionFlags::ReadWrite))};
	ASSERT_NE(region, nullptr);
	*region = 10;
	ASSERT_EQ(*region, 10);
	*region = -2;
	ASSERT_EQ(*region, -2);
	region[1] = 0xFF;
	ASSERT_EQ(region[1], 0xFF);
	ASSERT_TRUE(OSI::MemoryUnmap(region, sizeof(int) * 2));
}
