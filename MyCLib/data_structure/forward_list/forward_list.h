#ifndef MYCLIB_FORWARD_LIST_H
#define MYCLIB_FORWARD_LIST_H

#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

typedef int T;

struct Forward_list_node{
    T data;
    struct Forward_list_node *next;
};

typedef struct{
    size_t size;
    struct Forward_list_node *begin;
    struct Forward_list_node *end;
}Forward_list;

void forward_list_init(Forward_list *ptr_struct);
void forward_list_free(Forward_list *ptr_struct);

void forward_list_push_back(Forward_list *ptr_struct, T input);

T forward_list_at(Forward_list *ptr_struct, size_t n);

#endif //MYCLIB_FORWARD_LIST_H
