/*初期化確認用*/
#include<stdio.h>

typedef struct{
    int ar[2];
}Array;

typedef struct{
    int mat[2][2];
}Matrix;

int main(){
    
    Array ar = {1, 2}; //OK

    Matrix mat = {{1, 2}, {3, 4}}; //NG
    
    return 0;
}
