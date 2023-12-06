#include "sensor.h"
#include "switch.h"
#include "hysteresis.h"

#include <memory>


class Kochtopf
{
public:
    Kochtopf(const std::shared_ptr<Sensor>& sensor, 
             const std::shared_ptr<Switch>& switcH, 
             double target_temperature);

    double get_target_temperature() const
    { 
        return _hyst.low() + (_hyst.high() - _hyst.low()) / 2;
    }
    void set_target_temperature(double t)
    {
        double low = t - 2;      // ARGH!
        double high = t + 2;     // ARGH!
        
        _hyst.set_range(low, high);
    }

    void check();

private:
    Hysteresis _hyst;
};
