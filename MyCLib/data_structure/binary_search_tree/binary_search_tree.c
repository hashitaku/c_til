#include"binary_search_tree.h"

void binary_search_tree_init(Binary_search_tree *ptr_struct){
    if(ptr_struct == NULL){
        fprintf(stderr, "binary_search_tree_init arg nullptr\n");
        exit(1);
    }

    ptr_struct->root = NULL;
}

// impl function
static void binary_search_tree_node_free(Binary_search_tree_node *node){
    if(node == NULL) return;
    binary_search_tree_node_free(node->left);
    binary_search_tree_node_free(node->right);
    free(node);
}

void binary_search_tree_free(Binary_search_tree *ptr_struct){
    if(ptr_struct == NULL){
        fprintf(stderr, "binary_search_tree_free arg nullptr\n");
        exit(1);
    }

    binary_search_tree_node_free(ptr_struct->root);
}

void binary_search_tree_insert(Binary_search_tree* ptr_struct, Tp input){
    if(ptr_struct == NULL){
        fprintf(stderr, "binary_search_tree_insert arg nullptr\n");
        exit(1);
    }

    Binary_search_tree_node *new_node = malloc(sizeof(Binary_search_tree_node));

    if(new_node == NULL){
        fprintf(stderr, "binary_search_tree_insert malloc error\n");
        exit(1);
    }

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = input;

    if(ptr_struct->root == NULL){
        ptr_struct->root = new_node;
    }else{
        Binary_search_tree_node *look_node = ptr_struct->root;
        Binary_search_tree_node *look_node_prev = ptr_struct->root;

        while(look_node != NULL){
            if(look_node->data >= input){
                look_node_prev = look_node;
                look_node = look_node->left;
            }else{
                look_node_prev = look_node;
                look_node = look_node->right;
            }
        }

        if(look_node_prev->data >= input){
            look_node_prev->left = new_node;
        }else{
            look_node_prev->right = new_node;
        }
    }
}

// impl function
static void binary_search_tree_print_impl(Binary_search_tree_node *node, size_t depth){
    if(node == NULL){
        if(depth != 0) depth--;
        return;
    }

    for(size_t i = 0; i < depth * 4; i++) printf("%c", ' ');

    depth++;

    printf("|--[%d]\n", node->data);
    binary_search_tree_print_impl(node->left, depth);
    binary_search_tree_print_impl(node->right, depth);
}

void binary_search_tree_print(Binary_search_tree *ptr_struct){
    if(ptr_struct == NULL){
        fprintf(stderr, "binary_search_tree_print arg nullptr\n");
        exit(1);
    }


    binary_search_tree_print_impl(ptr_struct->root, 0);
}

