//
// Created by andrey on 23.09.18.
//
#include <iostream>
#include <omp.h>
#define ROWS 10
#define COLUMNS 90
#define MIN_SIZE 10
#define MAX_SIZE 30
#define PORTIONS 6

int main(){

    double matrix[ROWS][COLUMNS];
    double vector[MIN_SIZE];
    double result_vector[MIN_SIZE];

    double sequence_start = omp_get_wtime();

    for (auto &i : matrix) {
     for (double &j : i) {
         j = (MIN_SIZE + (rand() % (MAX_SIZE - MIN_SIZE + 1)));
      }
    }

    for (double &i : vector) {
        i = (MIN_SIZE + (rand() % (MAX_SIZE - MIN_SIZE + 1)));
    }

    for(int i = 0; i < ROWS; i++){

        result_vector[i] = 0;

        for(int j = 0; j < COLUMNS; j++){
            result_vector[i] += matrix[i][j] * vector[j];
        }

    }
    double sequence_stop = omp_get_wtime();
    printf("Время выполнения последовательной программы: %f секунд\n", sequence_stop - sequence_start);

    double parallel_start = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic, PORTIONS)
    for(int k = 0; k < ROWS; k++){
        #pragma omp parallel for schedule(dynamic, PORTIONS)
        for(int l = 0; l < COLUMNS; l++){
            matrix[k][l] = (MIN_SIZE + (rand() % (MAX_SIZE - MIN_SIZE + 1)));
        }
    }

    #pragma omp parallel for schedule(dynamic, PORTIONS)
    for(int k = 0; k < MIN_SIZE; k++){
        vector[k] = (MIN_SIZE + (rand() % (MAX_SIZE - MIN_SIZE + 1)));
    }

    #pragma omp parallel for schedule(dynamic, PORTIONS)
    for(int k = 0; k < ROWS; k++){

        result_vector[k] = 0;
        #pragma omp parallel for schedule(dynamic, PORTIONS)
        for(int l = 0; l < COLUMNS; l++){
            result_vector[k] += matrix[k][l] * vector[l];
        }

    }
    double parallel_stop = omp_get_wtime();
    printf("Время выполнения параллельной программы: %f секунд\n", parallel_stop - parallel_start);

    return 0;
}