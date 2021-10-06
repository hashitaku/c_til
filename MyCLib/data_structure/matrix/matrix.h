#ifndef MYCLIB_MATRIX_H
#define MYCLIB_MATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include<complex.h>

typedef struct{
    size_t row;
    size_t column;
    double _Complex *z;
}Matrix;

Matrix make_matrix(size_t row, size_t column);

void free_matrix(Matrix *);

double _Complex *at_matrix(Matrix *, size_t, size_t);

void print_matrix(Matrix *);

#endif //MYCLIB_MATRIX_H
