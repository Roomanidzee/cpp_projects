//
// Created by andrey on 23.09.18.
//
#include <iostream>
#include <omp.h>
#define N 100
#define MIN_SIZE 10
#define MAX_SIZE 30

int main() {

    int a[N];
    int j;
    int counter = 0;
    int counter1 = 0;

    for (int &i : a) {
        i = (MIN_SIZE + (rand() % (MAX_SIZE - MIN_SIZE + 1)));
    }

    #pragma omp parallel for private(j)
    for(j = 0; j < N; j++){
         counter += a[j];
    }
    printf("Конструкция parallel for, среднее арифметичеcкое: %d \n", counter / N);

    #pragma omp parallel for private(j) reduction(+: counter1)
    for(j = 0; j < N; j++){
        counter1 += a[j];
    }
    printf("Конструкция reduction, среднее арифметичеcкое: %d \n", counter1 / N);

    return 0;
}