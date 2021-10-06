#include"./count_line.h"

size_t count_line(FILE *ptr_file){
    size_t retval = 0;
    int tmp;
    while((tmp = fgetc(ptr_file)) != EOF){
        if(tmp == '\n') retval++;
    }
    rewind(ptr_file);

    return retval;
}
