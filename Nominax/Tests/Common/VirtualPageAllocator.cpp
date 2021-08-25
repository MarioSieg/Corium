#include "../TestBase.hpp"

TEST(VMM, VirtualAlloc)
{
    auto* region {static_cast<int*>(VMM::VirtualAlloc(sizeof(int) * 2, MemoryPageProtectionFlags::ReadWrite))};
    ASSERT_NE(region, nullptr);
    *region = 10;
    ASSERT_EQ(*region, 10);
    *region = -2;
    ASSERT_EQ(*region, -2);
    region[1] = 0xFF;
    ASSERT_EQ(region[1], 0xFF);
    void* ptr { region };
    VMM::VirtualDealloc(ptr);
}

TEST(VMM, VirtualDelloc)
{
    auto* region {static_cast<int*>(VMM::VirtualAlloc(sizeof(int) * 2, MemoryPageProtectionFlags::ReadWrite))};
    ASSERT_NE(region, nullptr);
    ASSERT_TRUE(VMM::VirtualDealloc(region));
}

TEST(VMM, VirtualAllocHeader)
{
    auto* region { VMM::VirtualAlloc(sizeof(int) * 2, MemoryPageProtectionFlags::ReadWrite) };
    const auto& header { *reinterpret_cast<const VirtualAllocationHeader*>(static_cast<const std::byte*>(region) - sizeof(VirtualAllocationHeader)) };
    ASSERT_EQ(header.Size, sizeof(int) * 2);
    ASSERT_EQ(header.ProtectionFlags, MemoryPageProtectionFlags::ReadWrite);
    ASSERT_EQ(header.UserData.Ptr, nullptr);
    VMM::VirtualDealloc(region);
}
