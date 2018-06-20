#include<stdio.h>
#include"algorithm/algorithm.h"
#include"data_structure/stack/stack.h"

int main(){

     Stack a;

     for(int i = 0; i < 5; i++){
         int tmp;
         scanf("%d",&tmp);
         stack_push(&a, tmp);
     }

     for(int i = 0; i < 5; i++){
         printf("%d\n",stack_pop(&a));
     }

    return 0;
}
