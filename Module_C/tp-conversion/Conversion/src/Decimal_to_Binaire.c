#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <Decimal_to_Binaire.h>
#include <stdlib.h>


// Décimal -> Binaire

char *dectobin_v1(unsigned int val) { // nombre entier strictement positif
    char *bin = malloc(33); // Max 32 bits + 1 pour '\0' 
                             // Malloc permet d'allouer dynamiquement de la mémoire
    if (!bin) return NULL; // Vérification de l'allocation mémoire, qu'elle a bien ete faite correctement
                            // qu'un espace mémoire a bien été alloué
                             // Si l'allocation échoue, on retourne NULL

    int started = 0; // hjkswdxfcgvhb
    int index = 0;  // qsdfghjkghhjkl

    for (int i = 31; i >= 0; i--) { // Parcourt les bits de 31 à 0
        unsigned int power = 1u << i; // 2^i avec un shift binaire

        if (val >= power) {  // Si la val est superieure ou égale à 2^i
            started = 1; // il y a un bit 1 trouvé
            bin[index++] = '1'; // Ajoute '1' à la chaîne binaire
            val -= power; // soustraction de la valeur moins 2^i
        } else if (started) {
            bin[index++] = '0'; // Ajoute 0 pour les bits suivants.
        }
    }

    if (index == 0) { // si la valeur est a 0 alors auccun bit a été jouté
        bin[index++] = '0'; // valeur a 0 donc on ajoute 0
    }

    bin[index] = '\0'; // termine la chaine de caractères
    return bin; // renvoie la chaine binaire
}