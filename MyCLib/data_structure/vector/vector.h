#ifndef VECTOR_H
#define VECTOR_H

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<stdbool.h>

typedef struct{
    int *data;
    size_t size;
    size_t top;
}Vector;

int vector_init(Vector *ptr_struct);

int vector_free(Vector *ptr_struct);

int vector_clear(Vector *ptr_struct);

int vector_resize(Vector *ptr_struct, size_t add_size);

int vector_is_full(Vector *ptr_struct);

int vector_push_back(Vector *ptr_struct, int input);

#endif VECTOR_H
