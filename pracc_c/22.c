/*メモリの動的確保のスコープ*/
#include<stdio.h>
#include<stdlib.h>

int main(){

    int* ptr = NULL;

    printf("%p\n",ptr);

    {
    ptr = (int*)calloc(1, sizeof(int));
    *ptr = 10;
    printf("%p\n",ptr);

    free(ptr);
    ptr = NULL;
    }

    printf("%p\n",ptr);

    return 0;
}
