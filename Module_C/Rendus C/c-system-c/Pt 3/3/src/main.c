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
    srand(time(NULL));
    mkfifo(argv[1], 0666);

    int fd = open(argv[1], O_WRONLY);
    int randInt;

    int opt;
    while ((opt = getopt(argc, argv, "n:")) != -1) { // rechercher 'n' dans les options (-n, --n) et regarder la valeur après (':') pour bien prendre en compte '-n 5'
        switch (opt) {
            case 'n':
                for(int i=0;i<atoi(optarg);i++) {
                    randInt = (rand() % 60);
                    printf("sending %d\n", randInt);
                    write(fd, &randInt, sizeof(int));
                }
                write(fd, &randInt, sizeof(randInt));
                break;
            default:
                printf("AHHHH\n");
                return 1;
        }
    }

    close(fd);
    return (0);
}