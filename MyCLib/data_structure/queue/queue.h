#pragma once
#include<stdio.h>

#define QUEUE_DATA_MAX 100

typedef struct Queue;

void queue_init(Queue *);

void queue_enqueue(Queue *, int);

int queue_dequeue(Queue *);
