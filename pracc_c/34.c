/*C言語でカリー化*/

#include<stdio.h>

typedef int (*ptr_func_t)(int);

int plus(int, int);
int internal_plus(int);
ptr_func_t curried_plus(int);

ptr_func_t pf = internal_plus; //戻り値の関数ポインタをグローバル変数へ
int internal_num; //キャプチャないから...

int main(){

    ptr_func_t plus_one = curried_plus(3); //部分適用

    printf("%d\n", plus(3, 5));
    printf("%d\n", curried_plus(3)(5));
    printf("%d\n", plus_one(3));
    
    return 0;
}

int plus(int a, int b){
    return a + b;
}

int internal_plus(int x){
    return internal_num + x;
}

ptr_func_t curried_plus(int x){
    internal_num = x;
    return pf;
}

