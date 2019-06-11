#include"forward_list.h"

void forward_list_init(Forward_list *ptr_struct){
    if(ptr_struct == NULL){
        fprintf(stderr, "forward_list_init arg nullptr\n");
        exit(1);
    }

    ptr_struct->begin = NULL;
    ptr_struct->end = NULL;
    ptr_struct->size = 0;
}

void forward_list_free(Forward_list *ptr_struct){
    if(ptr_struct == NULL){
        fprintf(stderr, "forward_list_free arg nullptr\n");
        exit(1);
    }

    struct Forward_list_impl *node = ptr_struct->begin;

    while(node != NULL){
        struct Forward_list_impl *next_node = node->next;
        free(node);
        node = next_node;
    }
}

void forward_list_push_back(Forward_list *ptr_struct, T input){
    if(ptr_struct == NULL){
        fprintf(stderr, "forward_list_push_back arg nullptr\n");
        exit(1);
    }

    struct Forward_list_impl *new_node = malloc(sizeof(struct Forward_list_impl));

    if(new_node == NULL){
        fprintf(stderr, "forward_list_push_back malloc error\n");
        exit(1);
    }

    if(ptr_struct->size == 0){
        new_node->next = NULL;
        new_node->data = input;
        ptr_struct->begin = new_node;
        ptr_struct->end = new_node;
    }else{
        new_node->next = NULL;
        new_node->data = input;
        ptr_struct->end->next = new_node;
        ptr_struct->end = new_node;
    }

    ptr_struct->size++;
}

T forward_list_at(Forward_list *ptr_struct, size_t n){
    if(ptr_struct == NULL){
        fprintf(stderr, "forward_list_at arg nullptr\n");
        exit(1);
    }

    if(n >= ptr_struct->size){
        fprintf(stderr, "forward_list_at arg n out of range\n");
        exit(1);
    }

    struct Forward_list_impl *node = ptr_struct->begin;

    for(size_t i = 0; i < n; i++){
        node = node->next;
    }

    return node->data;
}
