#pragma once

#include <sensor.h>
#include <switch.h>

#include <memory>


class Hysteresis
{
public:
    Hysteresis(const std::shared_ptr<Sensor>& sensor, 
               const std::shared_ptr<Switch>& switcH, 
               double low, double high);
    void check();
    void set_range(double low, double high);

private:
    std::shared_ptr<Sensor> _sensor;
    std::shared_ptr<Switch> _switch;
    double _low;
    double _high;
};
