/*sizeofで配列の要素数を知る。*/
#include<stdio.h>

int main(){

  int num[5];
  int size = 0;

  for(int i = 0; i < 5; i++){
    scanf("%d",&num[i]);
  }

  size = sizeof(num) / sizeof(int);

  printf("%d",size);

  return 0;

}
