//
// Created by yanag on 6/9/2020.
//

#include <stdio.h>
#include "utils.h"

#define ERROR_POINTER -21
#define ERROR_IO -12


void swap(long int *one, long int *two)
{
    int three = *one;
    *one = *two;
    *two = three;
}

void swapf(double *one, double *two)
{
    double three = *one;
    *one = *two;
    *two = three;
}

int get_average(FILE *file, long int left_border, double right_border, double *average)
{
    if (!file)
    {
        printf("Pointer exception in 'get_average'");
        return ERROR_POINTER;
    }

    fseek(file, left_border, SEEK_SET);
    double item;
    int index = 0;

    while (fscanf(file, "%lf", &item) == 1)
    {
        if (item == right_border)
        {
            break;
        }
        *average += item;
        index++;
    }

    if (index == 0)
    {
        *average = index;
    }
    else
    {
        *average /= index;
    }

    return 0;
}

int process(FILE *file, double *result)
{
    *result = 0;

    long int max_index, min_index;
    double max, min;

    int error = get_borders(file, &min_index, &max_index, &min, &max);

    if (error == ERROR_POINTER)
    {
        return ERROR_POINTER;
    }
    else if (error == ERROR_IO)
    {
        return ERROR_IO;
    }

    if (min_index > max_index)
    {
        swap(&min_index, &max_index);
        swapf(&min, &max);
    }

    error = get_average(file, min_index, max, result);
    if (error == ERROR_POINTER)
    {
        return ERROR_POINTER;
    }
    else if (error == ERROR_IO)
    {
        return ERROR_IO;
    }

    return 0;
}

int get_borders(FILE *file, long int *min_index, long int *max_index, double *min, double *max)
{
    if (!file || !max_index || !min_index)
    {
        return ERROR_POINTER;
    }


    double item;
    int error = fscanf(file, "%lf", &item);
    if (error != 1)
    {
        return ERROR_IO;
    }
    else
    {
        *min = item;
        *max = item;
    }

    *min_index = ftell(file);
    *max_index = ftell(file);
    while (fscanf(file, "%lf", &item) == 1)
    {
        if (item > *max)
        {
            *max = item;
            *max_index = ftell(file);
        }
        if (item < *min)
        {
            *min = item;
            *min_index = ftell(file);
        }
    }
    return 0;
}

