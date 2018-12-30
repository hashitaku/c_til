#include"./data_init.h"

void data_init(Data *ptr_struct, size_t size){
    ptr_struct->english = (double *)malloc(sizeof(double) * size);
    ptr_struct->math = (double *)malloc(sizeof(double) * size);
    ptr_struct->flag = (int *)malloc(sizeof(int) * size);

    if(ptr_struct->english == NULL){
        fprintf(stderr, "english malloc error\n");
        exit(1);
    }
    
    if(ptr_struct->math == NULL){
        fprintf(stderr, "math malloc error\n");
        free(ptr_struct->english);
        exit(1);
    }

    if(ptr_struct->flag == NULL){
        fprintf(stderr, "flag malloc error\n");
        free(ptr_struct->english);
        free(ptr_struct->math);
        exit(1);
    }
}
