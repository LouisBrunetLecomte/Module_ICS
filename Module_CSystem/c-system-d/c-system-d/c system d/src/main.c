// open 
// read

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int open(const char *pathname, int flags);

int main(int argc, char const *argv[])
{
    open("chemin/vers/fichier", O_RDONLY); // ouverture en lecture seule
    ssize_t read(int fd, void *buf, size_t count);
}