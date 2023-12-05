#pragma once

#include "sensor.h"

#include <string>

class W1Sensor : public Sensor
{
public:
    W1Sensor() : _fd(-1) {}
    W1Sensor(const std::string& filename);
    ~W1Sensor();

    double get_temperature() override;

private:
    int _fd;
};



