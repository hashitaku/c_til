/*画像データの読み込み*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    unsigned char* ptr_s = (unsigned char*)malloc(sizeof(unsigned char) * 640 * 640 * 4);
	FILE* fp = fopen("as.data", "rb");

	if(fp == NULL){
		printf("error\n");
		return 1;
	}else{
		fread(ptr_s, sizeof(unsigned char), 640 * 640 * 4, fp);
		fclose(fp);
	}

    for(int i = 0; i < 640 * 640 * 4; i++){
        printf("%d ", ptr_s[i]);
    	if(i % 4 == 3){
    		printf("\n");
    	}
    }

    return 0;
}
