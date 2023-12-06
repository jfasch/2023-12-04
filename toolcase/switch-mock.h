#pragma once

#include <switch.h>


class MockSwitch : public Switch
{
public:
    MockSwitch(bool initial_state);
    bool state() const { return _state; }
    void set_state(bool state) override;
private:
    bool _state;
};
