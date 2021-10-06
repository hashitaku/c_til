/*reacclocなど*/
#include<stdio.h>
#include<stdlib.h>

int main(){

    void *ptr = (void *)malloc(sizeof(int));

    if(ptr == NULL){
        return 1;
    }

    printf("%p\n",ptr);

    ptr = (void *)realloc(ptr, sizeof(int) * 2);

    if(ptr == NULL){
        return 1;
    }

    printf("%p\n",ptr);

    free(ptr);

    return 0;
}
