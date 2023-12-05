#pragma once

#include "kochtopf.h"
#include "cloud-device.h"

class KochtopfPowerControl : public PowerControl
{
public:
    KochtopfPowerControl(Kochtopf* kt) : _kt(kt) {}
    void set_state(bool s) override
    {
        if (s == true)
            _kt->on();
        else
            _kt->off();
    }
    bool get_state() override
    {
        return _kt->is_on();
    }
private:
    Kochtopf* _kt;
};

class KochtopfTemperatureControl : public TemperatureControl
{
public:
    KochtopfTemperatureControl(Kochtopf* kt) : _kt(kt) {}

    double get_temperature() override
    {
        return _kt->get_temperature();
    }
    void set_temperature(double t) override
    {
        _kt->set_temperature(t);
    }

private:
    Kochtopf* _kt;
};

class CloudKochtopf : public CloudDevice
{
public:
    CloudKochtopf(int id, Sensor* sensor, Switch* switcH)
    : _kochtopf(sensor, switcH),
      _info(id, {
            {"Temperaturregler", TEMPERATURE_CONTROL},
            {"EinAusSchalter", POWER_CONTROL},
        }),
      _power_ctl(&_kochtopf),
      _temperature_ctl(&_kochtopf)
    {}

    const DeviceInfo* get_info() override
    {
        return &_info;
    }
    Control* get_control(const std::string& name) override
    {
        if (name == "Temperaturregler")
            return &_temperature_ctl;
        else if (name == "EinAusSchalter")
            return &_power_ctl;
        else
            throw std::runtime_error("nix control");
    }

private:
    Kochtopf _topf;
    DeviceInfo _info;
    KochtopfPowerControl _power_ctl;
    KochtopfTemperatureControl _temperature_ctl;
};
