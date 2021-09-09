#ifndef SMA_DRIVER_H
#define SMA_DRIVER_H

#include <cstdint>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

/* TODO: Improve class public interfaces */

class SmaDevice {
    public:
        SmaDevice();
        int read(uint8_t output_sequence[], size_t size);
        int write(uint8_t input_sequence[], size_t size);
        ~SmaDevice();
    private:
        int fd;
};

#endif