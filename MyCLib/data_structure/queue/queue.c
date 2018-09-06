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


