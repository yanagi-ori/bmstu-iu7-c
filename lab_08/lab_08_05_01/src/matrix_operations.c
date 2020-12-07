//
// Created by Ivan Bogatyrev on 12/6/2020.
//

#include <stdio.h>
#include "../inc/matrix_operations.h"
#include "../inc/matrix_creation.h"
#include "../inc/errors.h"
#include "../inc/utils.h"
#include "../inc/io.h"


int delete_row(int **matrix, unsigned int *rows, unsigned int columns)
{
    unsigned int x, y;
    coord_of_min_in_matrix(matrix, *rows, columns, &x, &y);

    unsigned cur_x = 0, cur_y = 0;
    for (unsigned int i = 0; i < *rows; i++)
    {
        if (i == x)
        {
            continue;
        }
        for (unsigned int j = 0; j < columns; j++)
        {
            matrix[cur_x][cur_y] = matrix[i][j];
            cur_y++;
        }
        cur_y = 0;
        cur_x++;
    }
    (*rows)--;
    return 0;
}

int delete_column(int **matrix, unsigned int rows, unsigned int *columns)
{
    int **new_matrix = create_matrix(rows, (*columns) - 1);
    if (new_matrix == NULL)
    {
        return MATRIX_MEMORY_ALLOCATION_ERROR;
    }

    unsigned int x, y;
    coord_of_min_in_matrix(matrix, rows, *columns, &x, &y);

    unsigned cur_x = 0, cur_y = 0;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < *columns; j++)
        {
            if (j != y)
            {
                new_matrix[cur_x][cur_y] = matrix[i][j];
                cur_y++;
            }
        }
        cur_y = 0;
        cur_x++;
    }

    (*columns)--;
    return 0;
}

int squaring(int **matrix, unsigned int rows, unsigned int columns, unsigned int target)
{
    int rc;

    while (rows > target)
    {

        rc = delete_row(matrix, &rows, columns);
        if (rc == MATRIX_MEMORY_ALLOCATION_ERROR)
        {
            return MATRIX_MEMORY_ALLOCATION_ERROR;
        }
    }
    while (columns > target)
    {
        rc = delete_column(matrix, rows, &columns);
        if (rc == MATRIX_MEMORY_ALLOCATION_ERROR)
        {
            return MATRIX_MEMORY_ALLOCATION_ERROR;
        }
    }

    return 0;
}

