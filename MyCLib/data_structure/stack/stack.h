#pragma once

typedef struct{
    int top;
    int data[100];
}Stack;

void stack_init(Stack *);

int stack_full(Stack *);

int stack_empty(Stack *);

void stack_push(Stack *, int);

int stack_pop(Stack *);
