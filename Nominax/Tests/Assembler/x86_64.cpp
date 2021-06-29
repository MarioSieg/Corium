#include "../TestBase.hpp"

using namespace Assembler::X86_64;

TEST(Assembler_x86_64, PackRex_Empty)
{
    const U8 rex{PackRex(false, false, false, false)};
    ASSERT_EQ(rex, 0x40);
}

TEST(Assembler_x86_64, PackRex_W)
{
    const U8 rex{PackRex(true, false, false, false)};
    ASSERT_EQ(rex, 0x40 | (1 << 3));
}

TEST(Assembler_x86_64, PackRex_R)
{
    const U8 rex{PackRex(false, true, false, false)};
    ASSERT_EQ(rex, 0x40 | (1 << 2));
}

TEST(Assembler_x86_64, PackRex_X)
{
    const U8 rex{PackRex(false, false, true, false)};
    ASSERT_EQ(rex, 0x40 | (1 << 1));
}

TEST(Assembler_x86_64, PackRex_B)
{
    const U8 rex{PackRex(false, false, false, true)};
    ASSERT_EQ(rex, 0x40 | 1);
}

TEST(Assembler_x86_64, PackRex_WRXB)
{
    const U8 rex{PackRex(true, true, true, true)};
    ASSERT_EQ(rex, 0x40 | 0b1111);
}

TEST(Assembler_x86_64, PackPackBits233)
{
    const U8 trio {PackModRm(0b11, 0b010, 0b101)};
    ASSERT_EQ(trio, 0b11'010'101);
}

TEST(Assembler_x86_64, PackPackBits233_One)
{
    const U8 trio {PackModRm(0b11, 0b111, 0b111)};
    ASSERT_EQ(trio, 0xFF);
}

TEST(Assembler_x86_64, PackPackBitsZero)
{
    const U8 trio {PackModRm(0, 0, 0)};
    ASSERT_EQ(trio, 0);
}
