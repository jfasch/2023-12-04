#include <gtest/gtest.h>

#include <switch-mock.h>


TEST(switch_mock_suite, initial_state)
{
    {
        MockSwitch sw(false);
        ASSERT_FALSE(sw.state());
    }
    {
        MockSwitch sw(true);
        ASSERT_TRUE(sw.state());
    }
}

TEST(switch_mock_suite, set_on_off)
{
    MockSwitch sw(false);
    ASSERT_FALSE(sw.state());
    sw.set_state(true);
    ASSERT_TRUE(sw.state());
    sw.set_state(false);
    ASSERT_FALSE(sw.state());
}
