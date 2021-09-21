#include "../TestBase.hpp"

TEST(AlignedMalloc, Alloc)
{
    auto* const mem { static_cast<int*>(AlignedMalloc(sizeof(int), alignof(int))) };
    ASSERT_NE(mem, nullptr);
    ASSERT_TRUE(IsAlignedTo(mem, alignof(int)));
    *mem = 15;
    ASSERT_EQ(*mem, 15);
    AlignedFree(mem);
}

TEST(AlignedMalloc, AllocAligned)
{
    struct alignas(alignof(std::max_align_t)) Dummy final
    {
        std::array<std::uint8_t, 128> Data { };
    };

    auto* const mem { static_cast<Dummy*>(AlignedMalloc(sizeof(Dummy), alignof(Dummy ))) };
    ASSERT_NE(mem, nullptr);
    ASSERT_TRUE(IsAlignedTo(mem, alignof(int)));
    for (std::uint8_t y { }; std::uint8_t& x : mem->Data)
    {
        x = ++y;
    }
    for (std::uint8_t y { }; std::uint8_t& x : mem->Data)
    {
        ASSERT_EQ(x, ++y);
    }
    AlignedFree(mem);
}
