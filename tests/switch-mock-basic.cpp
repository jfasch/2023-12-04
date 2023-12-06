#include <gtest/gtest.h>

#include <switch-mock.h>


TEST(switch_mock_suite, initial_state)
{
    {
        MockSwitch sw(false);
        ASSERT_FALSE(sw.get_state());
    }
    {
        MockSwitch sw(true);
        ASSERT_TRUE(sw.get_state());
    }
}

TEST(switch_mock_suite, set_on_off)
{
    MockSwitch sw(false);
    ASSERT_FALSE(sw.get_state());
    sw.set_state(true);
    ASSERT_TRUE(sw.get_state());
    sw.set_state(false);
    ASSERT_FALSE(sw.get_state());
}
