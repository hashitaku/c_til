#include<stdio.h>

void add(int *, int *);

int main(){

  int x,y;

  scanf("%d",&x);
  scanf("%d",&y);

  add(&x,&y);

  printf("x = %d\n",x);
  printf("y = %d\n",y);

  return 0;

}

void add(int *px, int *py){
  *px = *px + 10;
  *py = *py + 10;
}
