//
// Created by Ivan Bogatyrev on 11/14/2020.
//

#include <stdlib.h>
#include "array.h"
#include "errors.h"

int **create_array(int rows, int columns)
{
    int **pointers, *data;

    pointers = malloc(columns * sizeof(int *));
    if (!pointers)
    {
        return NULL;
    }

    data = malloc(columns * rows * sizeof(int));
    if (!data)
    {
        free(pointers);
        return NULL;
    }

    for (int i = 0; i < columns; i++)
    {
        pointers[i] = data + i * rows;
    }

    return pointers;
}

void free_matrix(int **pointers)
{
    free(pointers[0]);
    free(pointers);
}

int find_number(int **matrix, int *number, int size)
{
    *number = 0;
    int status = NUMBER_NOT_FOUND;
    for (int i = 0; i < size; i++)
    {
        for (int j = size - i; j < size; j++)
        {
            if (abs(matrix[i][j]) % 10 == 5 && *number == 0)
            {
                *number = matrix[i][j];
                status = 0;
            }

            else if (abs(matrix[i][j] % 10) == 5 && matrix[i][j] > *number)
            {
                *number = matrix[i][j];
            }
        }
    }

    return status;
}