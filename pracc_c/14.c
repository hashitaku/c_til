/*char* とchar型配列の違い*/
#include<stdio.h>

int main(){

    char *ptr_str;

    //char * はメモリ上に配置されたchar型の文字列の先頭ポインタを表している

    ptr_str = "hello";

    printf("%p\n",ptr_str);

    ptr_str = "bye";//再代入

    printf("%p\n",ptr_str);//文字列が違うのでメモリ上の位置も違う

    return 0;
}
