#include<stdio.h>

int main(){

    int array[10] = {10,9,8,7,6,5,4,3,2,1};

    for(int i = 0; i < 10; i++){
        printf("%d\n",array[i]);
    }

    printf("%p %d\n",array+10, *(array+10));
    printf("%p %d\n",array, *array);
    printf("%p %d\n",array+9, *(array+9));

    return 0;
}
