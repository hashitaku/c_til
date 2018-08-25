#include"algorithm.h"

void swap(int *data1, int *data2){
    int tmp = *data1;
    *data1 = *data2;
    *data2 = tmp;
}

int max(int data1, int data2){
    if(data1 >= data2){
        return data1;
    }else{
        return data2;
    }
}

int min(int data1, int data2){
    if(data1 >= data2){
        return data2;
    }else{
        return data1;
    }
}

int compare(const int *data1, const int *data2){
    return *(int *)data1 - *(int *)data2;
}

int median_3(int num1, int num2, int num3){
    if(num1 > num2){
        if(num1 < num3){
            return num1;
        }else if(num2 > num3){
            return num2;
        }else{
            return num3;
        }
    }else{
        if(num1 > num3){
            return num1;
        }else if(num2 < num3){
            return num2;
        }else{
            return num3;
        }
    }
}

int average_3(int num1, int num2, int num3){
    return (int)(num1 + num2 + num3) / 3;
}

unsigned int reversed(unsigned int data){

    unsigned int reversed_data = 0;

    while(data != 0){
        reversed_data = (data % 10) + reversed_data * 10;
        data /= 10;
    }

    return reversed_data;
}

void partition(int *ptr_array, int left_index, int right_index){
    int cnt_first = left_index;
    int cnt_second = right_index;

    int pivot = median_3(ptr_array[left_index], ptr_array[right_index], ptr_array[(left_index + right_index) / 2]);

    while(1){
        while(ptr_array[cnt_first] < pivot) cnt_first++;
        while(ptr_array[cnt_second] > pivot) cnt_second--;

        swap(&ptr_array[cnt_first], &ptr_array[cnt_second]);

        if(cnt_first >= cnt_second) break;
    }
}

void bubble_sort(int *ptr_array, int index){
    for(int i = 0; i < index; i++){
        for(int j = index - 1; j > i; j--){
            if(ptr_array[i] > ptr_array[j]){
                swap(&ptr_array[i], &ptr_array[j]);
            }
        }
    }
}

void odd_even_sort(int *ptr_array, int index){

}

void selection_sort(int *ptr_array, int index){
    for(int i = 0; i < index - 1; i++){
        int min = ptr_array[i];
        int k = i;
        for(int j = i + 1; j < index; j++){
            if(min > ptr_array[j]){
                min = ptr_array[j];
                k = j;
            }
        }
        ptr_array[k] = ptr_array[i];
        ptr_array[i] = min;
    }
}

void insertion_sort(int *ptr_array, int index){
    for(int i = 1; i < index; i++){
        int j = i;
        while((j > 0) && (ptr_array[j - 1] > ptr_array[j])){
            swap(&ptr_array[j - 1], &ptr_array[j]);
            j--;
        }
    }
}

void quick_sort_up(int *ptr_array, int left_index, int right_index){
    int cnt_first = left_index;
    int cnt_second = right_index;
    int pivot = median_3(ptr_array[left_index], ptr_array[right_index], ptr_array[(left_index + right_index) / 2]);

    while(1){
        while(ptr_array[cnt_first] < pivot) cnt_first++;
        while(ptr_array[cnt_second] > pivot) cnt_second--;

        swap(&ptr_array[cnt_first], &ptr_array[cnt_second]);

        if(cnt_first >= cnt_second) break;
    }

    if((cnt_first - 1) > left_index) quick_sort_up(ptr_array, left_index, cnt_first - 1);
    if((cnt_second + 1) < right_index) quick_sort_up(ptr_array, cnt_second + 1, right_index);
}

void quick_sort_down(int *ptr_array, int left_index, int right_index){
    int cnt_first = left_index;
    int cnt_second = right_index;
    int pivot = median_3(ptr_array[left_index], ptr_array[right_index], ptr_array[(left_index + right_index) / 2]);

    while(1){
        while(ptr_array[cnt_first] > pivot) cnt_first++;
        while(ptr_array[cnt_second] < pivot) cnt_second--;

        swap(&ptr_array[cnt_first], &ptr_array[cnt_second]);

        if(cnt_first >= cnt_second) break;
    }

    if((cnt_first - 1) > left_index) quick_sort_down(ptr_array, left_index, cnt_first - 1);
    if((cnt_second + 1) < right_index) quick_sort_down(ptr_array, cnt_second + 1, right_index);
}

int gcd(int a, int b){
    if(a < b) swap(&a, &b);
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}
