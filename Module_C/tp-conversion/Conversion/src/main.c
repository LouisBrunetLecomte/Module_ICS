#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Binaire_to_Decimal.h"
#include "Hexa_to_Decimal.h"
#include "Decimal_to_Hexa.h"
#include "Decimal_to_Binaire.h"
#include "Décimal_to_Binaire_v2.h"

int main() {
    printf("Voici le résultat de bintodec : %d \n" ,bintodec ("101001"));
    printf("Voici le résultat de hexatodec : %d \n" ,hexatodec ("1A"));
    printf("Voici le résultat de dectohexa : %s \n" ,dectohexa (21));
    printf("Voici le résultat de dectobin_v1 : %s \n" ,dectobin_v1 (15));
    printf("Voici le résultat de dectobin_v2: %s \n" ,dectobin_v2 (40));
    return 0;
}

// %d signifie que l'on affiche un entier
// %s signifie que l'on affiche une chaîne de caractères
// \n signifie un retour à la ligne