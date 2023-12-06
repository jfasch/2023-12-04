#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, rises_above_range)
{
    auto sensor = std::make_shared<MockSensor>(30.2);
    auto switcH = std::make_shared<MockSwitch>(false);

    Hysteresis hyst(sensor, switcH, 20.1, 30.4);

    hyst.check();
    ASSERT_FALSE(switcH->state());

    sensor->set_temperature(35);                        // <--- rises above range

    hyst.check();
    ASSERT_FALSE(switcH->state());
}
