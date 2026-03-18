#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    int nb;

    while(read(fd, &nb, sizeof(int)) > 0) {
        printf("Nombre: %d\n", nb);
    }

    close(fd);

    return (0);
}