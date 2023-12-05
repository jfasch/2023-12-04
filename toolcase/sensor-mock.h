#pragma once

#include <sensor.h>


class MockSensor : public Sensor
{
public:
    MockSensor(double initial_temperature)
    : _temperature{initial_temperature} {}

    double get_temperature() override
    {
        return _temperature;
    }

    void set_temperature(double temperature)
    {
        _temperature = temperature;
    }

private:
    double _temperature;
};
