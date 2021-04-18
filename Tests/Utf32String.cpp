#include "TestBase.hpp"

TEST(U32String, ConstructFromLiteral)
{
	std::u32string_view view = U"Hello:)";
	Utf32String str{ view };
	ASSERT_EQ(str.GetSize(), view.size());
	ASSERT_EQ(str.GetCapacity(), view.size());
	ASSERT_EQ(str[0], U'H');
	ASSERT_EQ(str[1], U'e');
	ASSERT_EQ(str[2], U'l');
	ASSERT_EQ(str[3], U'l');
	ASSERT_EQ(str[4], U'o');
	ASSERT_EQ(str[5], U':');
	ASSERT_EQ(str[6], U')');
}