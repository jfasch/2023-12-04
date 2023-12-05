// #include <sensor-w1.h>

// #include <iostream>
// #include <array>
// using namespace std;

// constexpr const char* sensornames[] = {
//     "/sys/class/hwmon/hwmon5/temp1_input",
//     "/sys/class/hwmon/hwmon7/temp1_input",
// };

// constexpr size_t num_names(const auto& names)
// {
//     size_t num = 0;
//     for ([[maybe_unused]] auto n: names)
//         ++num;
//     return num;
// }

// template <size_t N>
// class SensorRegistry
// {
// public:
//     SensorRegistry(const char* names[])
//     {
//         for (size_t i=0; i<N; i++)
//             _sensors[i] = W1Sensor(names[i]);
//     }
// private:
//     std::array<Sensor, N> _sensors;
// };

int main()
{
    //SensorRegistry<num_names(sensornames)> reg(sensornames);
    return 0;
}
