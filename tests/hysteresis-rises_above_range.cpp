#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, rises_above_range)
{
    MockSensor sensor(30.2);
    MockSwitch switcH(false);

    Hysteresis hyst(&sensor, &switcH, 20.1, 30.4);

    hyst.check();
    ASSERT_FALSE(switcH.state());

    sensor.set_temperature(35);                        // <--- rises above range

    hyst.check();
    ASSERT_FALSE(switcH.state());
}
