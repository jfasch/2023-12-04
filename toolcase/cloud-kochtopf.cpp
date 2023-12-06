#include "cloud-kochtopf.h"

#include <chrono>
using namespace std::chrono_literals;


// -----------------------------------------------------------------------------
KochtopfPowerControl::KochtopfPowerControl(CloudKochtopf* component)
: _component(component) {}

void KochtopfPowerControl::start()
{
    _component->_start_background_thread();
}

void KochtopfPowerControl::stop()
{
    _component->_stop_background_thread();
}

// -----------------------------------------------------------------------------
KochtopfTemperatureControl::KochtopfTemperatureControl(CloudKochtopf* component)
: _component(component) {}

double KochtopfTemperatureControl::get_target_temperature()
{
    return _component->_topf.get_target_temperature();
}

void KochtopfTemperatureControl::set_target_temperature(double t)
{
    return _component->_topf.set_target_temperature(t);
}

double KochtopfTemperatureControl::get_current_temperature()
{
    return _component->_sensor->get_temperature();
}

// -----------------------------------------------------------------------------
CloudKochtopf::CloudKochtopf(int id, 
                             const std::shared_ptr<Sensor>& sensor, 
                             const std::shared_ptr<Switch>& switcH,
                             int interval_milliseconds)
: _topf(sensor, switcH, -273.15 /*default target temperature*/),
  _info(id, {
        {"Temperaturregler", DeviceInfo::TEMPERATURE_CONTROL},
        {"EinAusSchalter", DeviceInfo::POWER_CONTROL},
    }),
  _power_ctl(this),
  _temperature_ctl(this),
  _sensor(sensor),
  _interval_milliseconds(interval_milliseconds)
{}

const DeviceInfo* CloudKochtopf::get_info()
{
    return &_info;
}

Control* CloudKochtopf::get_control(const std::string& name)
{
    if (name == "Temperaturregler")
        return &_temperature_ctl;
    else if (name == "EinAusSchalter")
        return &_power_ctl;
    else
        throw std::runtime_error("nix control");
}

void CloudKochtopf::_start_background_thread()
{
    _running = true;

    _thread = std::make_unique<std::thread>(
        [this]()
        {
            while (_running) {
                _topf.check();
                std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(_interval_milliseconds));
            }
        });
}

void CloudKochtopf::_stop_background_thread()
{
    _running = false;
    _thread->join();
    _thread.reset();
}
