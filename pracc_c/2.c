#include<stdio.h>

int main(){

    int a,b;
	int* ptr;
	
	printf("a:"); scanf("%d",&a);
  	printf("b:"); scanf("%d",&b);
  	printf("a = %d\n",a);
  	printf("b = %d\n",b);

  	ptr = &a;
	
  	printf("&a = %p\n",&a);
  	printf("ptr = %p\n",ptr);
	
  	ptr = &b;
	
  	printf("&b = %p\n",&b);
  	printf("%p\n",ptr);
	
  	*ptr = 10;
	
  	printf("%d\n",b);
  	printf("%d\n",*ptr);
  	printf("%p\n",&b);
  	printf("%p\n",ptr);

  	return 0;
}
