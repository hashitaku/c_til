#include"queue.h"

typedef struct{
    int head;
    int tail;
    int data[QUEUE_DATA_MAX];
}Queue;

void queue_init(Queue *ptr_struct){
    ptr_struct->head = 0;
    ptr_struct->tail = 0;
}

void queue_enqueue(Queue *ptr_struct, int input){
    ptr_struct->data[ptr_struct->head] = input;
    ptr_struct->head++;
}

int queue_dequeue(Queue *ptr_struct){
    return ptr_struct->data[ptr_struct->tail--];
}
