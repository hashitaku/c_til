#include"stack.h"

void stack_init(Stack *ptr_struct){
    ptr_struct->top = 0;
}

int stack_full(Stack *ptr_struct){
    if(ptr_struct->top == STACK_DATA_MAX){
        return 0;
    }else{
        return 1;
    }
}

int stack_empty(Stack *ptr_struct){
    if(ptr_struct->top == 0){
        return 0;
    }else{
        return 1;
    }
}

void stack_push(Stack *ptr_struct, int input){
    if(stack_full == 1){
        printf("stack is full\n");
        return;
    }else{
        ptr_struct->data[ptr_struct->top] = input;
        ptr_struct->top++;
    }
}

int stack_pop(Stack *ptr_struct){
    return ptr_struct->data[--ptr_struct->top];
}
