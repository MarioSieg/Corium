#include "../TestBase.hpp"

#include <cmath>

TEST(Common, ILog2)
{
	ASSERT_EQ(ILog2(8), 3);
	ASSERT_EQ(ILog2(8), std::log(8) / std::log(2));
}