#include"./matrix.h"

Matrix make_matrix(size_t row, size_t column){
    Matrix retval;

    retval.row = row;
    retval.column = column;
    retval.z = (double _Complex *)malloc(sizeof(double _Complex) * row * column);

    if(retval.z == NULL){
        fprintf(stderr, "make_matrix error\n");
        exit(1);
    }

    return retval;
}

void free_matrix(Matrix *ptr_struct){
    free(ptr_struct->z);
}

double _Complex *at_matrix(Matrix *ptr_struct, size_t n, size_t m){
    if(ptr_struct->row - 1 < n || ptr_struct->column - 1 < m){
        fprintf(stderr, "matrix out of range\n");
        exit(1);
    }

    return &ptr_struct->z[ptr_struct->column * n + m];
}

void print_matrix(Matrix *ptr_struct){
    for(size_t i = 0; i < ptr_struct->row; i++){
        for(size_t j = 0; j < ptr_struct->column; j++){
            printf("%g%+gi  ", creal(*at_matrix(ptr_struct, i, j)), cimag(*at_matrix(ptr_struct, i, j)));
        }printf("\n");
    }
}
