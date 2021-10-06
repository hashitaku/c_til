#include<stdio.h>

void func(const char *, const char *);

int main(){

    const char *str1 = "hello";
    const char *str2 = "bye";

    printf("%p\n%p\n",str1, str2);

    func(str1, str2);

    printf("%s\n",str1);
    printf("%s\n",str2);

    printf("%p\n%p\n",str1, str2);

    return 0;
}

void func(const char *str1, const char *str2){

    const char *tmp;

    tmp  = str1;
    printf("%s %s %s\n",str1, str2, tmp);
    str1 = str2;
    printf("%s %s %s\n",str1, str2, tmp);
    str2 = tmp;
    printf("%s %s %s\n",str1, str2, tmp);
    printf("%p\n%p\n",str1, str2);
}
