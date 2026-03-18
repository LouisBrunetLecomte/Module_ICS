
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <Decimal_to_Hexa.h>
#include <stdlib.h>


// Décimal -> Hexadécimal

char *dectohexa(unsigned int val) { // nombre entier strictement positif
    char hexChars[] = "0123456789ABCDEF"; // juste décrit les caractères hexadécimaux
    char *hex = malloc(33); // Allocation dynamique de 33 caractères (suffisant pour 32 bits + '\0')
                                // Malloc permet d'allouer dynamiquement de la mémoire
    if (!hex) return NULL; // Verifie malloc

    int i = 0; 

    if (val == 0) { // Cas particulier : si la valeur est 0
        hex[i++] = '0'; // On écrit "0" dans la chaîne
    } else {
        while (val > 0) { // Tant que la valeur n’est pas nulle
            hex[i++] = hexChars[val % 16]; // On récupère le chiffre hexadécimal correspondant au reste de la division par 16
            val /= 16; // On divise la valeur par 16 pour passer au chiffre suivant
        }
    }

    hex[i] = '\0'; // Termine la chaîne de caractères

    // inverser la chaine parceque elle est faite a l'envers
    for (int j = 0; j < i / 2; j++) { // parcours jusqu'à la moitié du tableau
        char temp = hex[j]; // mettre dans la poche la valeur de j
        hex[j] = hex[i - j - 1]; // remplacer la valeur de j par celle qui lui est symétriquement opposée. 
        hex[i - j - 1] = temp; // placer le caractère temp a la fin.
    }
    
    return hex; // Retourne la chaîne hexadécimale
}
