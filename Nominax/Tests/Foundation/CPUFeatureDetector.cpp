#include "../TestBase.hpp"

using CPU::ISAExtensionDetector;
using CPU::ISAExtensionBit;

TEST(CPUFeaturDetector, Construct)
{
    const auto executor
    {
        []
        {
            [[maybe_unused]]
            const ISAExtensionDetector detector { };
        }
    };
    ASSERT_NO_FATAL_FAILURE(executor());
}

#ifdef __SSE__

TEST(CPUFeaturDetector, SSE)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::SSE]);
}

#endif

#ifdef __SSE2__

TEST(CPUFeaturDetector, SSE2)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::SSE2]);
}

#endif

#ifdef __SSE3__

TEST(CPUFeaturDetector, SSE3)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::SSE3]);
}

#endif

#ifdef __SSSE__

TEST(CPUFeaturDetector, SSSE3)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::SSSE3]);
}

#endif

#ifdef __SSE4_1__

TEST(CPUFeaturDetector, SSE4_1)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::SSE4_1]);
}

#endif

#ifdef __SSE4_2__

TEST(CPUFeaturDetector, SSE4_2)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::SSE4_2]);
}

#endif

#ifdef __FMA__

TEST(CPUFeaturDetector, FMA)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::FMA3]);
}

#endif

#ifdef __AVX__

TEST(CPUFeaturDetector, AVX)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::AVX]);
}

#endif

#ifdef __AVX2__

TEST(CPUFeaturDetector, AVX2)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::AVX2]);
}

#endif

#ifdef __AVX512F__

TEST(CPUFeaturDetector, AVX512F)
{
    const ISAExtensionDetector detector { };
    ASSERT_TRUE(detector[ISAExtensionBit::AVX512F]);
}

#endif
