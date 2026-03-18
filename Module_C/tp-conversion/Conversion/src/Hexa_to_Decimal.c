#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <Hexa_to_Decimal.h>

// Hexadécimal -> Décimal

int hexatodec(const char *val) { 
    int sum = 0; // Stocke le résultat final
    char c; // Caractère courant
    int digit; // Valeur décimale du caractère hexadécimal


    for (int i = 0; val[i] != '\0'; i++) { // Parcourt chaque caractère de la chaîne jusqu'à la fin '\0'
        c = toupper(val[i]); // transforme 'a'-'f' en 'A'-'F'


        if (c >= '0' && c <= '9') {
            digit = c - '0'; // Convertit '0'-'9' en 0-9
        } 
        
        else if (c >= 'A' && c <= 'F') {
            digit = 10 + (c - 'A'); // Convertit 'A'-'F' en 10-15
        } 
        
        else {
            continue; // prend pas en compte les autres caractères.
        }

        sum = sum * 16 + digit;   // Décalage à gauche en base 16 + ajout du chiffre courant
                                // "AB" -> (0*16 + 10) = 10 ; (10*16 + 11) = 171 ; (11*16 + 12) = 2748 ; ...
    }

    return sum; // retourne le résultat final en décimal
}