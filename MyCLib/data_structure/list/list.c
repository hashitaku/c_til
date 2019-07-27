#include"list.h"

int list_init(List *ptr_struct){
    if(ptr_struct == NULL){
        fprintf(stderr, "list_init arg nullptr\n");
        exit(1);
    }

    ptr_struct->begin = NULL;
    ptr_struct->end = NULL;
    ptr_struct->size = 0;

    return EXIT_SUCCESS;
}

void list_free(List *ptr_struct){
    while(ptr_struct->begin != NULL){
        struct List_node *next_node = ptr_struct->begin->next;
        free(ptr_struct->begin);
        ptr_struct->begin = next_node;
    }
}

void list_push_back(List *ptr_struct, T input){
    if(ptr_struct == NULL){
        fprintf(stderr, "list_push_back arg nullptr\n");
        exit(1);
    }

    struct List_node *new_node = malloc(sizeof(struct List_node));

    if(new_node == NULL){
        fprintf(stderr, "list_push_back malloc error\n");
        exit(1);
    }

    if(ptr_struct->size == 0){
        new_node->data = input;
        new_node->next = NULL;
        new_node->prev = NULL;
        ptr_struct->end = new_node;
        ptr_struct->begin = new_node;
    }else{
        new_node->data = input;
        new_node->next = NULL;
        new_node->prev = ptr_struct->end;
        ptr_struct->end->next = new_node;
        ptr_struct->end = new_node;
    }

    ptr_struct->size++;
}

void list_push_front(List *ptr_struct, T input){
    if(ptr_struct == NULL){
        fprintf(stderr, "list_push_front arg nullptr\n");
        exit(1);
    }

    struct List_node *new_node = malloc(sizeof(struct List_node));

    if(new_node == NULL){
        fprintf(stderr, "list_push_front malloc error\n");
        exit(1);
    }

    if(ptr_struct->size == 0){
        new_node->data = input;
        new_node->next = NULL;
        new_node->prev = NULL;
        ptr_struct->end = new_node;
        ptr_struct->begin = new_node;
    }else{
        new_node->data = input;
        new_node->prev = NULL;
        new_node->next = ptr_struct->begin;
        ptr_struct->begin->prev = new_node;
        ptr_struct->begin = new_node;
    }

    ptr_struct->size++;
}

void list_print(const List *ptr_struct){
    struct List_node *node = ptr_struct->begin;
    while(node != NULL){
        printf("%d\n", node->data);
        node = node->next;
    }
}


