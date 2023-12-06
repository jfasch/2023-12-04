#include <sensor-w1.h>

#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;

int main(int argc, char** argv)
{
    std::vector<W1Sensor> sensors;
    for (int i=1; i<argc; ++i) {
        std::cout << argv[i] << std::endl;
        sensors.push_back(W1Sensor(argv[i]));
    }
    
    for (int i=0; i<3; i++) {
        for (auto& s: sensors)
            std::cout << s.get_temperature() << std::endl;
        std::this_thread::sleep_for(1s);
    }

    return 0;
}
