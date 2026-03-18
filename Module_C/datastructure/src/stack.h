/* 
 * File:   stack.h
 * Author: aurelio
 *
 */

#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 100

typedef struct {
    float data[STACK_MAX_SIZE];
    int index;
} Stack;

/**
 * Init the stack (set s->index to 0...)
 * @param s : the stack to init
 */
void init_stack(Stack *s);

/**
 * Push value to the stack
 * @param s : a Stack structure
 * @param value : the value to store on the stack
 */
void push_stack(Stack *s, float value);

/**
 * Pop the value at the top of the stack
 * @param s : a stack structure
 * @return float : the value at the top of the stack
 */
float pop_stack(Stack *s);

/**
 * Check if stack is empty
 * @param s : the stack
 * @return true|false  
 */
bool is_stack_empty(Stack *s);

/**
 * Returns the value at the top of the stack without removing it
 * @param s : the stack
 * @return float : the value at the top
 */
float peek_stack(Stack *s);

/**
 * Duplicate the value at the top of the stack
 * @param s : the stack
 */
void dup(Stack *s);

/**
 * Swap the two values at the to of the stack
 * @param s : the stack
 */
void swap(Stack *s);

/**
 * Clear the stack. Similar to init_stack. Not very useful.
 * @param s
 */
void clear_stack(Stack *s);


#endif /* STACK_H */

