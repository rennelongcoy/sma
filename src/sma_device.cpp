#include "sma_device.hpp"

/* TODO: Improve class public interfaces */

SmaDevice::SmaDevice()
{
    fd = open("/dev/sma", O_RDWR);
}

int SmaDevice::read(uint8_t output_sequence[], size_t size)
{
    int ret;
    ret = ::read(fd, output_sequence, size);
    return ret;
}

int SmaDevice::write(uint8_t input_sequence[], size_t size)
{
    int ret;
    ret = ::write(fd, input_sequence, size);
    return ret;
}

SmaDevice::~SmaDevice()
{
    close(fd);
}