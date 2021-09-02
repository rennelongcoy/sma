#include "sma_device.hpp"

SmaDevice::SmaDevice()
{
    fd = open("/dev/sma", O_RDWR);
}

int SmaDevice::read(uint8_t output_sequence[], int size)
{
    int ret;
    ret = ::read(fd, output_sequence, size);
    return ret;
}

int SmaDevice::write(uint8_t input_sequence[], int size)
{
    int ret;
    ret = ::write(fd, input_sequence, size);
    return ret;
}

SmaDevice::~SmaDevice()
{
    close(fd);
}