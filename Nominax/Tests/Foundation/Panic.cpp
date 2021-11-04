#include "../TestBase.hpp"

TEST(Panic, Panic)
{
    const auto executor
    {
        []
        {
            Panic::Panic("ERROR!");
        }
    };
    ASSERT_DEATH(executor(), "");
}
