#include "../TestBase.hpp"
#include "../../Source/Assembler/Maschinengott/Maschinengott_AMD64.h"

TEST(CodeGenerator_AMD64, REXPrefixZero)
{
    constexpr MWord a { MG_REX(0, 0) };
    ASSERT_EQ(a, 0b0100'0000);
}

TEST(CodeGenerator_AMD64, MODRMZero)
{
    constexpr MWord a { MG_MODRM(MG_MOD_REG, 0, 0) };
    ASSERT_EQ(a, 0b11'000'000);
}

TEST(CodeGenerator_AMD64, MODRM)
{
    const MWord a { MG_MODRM(MG_MOD_REG, MG_RID(MG_REG_RAX), MG_RID(MG_REG_RBX)) };
    ASSERT_EQ(a, 0b11'000'011);
}

TEST(CodeGenerator_AMD64, MODRMMask)
{
    const MWord a { MG_MODRM(MG_MOD_REG, MG_RID(MG_REG_RDX), MG_RID(MG_REG_RSI)) };
    ASSERT_EQ(a & 0b11'000'000, MG_MOD_REG);
    ASSERT_EQ((a & 0b00'111'000) >> 3, MG_RID(MG_REG_RDX));
    ASSERT_EQ(a & 0b00'000'111, MG_RID(MG_REG_RSI));
}

TEST(CodeGenerator_AMD64, MODRMCheckValid)
{
    ASSERT_TRUE(MG_CHECK_MODRM(MG_MOD_REG, MG_RID(MG_REG_RDX), MG_RID(MG_REG_RSI)));
}

TEST(CodeGenerator_AMD64, MODRMCheckInvalid)
{
    ASSERT_TRUE(MG_CHECK_MODRM(MG_MOD_REG, 0b1111, 0b1111));
}

TEST(CodeGenerator_AMD64, EmitIMM8)
{
    MWord buf[8] { };
    MWord* m { buf };
    MG_EMIT_IMM8(m, 0xFF);
    ASSERT_EQ(buf[0], 0xFF);
}

TEST(CodeGenerator_AMD64, EmitIMM16)
{
    MWord buf[8] { };
    MWord* m { buf };
    MG_EMIT_IMM16(m, 0xFF'FF);
    ASSERT_EQ(buf[0], 0xFF);
    ASSERT_EQ(buf[1], 0xFF);
}

TEST(CodeGenerator_AMD64, EmitIMM32)
{
    MWord buf[8] { };
    MWord* m { buf };
    MG_EMIT_IMM32(m, 0xFF'FF'FF'FF);
    ASSERT_EQ(buf[0], 0xFF);
    ASSERT_EQ(buf[1], 0xFF);
    ASSERT_EQ(buf[2], 0xFF);
    ASSERT_EQ(buf[3], 0xFF);
}

TEST(CodeGenerator_AMD64, EmitIMM64)
{
    MWord buf[8] { };
    MWord* m { buf };
    MG_EMIT_IMM64(m, 0xFF'FF'FF'FF'FF'FF'FF'FF);
    ASSERT_EQ(buf[0], 0xFF);
    ASSERT_EQ(buf[1], 0xFF);
    ASSERT_EQ(buf[2], 0xFF);
    ASSERT_EQ(buf[3], 0xFF);
    ASSERT_EQ(buf[4], 0xFF);
    ASSERT_EQ(buf[5], 0xFF);
    ASSERT_EQ(buf[6], 0xFF);
    ASSERT_EQ(buf[7], 0xFF);
}

TEST(CodeGenerator_AMD64, EmitI8)
{
    MWord buf[8] { };
    MWord* m { buf };
    MG_EMIT_I8(m, 0x7F);
    ASSERT_EQ(buf[0], 0x7F);
}

TEST(CodeGenerator_AMD64, EmitI16)
{
    MWord buf[8] { };
    MWord* m { buf };
    MG_EMIT_I16(m, 0xFF'7F);
    ASSERT_EQ(buf[0], 0x7F);
    ASSERT_EQ(buf[1], 0xFF);
}

TEST(CodeGenerator_AMD64, EmitI32)
{
    MWord buf[8] { };
    MWord* m { buf };
    MG_EMIT_I32(m, 0xFF'FF'FF'7F);
    ASSERT_EQ(buf[0], 0x7F);
    ASSERT_EQ(buf[1], 0xFF);
    ASSERT_EQ(buf[2], 0xFF);
    ASSERT_EQ(buf[3], 0xFF);
}

TEST(CodeGenerator_AMD64, EmitI64)
{
    MWord buf[8] { };
    MWord* m { buf };
    MG_EMIT_I64(m, 0xFF'FF'FF'FF'FF'FF'FF'7F);
    ASSERT_EQ(buf[0], 0x7F);
    ASSERT_EQ(buf[1], 0xFF);
    ASSERT_EQ(buf[2], 0xFF);
    ASSERT_EQ(buf[3], 0xFF);
    ASSERT_EQ(buf[4], 0xFF);
    ASSERT_EQ(buf[5], 0xFF);
    ASSERT_EQ(buf[6], 0xFF);
    ASSERT_EQ(buf[7], 0xFF);
}

TEST(CodeGenerator_AMD64, ExecuteMultiByteNOPChain)
{
    const auto executor
    {
        []
        {
            constexpr auto machineCodeSize { sizeof(MWord) * 16 };
            MWord* const machineCode { static_cast<MWord*>(VMM::VirtualAlloc(machineCodeSize, MemoryPageProtectionFlags::ReadWriteExecute)) };
            MWord* machineCodeBack = machineCode + machineCodeSize - 1;
            int x { 10 };

            MWord* needle { machineCode };
            MG_EMIT_NOP_CHAIN(needle, 15);
            MG_EMIT_RETN(needle); // return

            __builtin___clear_cache(reinterpret_cast<char*>(machineCode), reinterpret_cast<char*>(machineCodeBack));
            reinterpret_cast<auto(*)()->void>(machineCode)();

            ++x;
            ASSERT_EQ(x, 11);
            VMM::VirtualDealloc(machineCode);
        }
    };
    ASSERT_NO_FATAL_FAILURE(executor());
};


#if NOX_DEBUG

TEST(CodeGenerator_AMD64, InjectWrongNOPChainSize)
{
    const auto executor
    {
        []
        {
            MWord m;
            MG_InjectMultiByteNOPChain(&m, 0);
        }
    };
    ASSERT_DEATH(executor(), "");
}

TEST(CodeGenerator_AMD64, InjectWrongNOPChainSize)
{
    const auto executor
    {
            []
            {
                MWord m;
                MG_InjectMultiByteNOPChain(&m, 16);
            }
    };
    ASSERT_DEATH(executor(), "");
}

TEST(CodeGenerator_AMD64, InjectWrongNOPChainNullBuf)
{
    const auto executor
    {
            []
            {
                MG_InjectMultiByteNOPChain(nullptr, 16);
            }
    };
    ASSERT_DEATH(executor(), "");
}

#endif
