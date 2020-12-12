//
// Created by Ivan Bogatyrev on 12/11/2020.
//

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/array_utils.h"

#define SIZE 25000

double time_calculation(
        int *array,
        void (sort)(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *)),
        int len
)
{
    len--;

    clock_t begin = clock();
    for (int i = 0; i < 5; i++)
    {
        sort(array, len, sizeof(int), compare);
    }
    clock_t end = clock();


    return (double) ((double) (end - begin) / CLOCKS_PER_SEC) / 5;
}

double time_calculation2(
        int *array,
        void (sort)(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *)),
        int len
)
{
    len--;

    clock_t begin = clock();
    for (int i = 0; i < 10000; i++)
    {
        sort(array, len, sizeof(int), compare);
    }
    clock_t end = clock();


    return (double) ((double) (end - begin) / CLOCKS_PER_SEC) / 10000;
}

int main()
{
    int buffer2_1[SIZE];
    int buffer2_2[SIZE];
    srand(time(NULL));
    for (size_t i = 0; i < SIZE; i++)
    {
        buffer2_1[i] = rand() % 1000 - 500;
    }
    for (size_t i = 0; i < SIZE; i++)
    {
        buffer2_2[i] = rand() % 1000 - 500;
    }

    //printf("%f ", time_calculation(buffer2_1, mysort, SIZE));
    printf("%f \n", time_calculation2(buffer2_2, qsort, SIZE));

    int buffer3[25000];
    for (size_t i = 0; i < SIZE; i++)
    {
        buffer3[i] = i;
    }

    //printf("%f ", time_calculation(buffer3, mysort, SIZE));
    printf("%f \n", time_calculation2(buffer3, qsort, SIZE));

    int buffer4[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        buffer3[i] = (long int) SIZE - i;
    }

    //printf("%f ", time_calculation(buffer4, mysort, SIZE));
    printf("%f \n", time_calculation2(buffer4, qsort, SIZE));


    return 0;
}