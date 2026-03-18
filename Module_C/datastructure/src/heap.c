#include <stdio.h>
#include <stdbool.h>

#define HEAP_MAX_SIZE 100

typedef struct {
    float data[HEAP_MAX_SIZE];
    int index;
} Heap;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Réorganise un sous-arbre pour respecter la propriété du max-heap.
 * @param h : Pointeur vers une structure Heap.
 * @param i : Indice du nœud à partir duquel le tas doit être réorganisé.
 */

void heapify(Heap *h, int i) {
    int largest = i; // Initialise l'index du plus grand nombre comme l'index du nœud courant (la racine au premier tour)
    int left = 2 * i + 1; // Indice de l'enfant gauche
    int right = 2 * i + 2; // Indice de l'enfant droit

    // Vérifie si l'enfant gauche existe et est plus grand que le nœud courant
    if (left < h->index && h->data[left] > h->data[largest]) {
        largest = left; // Met à jour l'indice du plus grand
    }

    // Vérifie si l'enfant droit existe et est plus grand que le plus grand
    if (right < h->index && h->data[right] > h->data[largest]) {
        largest = right; // Met à jour l'indice du plus grand
    }

    // Si le plus grand n'est pas le nœud courant
    if (largest != i) {
        // Échange les valeurs
        float temp = h->data[i];
        h->data[i] = h->data[largest];
        h->data[largest] = temp;

        // Appel récursif pour s'assurer que le sous-arbre reste un max-heap
        heapify(h, largest);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Init the heap 
 */

void init_heap(Heap *h) {
    h->index = 0;
    h->data[0] = '\0';
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Check if heap is empty
 * @param h : a Heap structure
 * @return true|false 
 */

bool is_heap_empty(Heap *h) {
    return h->index == 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * remove an returns the root value from the heap
 * @param h : a Heap structure
 * @return float : The root value
 */

float pop_heap(Heap *h) {
    if (is_heap_empty(h)) {
        return -1; // si le tas est vide, on ne peut pas renvoyer de valeur, on renvoie donc une erreur
    }
    float root = h->data[0];
    h->data[0] = h->data[h->index - 1];
    h->index--;
    heapify(h, 0); // re-heapify
    return root;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Ajoute une valeur à la heap tout en maintenant la propriété de max-heap.
 * @param h : Pointeur vers une structure Heap.
 * @param value : La valeur à ajouter à la heap.
 */

void push_heap(Heap *h, float value) {
    // Vérifie si la heap a encore de la place
    if (h->index < HEAP_MAX_SIZE) {
        // Ajoute la nouvelle valeur à la fin de la heap
        h->data[h->index] = value;
        
        // Indice du nouvel élément
        int i = h->index;
        // Incrémente l'indice pour le prochain ajout
        h->index++;

        // Ajuste la position du nouvel élément pour respecter la max-heap
        // Tant que l'élément n'est pas à la racine (i != 0) et qu'il est plus grand que son parent
        while (i != 0 && h->data[(i - 1) / 2] < h->data[i]) {
            // Échange la valeur avec son parent
            float temp = h->data[i];
            h->data[i] = h->data[(i - 1) / 2];
            h->data[(i - 1) / 2] = temp;

            // Met à jour l'indice pour poursuivre la remontée
            i = (i - 1) / 2;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns the root value
 * @param h : a Heap structure
 * @return float : the root value
 */

float peek_heap(Heap *h) {
    if (!is_heap_empty(h))
        return h->data[0];
    return -1; // si le tas est vide, on ne peut pas renvoyer de valeur, on renvoie donc une erreur
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Clear the heap (same as init in fact)
 * @param h : a Heap structure
 */

void clear_heap(Heap *h) {
    h->index = 0;
    h->data[0] = '\0';
}