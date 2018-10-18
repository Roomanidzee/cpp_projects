//
// Created by andrey on 13.09.18.
//
#include <iostream>
#include <time.h>
#include <omp.h>
#define N 10

int main(){

#pragma omp parallel num_threads(N)
    {
       printf("Вас категорически приветствует поток № %d!\n", omp_get_thread_num());
    };

}