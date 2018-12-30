#include"./data_input.h"

void data_input(FILE *ptr_file, Data *ptr_struct){
    size_t line = count_line(ptr_file);

    for(size_t i = 0; i < line; i++){
        fscanf(ptr_file, "%lf %lf %d\n", &ptr_struct->english[i], &ptr_struct->math[i], &ptr_struct->flag[i]);
    }

    rewind(ptr_file);
}
