#pragma once

class Switch
{
public:
    virtual ~Switch() {}
    virtual void set_state(bool state) = 0;

    // convenience (non-virtual)
    void on() { set_state(true); }
    void off() { set_state(false); }
};
