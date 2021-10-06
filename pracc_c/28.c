/*複合リテラル*/
#include<stdio.h>

typedef struct{
    int num;
}Num;

Num f(){
    return (Num){10}; //複合リテラル
}

int main(){
    
    Num a = {.num = 20}; //指示初期化子

    printf("%d\n", a.num);

    a = f();

    printf("%d\n", a.num);
    
    return 0;
}
