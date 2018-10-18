//
// Created by andrey on 20.09.18.
//
#include <iostream>
#include <omp.h>
#define N1 2
#define N2 4

int main(){
    
    int a = 0, b = 0;
    
    printf("До входа в параллельную область №1: a = %d, b = %d \n", a, b);
    printf("\n");

#pragma omp parallel num_threads(N1) private(a) firstprivate(b)
    {
        int thread_num = omp_get_thread_num();
        printf("Номер потока: %d \n", thread_num);
        a += thread_num;
        b += thread_num;
        printf("Изменение a и b для потока №%d : a = %d, b = %d \n", thread_num, a, b);
        printf("\n");
    };

    printf("После входа в параллельную область №1: a = %d, b = %d \n", a, b);
    printf("\n");

    printf("До входа в параллельную область №2: a = %d, b = %d \n", a, b);
    printf("\n");

#pragma omp parallel num_threads(N2) shared(a) private(b)
    {
        int thread_num = omp_get_thread_num();
        printf("Номер потока: %d \n", thread_num);
        a -= thread_num;
        b -= thread_num;
        printf("Изменение a и b для потока №%d : a = %d, b = %d \n", thread_num, a, b);
        printf("\n");
    };
    
    printf("После входа в параллельную область №2: a = %d, b = %d \n", a, b);
    printf("\n");
    
    return 0;
}