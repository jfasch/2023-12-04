#include "kochtopf.h"


Kochtopf::Kochtopf(const std::shared_ptr<Sensor>& sensor, 
                   const std::shared_ptr<Switch>& switcH, 
                   double target_temperature)
: _hyst(sensor, switcH, 
        target_temperature-2, target_temperature+2)
{}

void Kochtopf::check()
{ 
    _hyst.check();
}
