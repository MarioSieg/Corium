#include "../TestBase.hpp"

TEST(Common, SafeLocalTime)
{
	auto time = std::time(nullptr);
	auto result = SafeLocalTime(time);
	ASSERT_EQ(std::memcmp(std::localtime(&time), &result, sizeof(std::tm)), 0);
}