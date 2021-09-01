#ifndef SMA_DRIVER_H
#define SMA_DRIVER_H

#include <cstdint>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

class SmaDevice {
    public:
        SmaDevice();
        int read(uint8_t output_sequence[], int size);
        int write(uint8_t input_sequence[], int size);
        ~SmaDevice();
    private:
        int fd;
};

#endif