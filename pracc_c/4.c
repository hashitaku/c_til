/*変数のサイズ*/
#include<stdio.h>
#include<stdint.h>

int main(){

    printf("char:%lu\n",sizeof(char));
    printf("int:%lu\n",sizeof(int));
    printf("long int:%lu\n",sizeof(long int));
    printf("long long int:%lu\n",sizeof(long long int));
    printf("double:%lu\n",sizeof(double));
    printf("int8_t:%lu\n",sizeof(int8_t));
    printf("int16_t:%lu\n",sizeof(int16_t));
    printf("int32_t:%lu\n",sizeof(int32_t));
    printf("int64_t:%lu\n",sizeof(int64_t));

    return 0;
}
