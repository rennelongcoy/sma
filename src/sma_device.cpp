#include "sma_device.hpp"

SmaDevice::SmaDevice()
{
    std::cout << "SmaDevice::SmaDevice()" << std::endl;
    fd = open("/dev/sma", O_RDWR);
}

int SmaDevice::read(uint8_t output_sequence[], int size)
{
    std::cout << "SmaDevice::read()" << std::endl;
    int ret;
    ret = ::read(fd, output_sequence, size);
    std::cout << "Successfully read " << ret << " bytes" << std::endl;
    return ret;
}

int SmaDevice::write(uint8_t input_sequence[], int size)
{
    std::cout << "SmaDevice::write()" << std::endl;
    int ret;
    ret = ::write(fd, input_sequence, size);
    std::cout << "Successfully written " << ret << " bytes" << std::endl;
    return ret;
}

SmaDevice::~SmaDevice()
{
    std::cout << "SmaDevice::~SmaDevice()" << std::endl;
    close(fd);
}