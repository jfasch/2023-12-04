#pragma once

#include <vector>


class Control
{
public:
    virtual ~Control() {}
};

class TemperatureControl : public Control
{
public:
    virtual double get_target_temperature() = 0;
    virtual void set_target_temperature(double) = 0;
};

class PowerControl : public Control
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

class DeviceInfo
{
public:
    enum Type
    {
        POWER_CONTROL,
        TEMPERATURE_CONTROL,
    };
    using Capability = std::pair<std::string /*name*/, Type>;
    using Capabilities = std::vector<Capability>;

public:
    DeviceInfo(int id, Capabilities c) : _id(id), _capabilities(c) {}

    int id() const { return _id; }
    const Capabilities& capabilities() const { return _capabilities; }

private:
    int _id;
    Capabilities _capabilities;
};

class CloudDevice
{
public:
    virtual ~CloudDevice() {}
    virtual const DeviceInfo* get_info() = 0;
    virtual Control* get_control(const std::string& name) = 0;
};
