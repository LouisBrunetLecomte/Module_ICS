#include <stdio.h>
#include "all_sorts.h"

/**
 * @brief Trie un tableau en utilisant l'algorithme du tri à bulles.
 * 
 * Cette fonction trie un tableau de nombres à virgule flottante dans l'ordre croissant
 * en utilisant l'algorithme du tri à bulles. L'algorithme parcourt le tableau à plusieurs reprises,
 * compare les éléments adjacents et les échange s'ils ne sont pas dans le bon ordre.
 * 
 * @param tab Un pointeur vers le tableau de floats à trier.
 * @param size Le nombre d'éléments dans le tableau.
 */

void sort_bubble(float tab[], size_t size) {
    float temp; // Variable temporaire pour stocker une valeur lors d'un échange

    for(int j=0;j<(int)size-1;j++) { // parcours le tableau plusieurs fois.

        for(int i=0;i<(int)size-j-1;i++) { // compare les éléments
                                           // "(int)size" sert à convertir size_t en int
            
            if(tab[i] > tab[i+1]) { // Si i est plus grand que i+1, on échange les deux valeurs
                temp = tab[i];  // Stocke i dans temp
                tab[i] = tab[i+1]; // Remplace i par i+1
                tab[i+1] = temp; // Remplace i+1 par temp (ancienne valeur de i)
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////HEURE-est il ?

/**
 * @brief Trie un tableau en utilisant l’algorithme du tri par sélection.
 * 
 * Cette fonction trie un tableau de nombres à virgule flottante (float) dans l’ordre croissant
 * en appliquant l’algorithme du tri par sélection.
 * 
 * Le principe : le tableau est divisé en deux parties — une partie triée et une partie non triée.
 * À chaque itération, on cherche le plus petit élément dans la partie non triée
 * et on l’échange avec le premier élément de cette partie.
 * 
 * @param tab Pointeur vers le tableau de nombres flottants à trier.
 * @param size Nombre d’éléments présents dans le tableau.
 */

void sort_selection(float tab[], size_t size) {

    float min, temp; // déclare deux variables min (plus petite val) et temp (pour stocker une valeur temporairement)
    int imin;   // variable retenir l'indice du minimum

    for(int i=0;i<(int)size;i++) { // parcourt tout le tableau
        min = tab[i]; // le plus petit élément = position i
        imin = i;  // Mémorise l’indice de cet élément

        for(int z=i;z<(int)size;z++) { // cherche le plus petit élément dans la partie non triée (à partir de i)
            
            if(tab[z] < min) { // si on trouve un élément plus petit que min
                min = tab[z]; // min prend cette valeur
                imin = z; // on mémorise l'indice de la nouvelle valeur de min
            }

        }
        // Une fois le plus petit élément trouvé, on l’échange avec l’élément à la position i
        temp = tab[i]; // Avant de mettre la plus petite valeur trouvée min à la position i, on met la valeur actuelle de tab[i] dans une variable temporaire (temp).
        tab[i] = min; // la plus petite valeur prend la position de i 
        tab[imin] = temp; // On remet l’ancienne valeur de tab[i] à la position du plus petit élément.
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////HEURE-éka

/**
 * @brief Trie un tableau en utilisant l’algorithme du tri par insertion.
 * 
 * Cette fonction trie un tableau de nombres à virgule flottante (float) dans l’ordre croissant
 * en appliquant l’algorithme du tri par insertion.
 * 
 * Principe : le tableau est parcouru élément par élément.  
 * À chaque étape, on prend un élément et on le place à la bonne position
 * dans la partie déjà triée du tableau, en décalant les autres si nécessaire.
 * 
 * @param tab Pointeur vers le tableau de nombres flottants à trier.
 * @param size Nombre d’éléments présents dans le tableau.
 
 * TRI PAR INSERTION
 * N = longueur(T)
 * POUR i variant de 1 à N - 1 :
 * Prendre l’élément T[i] (l’élément à insérer)
 * Comparer T[i] avec les éléments précédents du tableau (T[0] à T[i-1])
 * Tant que T[i] est plus petit qu’un élément précédent :
 * Décaler cet élément vers la droite
 * Insérer T[i] à la bonne position (là où il n’y a plus d’élément plus grand à gauche)
 * FIN POUR
 *
 *Algorithme qui permet de trier de façon croissante une liste. Les uns apres les autres.
 *Analyser i comparé a i+1, si i > i+1 alors interposer i avec i+1. Répéter ca pour toutes les cases du tableau
 *Si i est suppérieur aux autres itérations de la chaine, alors placer le chiffre le plus petit des deux dans la chaine, et garder en mémoire le plus grand.
 *Recommencer tant que la length(T)-1 n'est pas atteinte.
 */


 void sort_insertion(float tab[], size_t size) {       

    for (int i = 1; i < (int)size; i++) { // Parcours du tableau à partir du deuxième élément (indice 1) jusqu'à la fin
        
        float element = tab[i];  // On garde l'élément courant à insérer dans la partie triée
        int j = i; // j sert à parcourir la partie triée du tableau (vers la gauche)

        // Tant qu'on n'est pas au début du tableau et que l'élément précédent est plus grand que "element"
        while (j > 0 && tab[j - 1] > element) {
            tab[j] = tab[j - 1]; // On décale l'élément plus grand vers la droite
            j--; // On recule dans la partie triée pour continuer à comparer
        }

        tab[j] = element; // On insère l'élément à sa place correcte dans la partie triée
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////HEURE-usement

/**
 * @brief Trie un tableau en utilisant l’algorithme du tri par tas (heap sort).
 * 
 * Cette fonction trie un tableau de nombres à virgule flottante (float) dans l’ordre croissant.
 * L’algorithme construit d’abord une structure de type “tas maximal” (max heap),
 * puis extrait le plus grand élément pour le placer à la fin du tableau.
 * Cette opération est répétée jusqu’à ce que tout le tableau soit trié.
 * 
 * @param tab Pointeur vers le tableau de nombres flottants à trier.
 * @param size Nombre d’éléments présents dans le tableau.
 * 
 * TRI PAR SELECTION(T) :
 * N = longueur(T)
 * POUR i variant de N-1 `a 1 par pas de -1:
 * k = indice du Maximum dans le sous-tableau de T allant jusqu’`a
 * l’indice i
 * Echanger T[i] et T[k]
 * FIN POUR
 */
void sort_tas(float tab[], size_t size) {
    
    for (int i = size - 1; i > 0; i--) { // Parcourt le tableau de la fin vers le début (i de size - 1 à 1)
        int k = 0; // On suppose que le maximum est à l'indice 0 au début

        for (int j = 1; j <= i; j++) { // Cherche l'indice du maximum dans le sous-tableau [0..i]
            if (tab[j] > tab[k]) {
                k = j; // Nouveau maximum trouvé, on garde son indice
            }
        }

        // Échange tab[i] et tab[k] pour placer le maximum à sa bonne position
        float temp = tab[i]; // On sauvegarde la valeur à la position i
        tab[i] = tab[k]; // On met le maximum trouvé à la position i
        tab[k] = temp; // On remet l’ancienne valeur de tab[i] à la position du maximum
    }
}