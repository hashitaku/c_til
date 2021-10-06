/*関数ポインタとtypedef*/

#include <stdio.h>

int f(int);

int f2(int, int);

typedef int (*PTR_FUNC) (int, int);

int main(){

    int (*ptr_func) (int);
    PTR_FUNC ptr_func2 = f2;

    ptr_func = f;

    printf("%d\n",ptr_func(10));
    printf("%d\n",ptr_func2(10, 10));

    return 0;
}

int f(int a){
    return a * 2;
}

int f2(int a, int b){
    return a * b;
}
