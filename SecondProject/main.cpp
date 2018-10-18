#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <cstring>
#include <time.h>

using namespace std;

void change(int &a, int &b){


    cout << "Введите а: ";
    cin >> a;
    cout << "\nВведите b: ";
    cin >> b;

    printf("a = %d, b = %d \n", a, b);

    int c = a;
    a = b;
    b = c;

    printf("a = %d, b = %d \n", a, b);

}

int sum(const int ar[]){

    int s = 0;
    int array_length = sizeof(ar)/sizeof(*ar);

    for(int i = 0; i < array_length; i++){
        s += ar[i];
    }

    return s;

}

int main() {

    int a, b;
    char s[100];

    strcpy(s, "abc");

    s[3] = 'a';

    cout << "Привет, мир!\n";

    change(a, b);

    const int n = 10;
    int *ar;

    int k = 20;
    ar = new int[k];
    //void *t = malloc(k * sizeof(k));

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++){
        ar[i] = rand() % 200 - 100;
        printf(" arr[%d] = %d ", i, ar[i]);
    }

    cout << sum(ar);

    delete ar;

    return 0;
}