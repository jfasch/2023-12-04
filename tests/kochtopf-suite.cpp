#include <kochtopf.h>
#include <sensor-mock.h>
#include <switch-mock.h>

#include <gtest/gtest.h>


TEST(kochtopf_suite, basic)
{
    auto sensor = std::make_shared<MockSensor>(23.4);
    auto switcH = std::make_shared<MockSwitch>(false);

    Kochtopf k(sensor, switcH, /*target temperature*/92.1);
    
    k.check();

    ASSERT_TRUE(switcH->state());
}
