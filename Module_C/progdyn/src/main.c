#include <stdio.h>
#include <stdlib.h>
#include "dichotomie.h"
#include "glouton.h"
#include "carre.h"

int main()
{
    printf("\n\n---DICHOTOMIE---\n\n");
    printf("Recherche du nombre 5.\n");
    int array[10] = {1, 3, 4, 5, 6, 7, 8, 9, 10};
    int tab[5] = {1, 3, 5, 7, 9};
    find_by_dichotomy(tab, 5, 5);
    
    Objet* arrayOfObject[5];

    // Allocate memory for 5 objects
    for (int i = 0; i < 5; i++) {
        arrayOfObject[i] = malloc(sizeof(Objet));
        if (arrayOfObject[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1; // Exit if memory allocation fails
        }
    }

    printf("\n\n---ALGO GLOUTON---\n\n");

    // Initialize the objects with values and volumes
    arrayOfObject[0]->valeur = 60; arrayOfObject[0]->volume = 10;
    arrayOfObject[1]->valeur = 100; arrayOfObject[1]->volume = 20;
    arrayOfObject[2]->valeur = 120; arrayOfObject[2]->volume = 30;
    arrayOfObject[3]->valeur = 80; arrayOfObject[3]->volume = 15;
    arrayOfObject[4]->valeur = 90; arrayOfObject[4]->volume = 25;

    int max_volume = 50; // Set the maximum volume for the knapsack

    // Call the glouton function
    glouton(arrayOfObject, 5, max_volume);

    printf("\n\n---FIND THE BIGGEST SQUARE---\n\n");

    int* m = newMatrice();
    showMatriceWithCarre(m);
    return 0;
}
