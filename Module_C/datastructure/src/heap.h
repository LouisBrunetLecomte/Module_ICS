/* 
 * File:   heap.h
 * Author: aurelio
 *
 */

#include <stdbool.h>

#ifndef HEAP_H
#define HEAP_H


#define HEAP_MAX_SIZE 100

typedef struct {
    float data[HEAP_MAX_SIZE];
    int index;
} Heap;

/**
 * Init the heap 
 */
void init_heap(Heap *h);

/**
 * Check if heap is empty
 * @param h : a Heap structure
 * @return true|false 
 */
bool is_heap_empty(Heap *h);

/**
 * remove an returns the root value from the heap
 * @param h : a Heap structure
 * @return float : The root value
 */
float pop_heap(Heap *h); //pop the root value

/**
 * Add a value to the heap
 * @param h : a Heap structure
 * @param value : the value to add
 */
void push_heap(Heap *h, float value);

/**
 * Returns the root value and put the new value at is place 
 * @param h : a Heap structure
 * @param float : the root value
 * @return float : the root value
 */
float replace(Heap *h, float value); // pop root and push a new key.

/**
 * Returns the root value
 * @param h : a Heap structure
 * @return float : the root value
 */
float peek_heap(Heap *h); // return root value but dont remove it

/**
 * Clear the heap (same as init in fact)
 * @param h : a Heap structure
 */
void clear_heap(Heap *h);

//En option

/**
 * Create heap from an array
 * @param s : a Heap structure to create
 * @param array : the array containing the data
 * @param array_size : the size 
 */
void heapify(Heap *s, float array[], size_t array_size);

/**
 * Merge two heaps 
 * @param dest : destination heap
 * @param src : source heap
 */
void merge(Heap *dest, Heap *src);

#endif /* HEAP_H */




