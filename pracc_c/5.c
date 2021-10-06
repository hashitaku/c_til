/*ポインタ関数*/
#include<stdio.h>

void swap(int *x, int *y);

int main(){

  int a,b;

  scanf("%d %d",&a,&b);

  swap(&a, &b);

  printf("%d %d\n",a,b);

  return 0;

}

void swap(int *px, int *py){

  int tmp = 0;

  tmp = *px;
  *px = *py;
  *py = tmp;

}
