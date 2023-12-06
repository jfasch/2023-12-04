#include "sensor.h"
#include "switch.h"
#include "hysteresis.h"

#include <memory>


class Kochtopf
{
public:
    Kochtopf(std::shared_ptr<Sensor> sensor, std::shared_ptr<Switch> switcH, 
             double target_temperature)
    : _hyst(sensor, switcH, 
            target_temperature-2, target_temperature+2)
    {}

    void check() { _hyst.check(); }

private:
    Hysteresis _hyst;
};
