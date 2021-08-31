#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;
    int ret;
    uint8_t average[128];

    fd = open("/dev/sma", O_RDONLY);

    ret = read(fd, average, 128);
    printf("read %d bytes\n", ret);

    for (int i = 0; i < 128; ++i) {
        printf("average[%d] = %u\n", i, average[i]);
    }

    return 0;
}