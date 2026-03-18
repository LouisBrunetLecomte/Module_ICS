#include <stdbool.h>

#define QUEUE_MAX_SIZE 100

typedef struct {
    float data[QUEUE_MAX_SIZE];
    int index;
} Queue;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Init the queue (set q->index to 0...)
 */ 
void init_queue(Queue *q) {
    q->index = 0; // initialisation : la queue est vide
    q->data[0] = '\0'; // caractère de fin de chaine à l'index 0 = chaine vidée
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Enqueue a value to the end of the queue
 * @param q : a Queue structure
 * @param value : a value toe enqueue
 */
void enqueue(Queue *q, float value) {
    q->data[q->index] = value; // la nouvelle valeur est placée à la fin de la queue
    q->index++; // la longueur de la queue a augmenté de 1
    q->data[q->index] = '\0'; // on rajoute à la fin de la queue le caractère de fin de chaine (évite des problèmes de mémoire)
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns the value at the front of the queue
 * @param q : a Queue structure
 * @return float : the value at the front
 */
float dequeue(Queue *q) {
    float front = q->data[0]; // la valeur en début de queue est celle à l'index 0 (première valeur)
    for(int i=0;i<q->index-1;i++){
        q->data[i] = q->data[i+1]; // on décale les nombres vers la gauche :
        //                              chaque nombre prend la valeur de celui qui est à sa droite.
        //                              ([1,2,3] -> 1 devient 2 ; 2 devient 3 ; on a [2,3,3])
    }
    q->index--; // la longueur de la queue baisse de 1 (on enlève un élément)
    q->data[q->index] = '\0'; // le dernier élément devient la fin de chaine (dans notre exemple : [2,3,3,\0] devient [2,3,\0])
    return front;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Check if the queue is empty
 * @param q : a Queue structure
 * @return true|false
 */
bool is_queue_empty(Queue *q) {
    return q->index == 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns the value at the front of the queue without removing it
 * @param q : a Queue structure
 * @return float : the value at the front
 */
float front(Queue *q) { //aka peek
    return q->data[0]; // la valeur en début de queue est celle à l'index 0 (première valeur)
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Reset the queue (similar to init in fact...)
 * @param q : a Queue structure
 */
void clear_queue(Queue *q) {
    q->index = 0;
    q->data[0] = '\0'; // caractère de fin de chaine à l'index 0 = chaine vidée
}