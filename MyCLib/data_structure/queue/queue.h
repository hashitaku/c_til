#ifndef MYCLIB_QUEUE_H
#define MYCLIB_QUEUE_H

#include<stdio.h>

#define QUEUE_DATA_MAX 100

typedef struct{
    int head;
    int tail;
    int data[QUEUE_DATA_MAX];
}Queue;

void queue_init(Queue *);

void queue_enqueue(Queue *, int);

int queue_dequeue(Queue *);

#endif //MYCLIB_QUEUE_H
