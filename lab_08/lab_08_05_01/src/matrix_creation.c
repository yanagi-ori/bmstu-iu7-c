//
// Created by Ivan Bogatyrev on 12/6/2020.
//

#include <stdlib.h>

#include "../inc/errors.h"

int **create_matrix(int rows, int cols)
{
    int **pointers, *data;

    if (rows <= 0 || cols <= 0)
    {
        return NULL;
    }

    pointers = malloc(rows * sizeof(int *));
    if (!pointers)
    {
        return NULL;
    }

    data = malloc(rows * cols * sizeof(int));
    if (!data)
    {
        free(pointers);
        return NULL;
    }

    for (int i = 0; i < rows; i++)
    {
        pointers[i] = data + i * cols;
    }

    return pointers;
}

void free_matrix(int **matrix)
{
    free(matrix[0]);
    free(matrix);
}