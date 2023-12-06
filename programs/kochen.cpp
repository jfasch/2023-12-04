#include <cloud-kochtopf.h>
#include <sensor-w1.h>

#include <iostream>


class StdoutSwitch : public Switch
{
public:
    StdoutSwitch(bool state) : _state(false) {}

    void set_state(bool s) override
    {
        _state = s;
        std::cout << (s? "ON": "OFF") << '\n';
    }

    bool get_state() override
    {
        return _state;
    }

private:
    bool _state;
};

int main(int argc, char** argv)
{
    auto sensor = std::make_shared<W1Sensor>(argv[1]);
    auto switcH = std::make_shared<StdoutSwitch>(false);

    std::shared_ptr<CloudDevice> device(new CloudKochtopf(666, sensor, switcH, 1000));

    // hmm, figure out device caps
    const DeviceInfo* info = device->get_info();
    std::cout << "Device ID: " << info->id() << '\n';

    PowerControl* pc = nullptr;
    TemperatureControl* tc = nullptr;

    for (auto [name, type]: info->capabilities()) {
        switch (type)
        {
            case DeviceInfo::POWER_CONTROL: {
                Control* c = device->get_control(name);
                pc = dynamic_cast<PowerControl*>(c);
                if (pc == nullptr) {
                    std::cerr << "Device broken: claims POWER_CONTROL \"" << name << "\" but hasnt\n";
                    return EXIT_FAILURE;
                }
                break;
            }
            case DeviceInfo::TEMPERATURE_CONTROL: {
                Control* c = device->get_control(name);
                tc = dynamic_cast<TemperatureControl*>(c);
                if (tc == nullptr) {
                    std::cerr << "Device broken: claims TEMPERATURE_CONTROL \"" << name << "\" but hasnt\n";
                    return EXIT_FAILURE;
                }
                break;
            }
        }
    }

    // startup device
    pc->start();

    while (true) {
        std::string command;

        std::cout << "Enter command (\"temperature\", \"stop\"): ";
        std::cin >> command;
        std::cout << '\n';

        if (command == "temperature") {
            std::cout << "Enter double: ";
            double target_temperature;
            std::cin >> target_temperature;
            std::cout << '\n';
            tc->set_target_temperature(target_temperature);
        }
        else if (command == "stop")
            break;
        else
            std::cerr << "bad command: " << command << std::endl;
    }

    // shutdown device
    pc->stop();
    return EXIT_SUCCESS;
}
