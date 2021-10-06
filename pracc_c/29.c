/*ファイルディスプリクタ*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    
    int fd = open("sample", O_RDWR);

    printf("%d\n", fd);

    close(fd);
    
    return 0;
}
