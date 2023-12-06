#pragma once

#include "sensor.h"

#include <string>

class W1Sensor : public Sensor
{
public:
    W1Sensor() : _fd(-1) {}
    W1Sensor(const std::string& filename);

    W1Sensor(const W1Sensor&) = delete;
    W1Sensor& operator=(const W1Sensor&) = delete;

    W1Sensor(W1Sensor&&);
    W1Sensor& operator=(W1Sensor&&);

    ~W1Sensor();

    double get_temperature() override;

private:
    int _fd;
};



