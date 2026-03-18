#include <stdio.h>

/**
* Recherche par dichotomie dans un tableau d'entiers
* @param array The array of values
* @param size_t The size of the array
* @param value The value to find
* @return The position of the value found or -1
*/
/**
 * On a une liste triée
 * on déclare deux valeurs "début" et "fin" qui représentent l'index de la première et la dernière valeur de la liste
 * on regarde la valeur située au milieu de la liste (on prend la valeur à droite du milieu si la liste est paire
 * ex: [1, 2, 3, 4] nombre pair - la moitié de la liste tombe entre deux nombres -> on prendra 3
 * si la valeur du milieu est celle recherchée :
 *  - on renvoie son index (fin de la recherche - on sort de la fonction)
 * si ce n'est pas la valeur recherchée :
 *  - on regarde si la valeur du milieu est inférieure ou supérieure à la valeur recherchée
 *  - si la valeur du milieu est inféireure, "fin" prend comme valeur l'index de la valeur du milieu
 *  - si la valeur du milieu est supérieure, "début" prend comme valeur l'index de la valeur du milieu
 *  - on recommence la procédure
 * fonction dicho( list, size, value )
 *      debut = list[0];
 *      fin = length(list)-1;
 *      millieu = length(list) / 2;
 * 
 *      si (liste = paire) { 
 *          millieu = length(list / 2) + 1
 *      }
 * 
 *      sinon si (value == millieu) {
 *          printf ("Vous avez trouvé du premier coup %f\n" return index(value);
 *      }
 * 
 *      si (value > millieu){
 *          debut = millieu
 *      }
 * 
 *      sinon si (value < millieu) {
 *          fin = millieu
 *      }
 *      appeller dicho(list, list[debut:fin],value)
 * fin fonction 
 * 
 * 
*/


int find_by_dichotomy(int array[], size_t size, int value){
    int debut = 0;
    int fin = size - 1;
    int millieu;
    int i_millieu;
    if (size % 2 == 0) // Si la taille de la list est paire alors 
    {
        i_millieu = (debut + fin) / 2 + 1;
        millieu = array[i_millieu]; //on met a jour le millieu en lui donnant la valeur de la list 
                                        // divisée par deux +1 
    }
    else {  
        i_millieu = (debut + fin) / 2; // 
        millieu = array[i_millieu]; // Ou si la liste est impaire la valeur du millieu de la list seras le millieu.
    }
    
    if(value == millieu) // Si la valeur est celle du millieu de la list
    {
        printf("Vous avez trouvé %d\n", value); // Alors vous avez gagné || %d -> pour les int
        return i_millieu;                                       // return -> sortir de la fonction
                                                                // Donnes l'index de la valeur millieu.
    }
    
    if (value > millieu)        
    {
        debut = millieu;
    }
    else if (value < millieu)
    {
        fin = millieu;
    }
    //find_by_dichotomy(array[debut:fin], fin - debut, value);
}