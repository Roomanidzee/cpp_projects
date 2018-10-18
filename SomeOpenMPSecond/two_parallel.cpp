//
// Created by andrey on 23.09.18.
//
#include <iostream>
#include <omp.h>
#define ARRAY_SIZE 12
#define THREAD_NUM_1 3
#define THREAD_NUM_2 4
#define ITERATIONS_COUNT 4

int main(){

    int a[ARRAY_SIZE], b[ARRAY_SIZE], c[ARRAY_SIZE];

    omp_set_num_threads(THREAD_NUM_1);
    printf("Статическое распределение: \n");

    #pragma omp parallel for schedule(static, ITERATIONS_COUNT)
    for(int i = 0; i < ARRAY_SIZE; i++){
        a[i] = i;
        b[i] = i;
        printf("Количество нитей: %d, номер нити: %d, a[i] = %d, b[i] = %d\n",
                omp_get_max_threads(), omp_get_thread_num(), a[i], b[i]);
    }
    printf("\n");

    printf("Динамическое распределение: \n");

    omp_set_num_threads(THREAD_NUM_2);

    #pragma omp parallel for schedule(dynamic, ITERATIONS_COUNT)
    for(int i = 0; i < ARRAY_SIZE; i++){
        c[i] = a[i] + b[i];
        printf("Количество нитей: %d, номер нити: %d, c[i] = %d\n",
               omp_get_max_threads(), omp_get_thread_num(), c[i]);
    }
    printf("\n");

    return 0;
}