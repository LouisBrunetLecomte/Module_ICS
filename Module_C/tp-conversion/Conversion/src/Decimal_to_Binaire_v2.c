#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "Décimal_to_Binaire_v2.h"


// Décimale -> Binaire

char *dectobin_v2(unsigned int val) { // nombre entier strictement positif
    char *bin = malloc(33);  // Max 32 bits + 1 pour '\0' 
                             // Malloc permet d'allouer dynamiquement de la mémoire
    if (!bin) return NULL;  // Vérification de l'allocation mémoire, qu'elle a bien ete faite correctement
                            // qu'un espace mémoire a bien été alloué
                             // Si l'allocation échoue, on retourne NULL

    int i = 0;

    // Cas spécial : 0
    if (val == 0) {
        bin[i] = '0'; // mettre la valeur a 0
        i++;    // incrémenter l'index

    } else {
        while (val > 0) {
            bin[i++] = (val % 2) ? '1' : '0';  // calcul du reste de la division de val par 2
                                             // si le reste est 1, on ajoute '1', sinon '0'
                                             // incrémente i après avoir assigné la valeur
            val /= 2;                          // Division entière de val par 2 pour réduire la valeur
        }
    }

    bin[i] = '\0'; // termine la chaine de caractères


    // Inverser la chaîne (car elle est construite à l'envers)
    for (int j = 0; j < i / 2; j++) { // parcours jusqu'à la moitié du tableau
        char temp = bin[j];     // mettre dans la poche la valeur de j
        bin[j] = bin[i - j - 1]; // remplacer la valeur de j par celle qui lui est symétriquement opposée. 
        bin[i - j - 1] = temp; // placer le caractère temp a la fin.
    }

    return bin;
}