//
// Created by andrey on 19.09.18.
//
#include <iostream>
#include <omp.h>
#define N 8

int main() {

#pragma omp parallel num_threads(N)
    {
      printf("ID: %d; Количество потоков: %d; Hello world! \n", omp_get_thread_num(), omp_get_num_threads());
    };

}