#ifndef MYCLIB_LIST_H
#define MYCLIB_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef int T;

struct List_impl{
    T data;
    struct List_impl *prev;
    struct List_impl *next; 
};

typedef struct{
    struct List_impl *begin;
    struct List_impl *end;
    size_t size;
}List;

int list_init(List *ptr_struct);
void list_free(List *ptr_struct);

void list_push_back(List *ptr_struct, T input);
void list_push_front(List *ptr_struct, T input);

void list_print(const List *ptr_struct);

#endif //MYCLIB_LIST_H
