#include "../TestBase.hpp"

TEST(CPUFeaturDetector, Construct)
{
    const auto executor
    {
        []
        {
            [[maybe_unused]]
            const CPUFeatureDetector detector { };
        }
    };
    ASSERT_NO_FATAL_FAILURE(executor());
}

#ifdef __SSE__

TEST(CPUFeaturDetector, SSE)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::SSE]);
}

#endif

#ifdef __SSE2__

TEST(CPUFeaturDetector, SSE2)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::SSE2]);
}

#endif

#ifdef __SSE3__

TEST(CPUFeaturDetector, SSE3)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::SSE3]);
}

#endif

#ifdef __SSSE__

TEST(CPUFeaturDetector, SSSE3)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::SSSE3]);
}

#endif

#ifdef __SSE4_1__

TEST(CPUFeaturDetector, SSE4_1)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::SSE4_1]);
}

#endif

#ifdef __SSE4_2__

TEST(CPUFeaturDetector, SSE4_2)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::SSE4_2]);
}

#endif

#ifdef __FMA__

TEST(CPUFeaturDetector, FMA)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::FMA3]);
}

#endif

#ifdef __AVX__

TEST(CPUFeaturDetector, AVX)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::AVX]);
}

#endif

#ifdef __AVX2__

TEST(CPUFeaturDetector, AVX2)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::AVX2]);
}

#endif

#ifdef __AVX512F__

TEST(CPUFeaturDetector, AVX512F)
{
    const CPUFeatureDetector detector { };
    ASSERT_TRUE(detector[CPUFeatureBits::AVX512F]);
}

#endif
