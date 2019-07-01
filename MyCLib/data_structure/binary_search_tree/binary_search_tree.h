#ifndef MYCLIB_BINARY_SEARCH_TREE
#define MYCLIB_BINARY_SEARCH_TREE

#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

typedef int Tp;

typedef struct Binary_search_tree_node{
    Tp data;
    struct Binary_search_tree_node *left;
    struct Binary_search_tree_node *right;
}Binary_search_tree_node;

typedef struct{
    Binary_search_tree_node *root;
}Binary_search_tree;

void binary_search_tree_init(Binary_search_tree *ptr_struct);
void binary_search_tree_free(Binary_search_tree *ptr_struct);

void binary_search_tree_insert(Binary_search_tree* ptr_struct, Tp input);

void binary_search_tree_print(Binary_search_tree *ptr_struct);

#endif //MYCLIB_BINARY_SEARCH_TREE
