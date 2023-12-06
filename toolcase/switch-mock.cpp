#include "switch-mock.h"


MockSwitch::MockSwitch(bool initial_state)
: _state(initial_state) {}
    
bool MockSwitch::get_state() 
{ 
    return _state;
}

void MockSwitch::set_state(bool state)
{
    _state = state;
}

