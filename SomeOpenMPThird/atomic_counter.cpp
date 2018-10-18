//
// Created by andrey on 27.09.18.
//
#include <iostream>
#include <omp.h>
#define ARRAY_SIZE 30
#define NUM_THREADS 4
#define PORTIONS 6
#define MIN_SIZE 10
#define MAX_SIZE 30

int main(){

    int a[ARRAY_SIZE];
    int counter = 0;
    int j;

    for (int &i : a) {
        i = (MIN_SIZE + (rand() % (MAX_SIZE - MIN_SIZE + 1)));
    }

    #pragma omp parallel for private(j) schedule(dynamic, PORTIONS)
    for(j = 0; j < ARRAY_SIZE; j++){

        if(a[j] % 9 == 0){

            #pragma omp atomic
            counter += 1;

        }

    }

    printf("Количество тех элементов, которые кратны 9: %d", counter);

    return 0;
}