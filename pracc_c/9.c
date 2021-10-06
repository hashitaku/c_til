/*配列とポインタ*/
#include<stdio.h>

int main(){

    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int *array_begin = array;
    int *array_end = array + 10;
    int *ptr = &array[10];

    for(; array_begin != array_end; array_begin++){
        printf("%d\n",*array_begin);
    }

    printf("%d\n",array[9]);
    printf("%p\n",&array[9]);
    printf("%p\n",&array[10]);

    printf("%d\n",*ptr);

    return 0;
}
