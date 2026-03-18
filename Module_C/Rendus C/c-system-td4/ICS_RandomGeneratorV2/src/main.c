/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char oc;
    int repet = -1;

    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n' && argc > 2) {
        repet = atoi(argv[2]);
    } else {
        while ((oc = getopt(argc, argv, "ia")) != -1) {
            switch (oc) {
                case 'a':
                    printf("boummm \n");
                    break;
                case 'i':
                    printf("nombre de valeur : ");
                    scanf("%i", &repet);
                    break;
            }
        }
    }

    while (repet-- != 0) {
        printf("%d\n", rand()%1000);
        usleep(500000);
    }
    return (EXIT_SUCCESS);
}


