#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, nop_when_within_range)
{
    auto sensor = std::make_shared<MockSensor>(30.2);
    auto switcH = std::make_shared<MockSwitch>(false);

    Hysteresis hyst(sensor, switcH, 20.1, 30.4);

    hyst.check();                                      // <--- sees sensor well within range
    ASSERT_FALSE(switcH->state());
}
