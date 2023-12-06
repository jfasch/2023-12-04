#include <cloud-kochtopf.h>
#include <sensor-mock.h>
#include <switch-mock.h>

#include <gtest/gtest.h>

#include <chrono>
using namespace std::chrono_literals;


TEST(cloud_kochtopf_suite, basic_usage)
{
    auto sensor = std::make_shared<MockSensor>(27.4);
    auto switcH = std::make_shared<MockSwitch>(false);

    CloudKochtopf kt(666, sensor, switcH, 1/*milli interval*/);

    PowerControl* pc = nullptr;
    TemperatureControl* tc = nullptr;

    const DeviceInfo* info = kt.get_info();
    ASSERT_EQ(info->id(), 666);
    for (auto [name, type]: info->capabilities()) {
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

    tc->set_target_temperature(91);
    pc->start();

    sensor->set_temperature(95);

    for (int _=0; _<100; _++)
        std::this_thread::sleep_for(1ms);

    ASSERT_FALSE(switcH->get_state());

    pc->stop();
}
