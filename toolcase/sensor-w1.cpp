#include "sensor-w1.h"

#include <system_error>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>


W1Sensor::W1Sensor(const std::string& filename)
{
    _fd = ::open(filename.c_str(), O_RDONLY);
    if (_fd == -1)
        throw std::system_error(errno, std::generic_category(), "open");
}

W1Sensor::~W1Sensor()
{
    ::close(_fd);
}

double W1Sensor::get_temperature()
{ 
    off_t pos = ::lseek(_fd, 0, SEEK_SET);
    if (pos == -1)
        throw std::system_error(errno, std::generic_category(), "read");

    char buffer[32];
    ssize_t nread = ::read(_fd, buffer, sizeof(buffer));
    if (nread == -1)
        throw std::system_error(errno, std::generic_category(), "read");

    buffer[nread] = 0;

    long millis = std::stol(buffer);
    return (double)millis/1000;
}
