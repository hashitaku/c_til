#ifndef STACK_H
#define STACK_H

#include<stdio.h>

#define STACK_DATA_MAX 100

typedef struct{
    int top;
    int data[STACK_DATA_MAX];
}Stack;

void stack_init(Stack *);

int stack_full(Stack *);

int stack_empty(Stack *);

void stack_push(Stack *, int);

int stack_pop(Stack *);

#endif STACK_H
