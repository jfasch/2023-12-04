#include <gtest/gtest.h>

#include <sensor-w1.h>

#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>

#include <stdexcept>

using namespace std;


// fixture class: supply a temporary file, plus a method
// write_temperature() thaht derived classes can call
struct w1_sensor_suite : public ::testing::Test
{
    void SetUp() override
    {
        char filename_pattern[] = "w1_sensor_suite-XXXXXX";
        
        int fd = mkstemp(filename_pattern);
        if (fd == -1)
            throw runtime_error("nix mkstemp()");
        close(fd);

        filename = filename_pattern;
    }

    void TearDown() override
    {
        unlink(filename.c_str());
    }

    void change_temperature(double temperature)
    {
        unsigned temp_milli = temperature * 1000;

        string content = to_string(temp_milli);

        int fd = open(filename.c_str(), O_WRONLY);
        ASSERT_GE(fd, 0);

        ssize_t nwritten = ::write(fd, content.c_str(), content.size());
        ASSERT_EQ(nwritten, content.size());
        ::close(fd);
    }

    string filename;
};

TEST_F(w1_sensor_suite, read_sensor)
{
    W1Sensor sensor(filename);                 // <--- using filename from w1_sensor_suite fixture
    double temperature;

    change_temperature(42);                    // <--- change temperature
    temperature = sensor.get_temperature();    // <--- read temperature
    ASSERT_FLOAT_EQ(temperature, 42);

    change_temperature(36);                    // <--- change temperature
    temperature = sensor.get_temperature();    // <--- read temperature
    ASSERT_FLOAT_EQ(temperature, 36);
}

TEST_F(w1_sensor_suite, no_decimal_places_lost)
{
    W1Sensor sensor(filename);
    double temperature;

    change_temperature(42.666);
    temperature = sensor.get_temperature();
    ASSERT_FLOAT_EQ(temperature, 42.666);
}
