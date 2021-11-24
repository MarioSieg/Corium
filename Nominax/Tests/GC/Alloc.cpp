#include "../TestBase.hpp"

TEST(GC, Alloc)
{
	const auto executor
	{
		[]
		{
			int* x { GCHeapAllocNative<int>() };
			ASSERT_NE(x, nullptr);
			GCHeapForcedDealloc(x);
		}
	};
	ASSERT_NO_FATAL_FAILURE(executor());
}
