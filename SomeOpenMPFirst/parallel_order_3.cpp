//
// Created by andrey on 20.09.18.
//

#include <iostream>
#include <omp.h>
#define FIRST_SIZE 6
#define SECOND_SIZE 8
#define MIN_SIZE 10
#define MAX_SIZE 30

int main(){

    int a[FIRST_SIZE][SECOND_SIZE];

    for (auto &k : a) {
        for (int &l : k) {
            l = (MIN_SIZE + (rand() % (MAX_SIZE - MIN_SIZE + 1)));
        }
    }

    for (auto &k : a) {
        for (int &l : k) {
            printf("%d ", l);
        }
        printf("\n");
    }

    int min_elem = a[0][0], max_elem = a[0][0];

#pragma omp parallel sections
    {

        #pragma omp section
        {

            int s = 0;

            for (auto &i : a) {
                for (int j : i) {
                    s += j;
                }
            }

            printf("Среднее арифметическое: %d. Номер нити: %d \n", s / (FIRST_SIZE * SECOND_SIZE), omp_get_thread_num());

        }

        #pragma omp section
        {

            for (auto &i : a) {
                for (int j : i) {
                    if(j < min_elem){
                        min_elem = j;
                    }
                    if(j > max_elem){
                        max_elem = j;
                    }
                }
            }

            printf("Минимальное значение: %d. Максимальное значение: %d; Номер нити: %d \n",
                    min_elem, max_elem,omp_get_thread_num());

        }

        #pragma omp section
        {
            int counter = 0;

            for (auto &i : a) {
                for (int j : i) {
                    if(j % 3 == 0){
                        counter += 1;
                    }
                }
            }

            printf("Количество тех элементов, которые кратны 3: %d. Номер нити: %d \n",
                    counter, omp_get_thread_num());

        }

    };

    return 0;
}