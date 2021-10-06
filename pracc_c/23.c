/*ファイルの入出力*/
#include<stdio.h>

int main(){

    int a = 10;

    FILE* fp = fopen("sample", "w");

    if(fp == NULL){
        printf("error\n");
        return 1;
    }

    fputs("hello\nas\n",fp);
    fprintf(fp, "%d\n",a);

    fclose(fp);



    return 0;
}
