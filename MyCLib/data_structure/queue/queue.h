#pragma once
#include<stdio.h>

#define QUEUE_DATA_MAX 100

typedef struct{
    int head;
    int tail;
    int data[QUEUE_DATA_MAX];
}Queue;
