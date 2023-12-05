class Kochtopf
{
public:
    Kochtopf(Sensor* sensor, Switch* switcH)
    : _hyst(sensor, switcH) {}

    void on()
    {
        // ...
        _status = true;
    }
    void off()
    {
        // ...
        _status = false;
    }
    void set_target_temperature(double t) { _hyst.set_target_temperature(t); }

private:
    Hysteresis _hyst;
};
