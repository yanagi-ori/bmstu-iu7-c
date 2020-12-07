//
// Created by Ivan Bogatyrev on 12/6/2020.
//

#include <stdio.h>

#include "../inc/io.h"

void output_matrix(int **matrix, unsigned int rows, unsigned int columns)
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}