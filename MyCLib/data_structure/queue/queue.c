#include"queue.h"

void queue_init(Queue *ptr_struct){
    ptr_struct->head = 0;
    ptr_struct->tail = 0;
}
