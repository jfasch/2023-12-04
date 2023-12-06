#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, set_range)
{

    MockSensor sensor(30.2);
    MockSwitch switcH(false);

    Hysteresis hyst(&sensor, &switcH, 
                    20.1, 30.4);
    hyst.check();
    ASSERT_FALSE(switcH.state());

    hyst.set_range(0,2);
    hyst.check();
    ASSERT_FALSE(switcH.state());

    sensor.set_temperature(-2);

    hyst.check();
    ASSERT_TRUE(switcH.state());

    hyst.set_range(100,102);
    hyst.check();
    ASSERT_TRUE(switcH.state());
    sensor.set_temperature(90);
    hyst.check();
    ASSERT_TRUE(switcH.state());
    sensor.set_temperature(105);
    hyst.check();
    ASSERT_FALSE(switcH.state());


}
