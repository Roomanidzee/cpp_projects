//
// Created by andrey on 19.09.18.
//
#include <iostream>
#include <omp.h>
#define N1 3
#define N2 1

int main(){

    omp_set_num_threads(N1);

#pragma omp parallel if(omp_get_max_threads() > 2)
    {

        if(omp_in_parallel()){
            printf("Количество нитей: %d; Номер нити : %d\n", omp_get_num_threads(), omp_get_thread_num());
        }

    }

    omp_set_num_threads(N2);

#pragma omp parallel if(omp_get_max_threads() > 2)
    {
        if(omp_in_parallel()){
            printf("Количество нитей: %d; Номер нити : %d\n", omp_get_num_threads(), omp_get_thread_num());
        }
    }

    return 0;

};