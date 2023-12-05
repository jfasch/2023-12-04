#pragma once

#include <sensor.h>


class MockSensor : public Sensor
{
public:
    MockSensor(double initial_temperature);
    double get_temperature() override;

    // set result for next get_temperature() call
    void set_temperature(double temperature);
private:
    double _temperature;
};
