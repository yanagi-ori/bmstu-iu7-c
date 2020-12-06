//
// Created by Ivan Bogatyrev on 11/14/2020.
//

#include <stdio.h>
#include "io.h"
#include "errors.h"

int get_matrix_size(FILE *file, int *rows, int *columns)
{
    int result = fscanf(file, "%d%d", rows, columns);
    if (result != 2)
    {
        return MATRIX_SIZE_ERROR;
    }

    if (*rows <= 0 || *columns <= 0)
    {
        return MATRIX_SIZE_ERROR;
    }

    return 0;
}

int get_matrix(FILE *file, int **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (fscanf(file, "%d", &matrix[i][j]) != 1)
            {
                return READ_ERROR;
            }
        }
    }
    int temp;
    fscanf(file, "%d", &temp);
    if (!feof(file))
    {
        return READ_ERROR;
    }

    return 0;
}