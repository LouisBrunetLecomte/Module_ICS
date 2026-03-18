#include <stdbool.h>
#include <stdio.h>

#define ARRAY_LIST_H

#define ARRAY_LIST_MAX_SIZE 100

typedef struct {
    float data[ARRAY_LIST_MAX_SIZE];
    int index;
} Array_list;

/**
 * Initialise la structure de liste
 * @param l : une Array_list (similaire aux classes ArrayList et LinkedList en Java)
 */

void init_array_list(Array_list *l) {
    l->index = 0; // initialisation : la queue est vide
    l->data[0] = '\0'; // caractère de fin de chaine à l'index 0 = chaine vidée
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Insère une valeur à une position donnée dans la liste l
 * @param l : une structure de type Array_list
 * @param position : la position où insérer la valeur
 * @param value : la valeur à insérer
 */

void insert_at(Array_list *l, int position, float value) {
    for(int i=position;i<l->index-1;i++){
        l->data[i] = l->data[i+1];
    }
    // on augmente la longueur de la liste après le décalage pour éviter que \0 soit copié dans l'avant dernier élément.
    l->index++; // la longueur de la liste baisse de 1 (on enlève un élément)
    l->data[l->index] = '\0'; // le dernier élément devient la fin de chaine (dans notre exemple : [2,3,3,\0] devient [2,3,\0])
    l->data[position] = value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Ajoute une valeur à la fin de la liste
 * @param l : une structure de type Array_list
 * @param value : la valeur à placer à la fin de la liste
 */

void add(Array_list *l, float value) {
    l->data[l->index] = value; // la nouvelle valeur est placée à la fin de la queue
    l->index++; // la longueur de la queue a augmenté de 1
    l->data[l->index] = '\0'; // on rajoute à la fin de la queue le caractère de fin de chaine (évite des problèmes de mémoire)
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Supprime et renvoie la valeur à la position indiquée dans la liste
 * @param l : une structure de type Array_list
 * @param position : la position de l’élément à supprimer
 * @return float : la valeur présente à cette position
 */

float remove_at(Array_list *l, int position) {
    float to_remove = l->data[position]; // la valeur en début de queue est celle à l'index 0 (première valeur)
    for(int i=position;i<l->index-1;i++){
        l->data[i] = l->data[i+1]; // on décale les nombres vers la gauche :
        //                              chaque nombre prend la valeur de celui qui est à sa droite.
        //                              ([1,2,3] -> 1 devient 2 ; 2 devient 3 ; on a [2,3,3])
    }
    l->index--; // la longueur de la queue baisse de 1 (on enlève un élément)
    l->data[l->index] = '\0'; // le dernier élément devient la fin de chaine (dans notre exemple : [2,3,3,\0] devient [2,3,\0])
    return to_remove;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Renvoie la valeur à une position donnée sans la supprimer
 * @param l : une structure de type Array_list
 * @param position : la position de l’élément
 * @return float : la valeur présente à cette position
 */
float get_at(Array_list *l, int position) {
    return l->data[position];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Vide la liste (équivalent à l'initialisation)
 * @param l : une structure de type Array_list
 */
void clear_list(Array_list *l) {
    l->index = 0; // initialisation : la queue est vide
    l->data[0] = '\0'; // caractère de fin de chaine à l'index 0 = chaine vidée
}






