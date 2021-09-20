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

TEST(OSI, Threads)
{
    ASSERT_NE(OSI::QueryLogicalCPUCount(), 0);
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
    [[maybe_unused]]
	const bool result {OSI::MemoryUnmap(region, sizeof(int) * 2)};
}

TEST(OSI, MemoryUnmap)
{
    auto* const region {static_cast<int*>(OSI::MemoryMap(sizeof(int) * 2, MemoryPageProtectionFlags::ReadWrite))};
    ASSERT_TRUE(OSI::MemoryUnmap(region, sizeof(int) * 2));
    ASSERT_DEATH(*region = 10, "");
}

TEST(OSI, MemoryProtect)
{
    auto* const region {static_cast<int*>(OSI::MemoryMap(sizeof(int) * 2, MemoryPageProtectionFlags::NoAccess))};
    ASSERT_TRUE(OSI::MemoryProtect(region, sizeof(int) * 2, MemoryPageProtectionFlags::ReadWrite));
    ASSERT_NE(region, nullptr);
    *region = 10;
    ASSERT_EQ(*region, 10);
    *region = -2;
    ASSERT_EQ(*region, -2);
    region[1] = 0xFF;
    ASSERT_EQ(region[1], 0xFF);
    [[maybe_unused]]
    const bool result {OSI::MemoryUnmap(region, sizeof(int) * 2)};
}

TEST(OSI, MemoryNoProtect)
{
    const auto executor
    {
        []
        {
            auto* const region {static_cast<int*>(OSI::MemoryMap(sizeof(int) * 2, MemoryPageProtectionFlags::NoAccess))};
            ASSERT_NE(region, nullptr);
            *region = 10;
            ASSERT_EQ(*region, 10);
            *region = -2;
            ASSERT_EQ(*region, -2);
            region[1] = 0xFF;
            ASSERT_EQ(region[1], 0xFF);
            [[maybe_unused]]
            const bool result {OSI::MemoryUnmap(region, sizeof(int) * 2)};
        }
    };
    ASSERT_DEATH(executor(), "");
}
