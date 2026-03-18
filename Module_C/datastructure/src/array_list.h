/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   array_list.h
 * Author: aurelio
 *
 */

#include <stdbool.h>

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define ARRAY_LIST_MAX_SIZE 100

typedef struct {
    float data[ARRAY_LIST_MAX_SIZE];
    int index;
} Array_list;

/**
 * Init the list structure
 * @param l : an Array_list (cf java ArrayList and LinkedList)
 */
void init_array_list(Array_list *l);

/**
 * Insert a value at a given position in the list l
 * @param l : an Array_list structure
 * @param position : the position of the insertion
 * @param value : a value to insert
 */
void insert_at(Array_list *l, int position, float value);

/**
 * Add the value to the end of the list
 * @param l : an Array_list structure
 * @param value : the value to place at the end of the list
 */
void add(Array_list *l, float value);

/**
 * Remove ant returns the value at position from the list
 * @param l : an Array_list
 * @param position : the position
 * @return float : the value at position
 */
float remove_at(Array_list *l, int position);

/**
 * Returns the value at position without removing it
 * @param l : an Array_list structure
 * @param position the position
 * @return float : the value at position
 */
float get_at(Array_list *l,int position);

/**
 * Clear the list (same s init in fact)
 * @param l : an Array_list structure
 */
void clear_list(Array_list *l);

#endif /* ARRAY_LIST_H */





