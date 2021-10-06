/*ファイル入力*/
#include<stdio.h>

int main(){
    
    FILE *fp = fopen("./sample", "r");
    char s[8][14];
    int cnt = 0;

    while(fgets(s[cnt], 14, fp) != NULL){
        cnt++;
    }

    for(int i = 0; i < 8; i++){
        printf("%s",s[i]);
    }
    
    return 0;
}
