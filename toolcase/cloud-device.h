#pragma once

class Control
{
public:
    virtual ~Control() {}
};

class TemperatureControl : public Control
{
public:
    virtual double get_temperature() = 0;
    virtual void set_temperature(double) = 0;
};

class PowerControl : public Control
{
public:
    virtual void set_state(bool) = 0;
    virtual bool get_state() = 0;
};

class DeviceInfo
{
public:
    DeviceInfo(int id, Capabilities c) : _id(id), _capabilities(c) {}

    enum Type
    {
        POWER_CONTROL,
        TEMPERATURE_CONTROL,
    };

    const Capabilities& capabilities() const { return _capabilities; }{

public:
    using Capability = std::pair<std::string /*name*/, Type>;
    using Capabilities = std::vector<Capability>;

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

