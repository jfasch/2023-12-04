#include <sensor-w1.h>

#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;


int main(int argc, char** argv)
{
    while (true) {
        for (int i=1; i<argc; i++) {
            W1Sensor s(argv[i]);
            std::cout << argv[i] << ": " << s.get_temperature() << '\n';
        }
        std::this_thread::sleep_for(1s);
    }

    return 0;
}
