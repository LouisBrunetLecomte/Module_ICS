/* 
 * File:   queue.h
 * Author: aurelio
 *
 */

#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H


#define QUEUE_MAX_SIZE 100

typedef struct {
    float data[QUEUE_MAX_SIZE];
    int index;
} Queue;

/**
 * Init the queue (set q->index to 0...)
 */ 
void init_queue(Queue *q);

/**
 * Enqueue a value to the end of the queue
 * @param q : a Queue structure
 * @param value : a value toe enqueue
 */
void enqueue(Queue *q, float value);

/**
 * Returns the value at the front of the queue
 * @param q : a Queue structure
 * @return float : the value at the front
 */
float dequeue(Queue *q);

/**
 * Check if the queue is empty
 * @param q : a Queue structure
 * @return true|false
 */
bool is_queue_empty(Queue *q);

/**
 * Returns the value at the front of the queue without removing it
 * @param q : a Queue structure
 * @return float : the value at the front
 */
float front(Queue *q); //aka peek

/**
 * Reset the queue (similar to init in fact...)
 * @param q : a Queue structure
 */
void clear_queue(Queue *q);

#endif /* QUEUE_H */



