//
// Created by andrey on 27.09.18.
//
#include <iostream>
#include <omp.h>
#define N1 6
#define N2 8
#define NUM_THREADS 4
#define PORTIONS 6
#define MIN_SIZE 10
#define MAX_SIZE 30

int main() {

    int a[N1][N2];

    for (auto &i : a) {
        for (int &j : i) {
            j = (MIN_SIZE + (rand() % (MAX_SIZE - MIN_SIZE + 1)));
        }
    }

    int max = a[0][0], min = a[0][0];

    #pragma omp parallel num_threads(NUM_THREADS)
    {

       #pragma omp parallel for schedule(dynamic, PORTIONS)
       for(int i = 0; i < N1; i++){

          #pragma omp parallel for schedule(dynamic, PORTIONS)
          for(int j = 0; j < N2; j++){

             #pragma omp critical
              {

                 if(a[i][j] > max){
                     max = a[i][j];
                 }

                 if(a[i][j] < min){
                     min = a[i][j];
                 }

              };

          }

       }

    }

    printf("Минимум: %d ; Максимум: %d; \n", min, max);

    return 0;
}