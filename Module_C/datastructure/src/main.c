/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "heap.h"
#include "queue.h"
#include "heap.h"
#include "array_list.h"
#include "stack.h"

void test(int a) {

    //exemple d'utilisation des assertions 
    assert(a == 5); // use -DNDEBUG to disable assertions in makefile or #define NDEBUG

    // et de la gestion des erreurs...
    errno = a;
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
}

/*
 * 
 */
int main(int argc, char** argv) {
    printf("-----TEST HEAP-----\n");
    Heap *h = malloc(sizeof(Heap));
    init_heap(h);
    push_heap(h, 100.0);
    push_heap(h, 70.0);
    push_heap(h, 80.0);
    printf("Voici peek_heap : %f\n", peek_heap(h) );
    printf("Voici pop_heap : %f\n", pop_heap(h) );
    printf("is peek_heap empty : %d\n", is_heap_empty(h) ); 
    clear_heap(h);
    printf("Voici peek_heap : %f\n", peek_heap(h) );


    printf("-----TEST ARRAY LIST-----\n");
    Array_list *s = malloc(sizeof(Array_list));
    init_array_list(s);
    add(s, 2.0);
    add(s, 3.0);
    insert_at(s, 1, 4.0);
    printf("Voici get_at : %f\n", get_at(s, 1) );
    remove_at(s, 1);
    add(s, 12.0);
    printf("Voici get_at : %f\n", get_at(s, 0));
    printf("Voici get_at : %f\n", get_at(s, 1));
    printf("Voici get_at : %f\n", get_at(s, 2));
    clear_list(s);
    printf("Voici la longueur de s : %d\n", s->index);

    printf("-----TEST QUEUE-----\n");
    Queue *q = malloc(sizeof(Queue));
    init_queue(q);
    enqueue(q, 5.0);
    enqueue(q, 6.0);
    enqueue(q, 7.0);
    enqueue(q, 8.0);
    is_queue_empty(q);
    printf("Voici dequeue : %f\n", dequeue(q));
    printf("la queue est elle vide ? %d\n", is_queue_empty(q));
    front(q);
    printf("la valeur en front est : %f\n", front(q));
    clear_queue(q);
    is_queue_empty(q);
    printf("la queue est elle vide ? %d\n", is_queue_empty(q));
    dequeue(q);
    printf("Voici dequeue : %f\n", dequeue(q));

    printf("-----TEST STACK-----\n");
    Stack *t = malloc(sizeof(Stack));
    init_stack(t);
    push_stack(t, 10.0);
    push_stack(t, 20.0);
    push_stack(t, 30.0);
    dup(t);
    swap(t);
    is_stack_empty(t);
    printf("la stack est elle vide ? %d\n", is_stack_empty(t));
    pop_stack(t);
    printf("Voici pop_stack : %f\n", pop_stack(t));
    peek_stack(t);
    printf("Voici peek_stack : %f\n", peek_stack(t));
    clear_stack(t);
    is_stack_empty(t);
}

// %f pour float
// %d pour int
// %s pour string