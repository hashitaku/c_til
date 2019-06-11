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

int vector_add_size(Vector *ptr_struct, size_t add_size){
    T *ptr_tmp = (T *)realloc(ptr_struct->data, sizeof(T) * (ptr_struct->size + add_size)); //reallocがNULLならメモリリークする可能性あり 一時変数へ
    if(ptr_tmp == NULL){
        fprintf(stderr, "vector resize error\n");
        return EXIT_FAILURE;
    }else{
        ptr_struct->data = ptr_tmp;
        ptr_struct->size += add_size;
        return EXIT_SUCCESS;
    }
}

int vector_resize(Vector *ptr_struct, size_t chenge_size){
    T *ptr_tmp = (T *)realloc(ptr_struct->data, sizeof(T) * (chenge_size));
    if(ptr_tmp == NULL){
        fprintf(stderr, "vector resize error\n");
        return EXIT_FAILURE;
    }else{
        ptr_struct->data = ptr_tmp;
        ptr_struct->size = chenge_size;
        return EXIT_SUCCESS;
    }
}

bool vector_is_full(const Vector *ptr_struct){
    if(ptr_struct->size == ptr_struct->top){
        return true;
    }else{
        return false;
    }
}

int vector_push_back(Vector *ptr_struct, int input){
    if(vector_is_full(ptr_struct) == true){
        vector_add_size(ptr_struct, 1);
        ptr_struct->data[ptr_struct->top] = input;
        ptr_struct->top++;
        return EXIT_SUCCESS;
    }else{
		ptr_struct->data[ptr_struct->top] = input;
		ptr_struct->top++;
		return EXIT_SUCCESS;
    }
}

size_t vector_size(const Vector *ptr_struct){
    return ptr_struct->top;
}

size_t vector_capacity(const Vector *ptr_struct){
    return ptr_struct->size;
}

T *vector_at(Vector *ptr_struct, size_t n){
    if(n >= vector_size(ptr_struct)){
        fprintf(stderr, "vector out of range\n");
        exit(1);
    }

    return &ptr_struct->data[n];
}

T vector_dot(const Vector *ptr_struct1, const Vector *ptr_struct2){
    if(vector_size(ptr_struct1) != vector_size(ptr_struct2)){
        fprintf(stderr, "vector dot size error\n");
        exit(1);
    }

    T retval = 0;

    for(size_t i = 0; i < vector_size(ptr_struct1); i++){
        retval += (ptr_struct1->data[i]) * (ptr_struct2->data[i]);
    }

    return retval;
}
