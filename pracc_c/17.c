#include<stdio.h>
#include<unistd.h>

int main(){

    size_t second = 5;

    printf("%zu秒止めます\n",second);

    sleep(second);

    printf("%zu秒止めました\n",second);

    return 0;
}
