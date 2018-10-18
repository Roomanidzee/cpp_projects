//
// Created by andrey on 20.09.18.
//

#include <iostream>
#include <omp.h>
#define N 2
#define ARR_SIZE 10

int main(){

    int a[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int max = a[0];

    int b[ARR_SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int min = b[0];

#pragma omp parallel
    {

        if (omp_get_thread_num() == 0){

            for (int i : a) {
                if (i > max){
                    max = i;
                };
            }
            printf("Максимальное значение: %d \n", max);

        }

        if (omp_get_thread_num() == 1){
            for (int i : b) {
                if (i < min){
                    min = i;
                };
            }
            printf("Минимальное значение: %d\n", min);
        }

    };

    return 0;
}