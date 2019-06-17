#ifndef MYCLIB_LIST_H
#define MYCLIB_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef int T;

struct List_node{
    T data;
    struct List_node *prev;
    struct List_node *next; 
};

typedef struct{
    struct List_node *begin;
    struct List_node *end;
    size_t size;
}List;

int list_init(List *ptr_struct);
void list_free(List *ptr_struct);

void list_push_back(List *ptr_struct, T input);
void list_push_front(List *ptr_struct, T input);

void list_print(const List *ptr_struct);

#endif //MYCLIB_LIST_H
