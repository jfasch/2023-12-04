#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, falls_below_range)
{
    auto sensor = std::make_shared<MockSensor>(30.2);
    auto switcH = std::make_shared<MockSwitch>(false);

    Hysteresis hyst(sensor, switcH, 
                    20.1, 30.4);                       // <--- initially within range

    hyst.check();
    ASSERT_FALSE(switcH->get_state());

    sensor->set_temperature(20.0);                      // <--- falls below range

    hyst.check();
    ASSERT_TRUE(switcH->get_state());
}
