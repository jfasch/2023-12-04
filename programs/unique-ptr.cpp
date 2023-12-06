#include <sensor-w1.h>
#include <memory>
#include <map>
#include <iostream>

int main()
{
    std::map<std::string, std::unique_ptr<W1Sensor>> sensors;

    auto s1 = std::make_unique<W1Sensor>("/tmp/file1");
    auto s2 = std::make_unique<W1Sensor>("/tmp/file2");

    sensors["Hansi"] = std::move(s1);
    sensors["Franzi"] = std::move(s2);

    std::cout << "Hansi: " << sensors["Hansi"]->get_temperature() << std::endl;
    std::cout << "Franzi: " << sensors["Franzi"]->get_temperature() << std::endl;
    
    return 0;
}
