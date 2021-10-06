/*構造体*/
#include<stdio.h>

typedef struct{
    char a1[11];
    char a2[11];
    char a3[11];
    char a4[11];
    char a5[11];
}TIME;

int main(){

    TIME MONDAY;

    scanf("%s",MONDAY.a1);
    scanf("%s",MONDAY.a2);
    scanf("%s",MONDAY.a3);
    scanf("%s",MONDAY.a4);
    scanf("%s",MONDAY.a5);

    printf("%s\n",MONDAY.a1);
    printf("%s\n",MONDAY.a2);
    printf("%s\n",MONDAY.a3);
    printf("%s\n",MONDAY.a4);
    printf("%s\n",MONDAY.a5);

    return 0;

}
