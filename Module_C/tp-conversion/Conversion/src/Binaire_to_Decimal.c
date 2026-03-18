#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Binaire_to_Decimal.h"

// Binaire -> Décimal "1010 0110"

int bintodec(char *val) {
    double sum = 0.0; // Somme des valeurs des bits (utilisé comme double pour pow)
    for(int i=0;i<strlen(val);i++) { // Parcourt chaque caractère de la chaîne -> avec strlen
        if(val[i] == '1') { // Si le bit courant vaut 1
            // On ajoute 2^(position) à la somme
            // strlen(val) - i - 1 : position du bit depuis la droite (bit de poids faible = 0)
            sum += pow((double) 2, (double) strlen(val)-i-1); // premier agr est la base le second est l'exposant
        }
    }
    return (int) sum; // Conversion en entier pour retourner le résultat
}


