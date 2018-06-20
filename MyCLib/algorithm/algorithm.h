/*アルゴリズム勉強用ライブラリ*/
/*汎用性のある関数は前方宣言*/
/*2018/04/07作成*/
/*ヘッダ部*/

#pragma once

void swap(int *, int *);

int compare(int *, int *);

int median_3(int, int, int);

int average_3(int, int, int);

unsigned int reversed(unsigned int);

void partition(int *, int, int);

void bubble_sort(int *, int);

void odd_even_sort(int *, int);

void selection_sort(int *, int);

void insertion_sort(int *, int);

void quick_sort_up(int *, int, int);

void quick_sort_down(int *, int, int);
