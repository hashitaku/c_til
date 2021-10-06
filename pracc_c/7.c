/*配列の代入*/
#include<stdio.h>

int main(){

    int a[2][2] = {{1,2},{3,4}};

    a[0][0] = 5;

    char b[3] = {"ab"};

    b[0] = 'c';

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("%c %c\n",b[0],b[1]);

    return 0;

}
