#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

//user space application
int main()
{

    char buffer[1024];
    int fd = open ("/dev/mydriver",O_RDWR);

    if (fd < 0) {
        perror("open");
        return 1;
    }


    int n = read(fd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        return 1;
    }

    buffer[n] = '\0';

    printf("Read from device: %s\n", buffer);

    close(fd);
    return 0;
}