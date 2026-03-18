/* 
 * File:   stack.h
 * Author: aurelio
 *
 */

#include <stdbool.h>

#define STACK_H

#define STACK_MAX_SIZE 100




typedef struct {
    float data[STACK_MAX_SIZE];
    int index;
} Stack;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Init the stack (set s->index to 0...)
 * @param s : the stack to init
 */

void init_stack(Stack *s) {
    // S est une boite qui contient la variable index
    // Faire en sortes que la pile soit vidée
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i]= -1; // fixe l'index a -1 pour indiquer que Stack est vide.   
    }
    s->index = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Push value to the stack
 * @param s : a Stack structure
 * @param value : the value to store on the stack
 */

void push_stack(Stack *s, float value) {
    // Ajouter dans l'ordre croissant du tableau les éléments les uns apres les autres
    // Empiler les éléments dans la stack qui a été vidée. Les uns avec les autres.
    s->data[s->index] = value;
    s->index = s->index + 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Pop the value at the top of the stack
 * @param s : a stack structure
 * @return float : the value at the top of the stack
 */

float pop_stack(Stack *s) {
    // Faire sortir les derniers éléments qui ont intégrés la liste.
    // si A rentres et B rentres apres, et bien B seras le premier a sortir du tableau.
    // recup val a index -1 avant de la delet 
    int Valstok = s->data[s->index - 1];
    s->data[s->index - 1] = -1;
    s->index = s->index - 1; // deplacer le curseur
    return(Valstok); // print le float.
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Check if stack is empty
 * @param s : the stack
 * @return true|false  
 */

bool is_stack_empty(Stack *s) {
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        if (s->data[i] != -1)
        {
            return  0;
        }
    }
    return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns the value at the top of the stack without removing it
 * @param s : the stack
 * @return float : the value at the top
 */

float peek_stack(Stack *s) {
    return s->data[s->index - 1]; // renvoie l'element s de la list qui est a l'index
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Duplicate the value at the top of the stack
 * @param s : the stack
 */

void dup(Stack *s){
    s->data[s->index] = s->data[s->index - 1]; // le nouvel index est égal a l'ancien dernier index
    s->index = s->index + 1;    // augmente l'index de 1
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Swap the two values at the top of the stack
 * @param s : the stack
 */

void swap(Stack *s){
    float temp = s->data[s->index - 1];
    s->data[s->index - 1] = s->data[s->index - 2];
    s->data[s->index - 2] = temp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Clear the stack. Similar to init_stack. Not very useful.
 * @param s
 */

void clear_stack(Stack *s){
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i]= -1; // fixe l'index a -1 pour indiquer que Stack est vide.   
    }
    s->index = 0;
}




