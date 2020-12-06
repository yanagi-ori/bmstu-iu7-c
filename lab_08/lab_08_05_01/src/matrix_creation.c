//
// Created by Ivan Bogatyrev on 12/6/2020.
//

#include <stdlib.h>

#include "../inc/errors.h"

int **create_matrix(unsigned int m, unsigned int n)
{
    int **pointers, *data;

    pointers = malloc(m * sizeof(int *));
    if (!pointers)
    {
        return NULL;
    }

    data = malloc(m * n * sizeof(int));
    if (!data)
    {
        free(pointers);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        pointers[i] = data + i * m;
    }

    return pointers;
}

void free_matrix(int **matrix)
{
    free(matrix[0]);
    free(matrix);
}