#include"vector.h"

int vector_init(Vector *ptr_struct){
    ptr_struct->data = NULL;
    ptr_struct->top = 0;

    ptr_struct->data = (T *)malloc(sizeof(T));
    if(ptr_struct->data == NULL){
    	fprintf(stderr, "vector_init error\n");
    	return EXIT_FAILURE;
    }else{
    	ptr_struct->size = 1;
    	return EXIT_SUCCESS;
    }
}

int vector_free(Vector *ptr_struct){
	if(ptr_struct->size == 0){
        fprintf(stderr, "vector_free error\n");
		return EXIT_FAILURE;
	}else{
		free(ptr_struct->data);
        ptr_struct->size = 0;
		return EXIT_SUCCESS;
	}
}

int vector_clear(Vector *ptr_struct){
	ptr_struct->top = 0;
	return EXIT_SUCCESS;
}

int vector_resize(Vector *ptr_struct, size_t add_size){
        ptr_struct->data = (T *)realloc(ptr_struct->data, sizeof(T) * (ptr_struct->size + add_size));
        if(ptr_struct->data == NULL){
        	fprintf(stderr, "vector resize error\n");
        	return EXIT_FAILURE;
        }else{
        	ptr_struct->size += add_size;
        	return EXIT_SUCCESS;
        }
}

int vector_is_full(Vector *ptr_struct){
    if(ptr_struct->size == ptr_struct->top){
        return true;
    }else{
        return false;
    }
}

int vector_push_back(Vector *ptr_struct, int input){
    if(vector_is_full(ptr_struct) == true){
        vector_resize(ptr_struct, 1);
        ptr_struct->data[ptr_struct->top] = input;
        ptr_struct->top++;
        return EXIT_SUCCESS;
    }else{
		ptr_struct->data[ptr_struct->top] = input;
		ptr_struct->top++;
		return EXIT_SUCCESS;
    }
}
