/*ダブルクォーテーションとシングルクォーテーションの違い*/
#include<stdio.h>

int main(){

    char *str1 = "as";
    char *str2 = "a";
    char s = 'a';

    printf("文字列%sの先頭ポインタは%p\n","as", "as");//ダブルクォーテーションに囲まれた文字列はポインタを表している
    printf("変数str1の先頭ポインタは%p\n",str1);//同じ文字列はメモリの節約のため同じ位置

    printf("変数str2の先頭ポインタは%p\n",str2);
    printf("変数sのポインタは%p\n",&s);//文字列変数と文字変数ではメモリの位置も違う(中身は同じaなのに...\0があるかないか)

    printf("%p\n",(char *)'a');//これは謎
    printf("%p\n",(int *)7);//メモリ領域の問題?

    return 0;
}
