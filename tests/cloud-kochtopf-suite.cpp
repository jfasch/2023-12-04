#include <cloud-kochtopf.h>
#include <sensor-mock.h>
#include <switch-mock.h>

#include <gtest/gtest.h>

#include <chrono>
using namespace std::chrono_literals;


struct cloud_kochtopf_suite : public ::testing::Test
{
    void SetUp() override
    {
        sensor = std::make_shared<MockSensor>(0.0);
        switcH = std::make_shared<MockSwitch>(false);

        topf = new CloudKochtopf(666, sensor, switcH, 1/*milli interval*/);

        temperature_control = nullptr;
        power_control = nullptr;

        const DeviceInfo* info = topf->get_info();
        ASSERT_EQ(info->id(), 666);
        for (auto [name, type]: info->capabilities()) {
            switch (type)
            {
                case DeviceInfo::POWER_CONTROL: {
                    Control* c = topf->get_control(name);
                    power_control = dynamic_cast<PowerControl*>(c);
                    ASSERT_NE(power_control, nullptr);
                    break;
                }
                case DeviceInfo::TEMPERATURE_CONTROL: {
                    Control* c = topf->get_control(name);
                    temperature_control = dynamic_cast<TemperatureControl*>(c);
                    ASSERT_NE(temperature_control, nullptr);
                    break;
                }
            }
        }

        power_control->start();
    }

    void TearDown() override
    {
        power_control->stop();
    }

    CloudDevice* topf;
    std::shared_ptr<MockSensor> sensor;
    std::shared_ptr<MockSwitch> switcH;

    PowerControl* power_control;
    TemperatureControl* temperature_control;
};


TEST_F(cloud_kochtopf_suite, basic_usage)
{

    temperature_control->set_target_temperature(91);

    // expecting the switch turned on really soon now
    int loop;
    for (loop=0; loop<100; loop++) {
        if (switcH->get_state() == true)
            break;
        std::this_thread::sleep_for(1ms);
    }
    ASSERT_TRUE(switcH->get_state());
    ASSERT_NE(loop, 100);

    sensor->set_temperature(95);  // target temperature reached

    // expecting the switch turned off really soon now
    for (loop=0; loop<100; loop++) {
        if (switcH->get_state() == false)
            break;
        std::this_thread::sleep_for(1ms);
    }
    ASSERT_FALSE(switcH->get_state());
    ASSERT_NE(loop, 100);
}
