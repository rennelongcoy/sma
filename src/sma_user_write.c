#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;
    int ret;
    uint8_t average[128] = {10, 10, 50, 100, 100, 200, 100, 1};

    fd = open("/dev/sma", O_WRONLY);

    /*for (int i = 0; i < 128; ++i) {
        average[i] = 128 - i;
    }*/

    //ret = write(fd, average, 128);
    ret = write(fd, average, 8);
    printf("written %d bytes\n", ret);

    return 0;
}