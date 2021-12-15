#include "../TestBase.hpp"

TEST(Panic, Panic)
{
    const auto executor
    {
        []
        {
            Panic("ERROR!");
        }
    };
    ASSERT_DEATH(executor(), "");
}
