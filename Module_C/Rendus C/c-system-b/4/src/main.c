#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


#define FILE_LENGTH sizeof(int) * 5  // 5 entiers

int main() {
    int fd;
    int *file_memory;

    srand(time(NULL));

    // Création du fichier ou ouverture s'il existe
    fd = open("shared.bin", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if(fd < 0) { perror("open"); exit(1); } //affiche une erreur si échec


    ftruncate(fd, FILE_LENGTH); // Fixer la taille du fichier

    
    // Mapping mémoire
    file_memory = (int *) mmap(NULL, FILE_LENGTH, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if(file_memory == (void*) -1) { perror("mmap"); exit(1); }

    close(fd); // fd plus nécessaire après mmap

    // Écriture des 5 entiers aléatoires (-100 à 100)
    for(int i = 0; i < 5; i++) {
        file_memory[i] = rand() % 201 - 100;
        printf("[WRITER] Valeur écrite : %d\n", file_memory[i]);
    }

    // Libération mémoire
    munmap(file_memory, FILE_LENGTH);


    // Ouverture du fichier existant
    fd = open("shared.bin", O_RDONLY);
    if(fd < 0) { perror("open"); exit(1); }

    // Mapping mémoire
    file_memory = (int *) mmap(NULL, FILE_LENGTH, PROT_READ, MAP_SHARED, fd, 0);
    if(file_memory == (void*) -1) { perror("mmap"); exit(1); }

    close(fd);

    // Lecture et affichage des 5 entiers
    for(int i = 0; i < 5; i++) {
        printf("[READER] Valeur lue : %d\n", file_memory[i]);
    }

    // Libération mémoire
    munmap(file_memory, FILE_LENGTH);

    return 0;
}