#pragma once

#include "kochtopf.h"
#include "cloud-device.h"

#include <atomic>
#include <memory>
#include <thread>
#include <chrono>


class CloudKochtopf;

class KochtopfPowerControl final : public PowerControl
{
public:
    KochtopfPowerControl(CloudKochtopf* component);
    void start() override;
    void stop() override;
private:
    CloudKochtopf* _component;
};

class KochtopfTemperatureControl final : public TemperatureControl
{
public:
    KochtopfTemperatureControl(CloudKochtopf* component);
    double get_target_temperature() override;
    void set_target_temperature(double t) override;
    double get_current_temperature() override;
private:
    CloudKochtopf* _component;
};

class CloudKochtopf : public CloudDevice
{
public:
    CloudKochtopf(
        int id, 
        const std::shared_ptr<Sensor>& sensor, 
        const std::shared_ptr<Switch>& switcH,
        int interval_milliseconds
    );

    const DeviceInfo* get_info() override;
    Control* get_control(const std::string& name) override;

private:
    Kochtopf _topf;
    DeviceInfo _info;
    KochtopfPowerControl _power_ctl;
    KochtopfTemperatureControl _temperature_ctl;

    std::shared_ptr<Sensor> _sensor;

private:
    void _start_background_thread();
    void _stop_background_thread();

    std::unique_ptr<std::thread> _thread;
    std::atomic<bool> _running;
    int _interval_milliseconds;

private:
   friend class KochtopfTemperatureControl;
   friend class KochtopfPowerControl;
};
