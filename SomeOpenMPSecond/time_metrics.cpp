//
// Created by andrey on 23.09.18.
//
#include <iostream>
#include <stdlib.h>
#include <omp.h>
#define ELEMENT_COUNT 16000
#define THREAD_COUNT 8
#define DIVIDER 3.0
#define PORTIONS_1 4
#define PORTIONS_2 6

int main(){

    omp_set_num_threads(THREAD_COUNT);

    double static_11_start = omp_get_wtime();

    auto *a = new double[ELEMENT_COUNT];
    auto *b = new double[ELEMENT_COUNT];

    #pragma omp parallel for schedule(static,PORTIONS_1)
    for(int i = 0; i < ELEMENT_COUNT; i++){
        a[i] = i;
    }

    #pragma omp parallel for schedule(static,PORTIONS_1)
    for(int i = 1; i < ELEMENT_COUNT - 2; i++){
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / DIVIDER;
    }

    double static_21_stop = omp_get_wtime();
    printf("Тип распределения: static, количество порций: %d, время выполнения: %f секунд\n",
            PORTIONS_1, static_21_stop - static_11_start);

    delete[] a;
    delete[] b;

    double static_12_start = omp_get_wtime();

    a = new double[ELEMENT_COUNT];
    b = new double[ELEMENT_COUNT];

    #pragma omp parallel for schedule(static,PORTIONS_2)
    for(int i = 0; i < ELEMENT_COUNT; i++){
        a[i] = i;
    }

    #pragma omp parallel for schedule(static,PORTIONS_2)
    for(int i = 1; i < ELEMENT_COUNT - 2; i++){
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / DIVIDER;
    }

    double static_22_stop = omp_get_wtime();
    printf("Тип распределения: static, количество порций: %d, время выполнения: %f секунд\n",
           PORTIONS_2, static_22_stop - static_12_start);

    delete[] a;
    delete[] b;

    printf("\n");

    double dynamic_11_start = omp_get_wtime();

    a = new double[ELEMENT_COUNT];
    b = new double[ELEMENT_COUNT];

    #pragma omp parallel for schedule(dynamic,PORTIONS_1)
    for(int i = 0; i < ELEMENT_COUNT; i++){
        a[i] = i;
    }

    #pragma omp parallel for schedule(dynamic,PORTIONS_1)
    for(int i = 1; i < ELEMENT_COUNT - 2; i++){
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / DIVIDER;
    }

    double dynamic_21_stop = omp_get_wtime();
    printf("Тип распределения: dynamic, количество порций: %d, время выполнения: %f секунд\n",
           PORTIONS_1, dynamic_21_stop - dynamic_11_start);

    delete[] a;
    delete[] b;

    double dynamic_12_start = omp_get_wtime();

    a = new double[ELEMENT_COUNT];
    b = new double[ELEMENT_COUNT];

    #pragma omp parallel for schedule(dynamic,PORTIONS_2)
    for(int i = 0; i < ELEMENT_COUNT; i++){
        a[i] = i;
    }

    #pragma omp parallel for schedule(dynamic,PORTIONS_2)
    for(int i = 1; i < ELEMENT_COUNT - 2; i++){
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / DIVIDER;
    }

    double dynamic_22_stop = omp_get_wtime();
    printf("Тип распределения: dynamic, количество порций: %d, время выполнения: %f секунд\n",
           PORTIONS_2, dynamic_22_stop - dynamic_12_start);

    delete[] a;
    delete[] b;

    printf("\n");

    double guided_11_start = omp_get_wtime();

    a = new double[ELEMENT_COUNT];
    b = new double[ELEMENT_COUNT];

    #pragma omp parallel for schedule(guided,PORTIONS_1)
    for(int i = 0; i < ELEMENT_COUNT; i++){
        a[i] = i;
    }

    #pragma omp parallel for schedule(guided,PORTIONS_1)
    for(int i = 1; i < ELEMENT_COUNT - 2; i++){
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / DIVIDER;
    }

    double guided_21_stop = omp_get_wtime();
    printf("Тип распределения: guided, количество порций: %d, время выполнения: %f секунд\n",
           PORTIONS_1, guided_21_stop - guided_11_start);

    delete[] a;
    delete[] b;

    double guided_12_start = omp_get_wtime();

    a = new double[ELEMENT_COUNT];
    b = new double[ELEMENT_COUNT];

    #pragma omp parallel for schedule(guided,PORTIONS_2)
    for(int i = 0; i < ELEMENT_COUNT; i++){
        a[i] = i;
    }

    #pragma omp parallel for schedule(guided,PORTIONS_2)
    for(int i = 1; i < ELEMENT_COUNT - 2; i++){
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / DIVIDER;
    }

    double guided_22_stop = omp_get_wtime();
    printf("Тип распределения: guided, количество порций: %d, время выполнения: %f секунд\n",
           PORTIONS_2, guided_22_stop - guided_12_start);

    delete[] a;
    delete[] b;

    printf("\n");

    std::string str1 = "OMP_SCHEDULE=" + std::to_string(PORTIONS_1);
    putenv(const_cast<char *>(str1.c_str()));

    double runtime_11_start = omp_get_wtime();

    a = new double[ELEMENT_COUNT];
    b = new double[ELEMENT_COUNT];

    #pragma omp parallel for schedule(runtime)
    for(int i = 0; i < ELEMENT_COUNT; i++){
        a[i] = i;
    }

    #pragma omp parallel for schedule(runtime)
    for(int i = 1; i < ELEMENT_COUNT - 2; i++){
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / DIVIDER;
    }

    double runtime_21_stop = omp_get_wtime();
    printf("Тип распределения: runtime, количество порций: %d, время выполнения: %f секунд\n",
           PORTIONS_1, runtime_21_stop - runtime_11_start);

    delete[] a;
    delete[] b;

    std::string str2 = "OMP_SCHEDULE=" + std::to_string(PORTIONS_2);
    putenv(const_cast<char *>(str2.c_str()));

    double runtime_12_start = omp_get_wtime();

    a = new double[ELEMENT_COUNT];
    b = new double[ELEMENT_COUNT];

    #pragma omp parallel for schedule(runtime)
    for(int i = 0; i < ELEMENT_COUNT; i++){
        a[i] = i;
    }

    #pragma omp parallel for schedule(runtime)
    for(int i = 1; i < ELEMENT_COUNT - 2; i++){
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / DIVIDER;
    }

    double runtime_22_stop = omp_get_wtime();
    printf("Тип распределения: runtime, количество порций: %d, время выполнения: %f секунд\n",
           PORTIONS_2, runtime_22_stop - runtime_12_start);

    delete[] a;
    delete[] b;

    printf("\n");

    return 0;
}
