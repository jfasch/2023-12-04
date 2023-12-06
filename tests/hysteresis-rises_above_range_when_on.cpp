#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, rises_above_range_when_on)
{
    auto sensor = std::make_shared<MockSensor>(30.2);
    auto switcH = std::make_shared<MockSwitch>(false);

    Hysteresis hyst(sensor, switcH, 20.1, 30.4);

    sensor->set_temperature(-273.15);                  // <--- ensure that switch will be 
                                                       //      on after next check()

    hyst.check();
    ASSERT_TRUE(switcH->state());

    sensor->set_temperature(35);                        // <--- rises above range

    hyst.check();
    ASSERT_FALSE(switcH->state());
}
