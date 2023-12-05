#include <gtest/gtest.h>

TEST(cloud_kochtopf_suite, basic_usage)
{
    MockSensor sensor(27.4);
    MockSwitch switcH(false);

    CloudKochtopf kt(666, &sensor, &switcH);

    PowerControl* pc = nullptr;
    TemperatureControl* tc = nullptr;

    DeviceInfo* info = kt.get_info();
    ASSERT_EQ(info->id(), 666);
    for (auto [name, type]: info) {
        switch (type)
        {
            case DeviceInfo::POWER_CONTROL: {
                Control* c = kt.get_control(name);
                pc = dynamic_cast<PowerControl*>(c);
                ASSERT_NE(pc, nullptr);
                break;
            }
            case DeviceInfo::TEMPERATURE_CONTROL: {
                Control* c = kt.get_control(name);
                tc = dynamic_cast<TemperatureControl*>(c);
                ASSERT_NE(tc, nullptr);
                break;
            }
        }
    }

    pc->set_state(true);
    tc->set_temperature(91);

    sensor.set_temperature(95);
    // ...
    ASSERT_FALSE(switcH.get_state());
}
