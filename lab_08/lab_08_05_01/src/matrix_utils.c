//
// Created by Ivan Bogatyrev on 12/7/2020.
//

#include "../inc/matrix_utils.h"

void coord_of_min_in_matrix(int **matrix, unsigned int rows, unsigned int columns, unsigned int *x, unsigned int *y)
{
    int min = matrix[0][0];
    *y = 0;
    *x = 0;

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                *x = i;
                *y = j;
            }
        }
    }
}

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
    unsigned int x, y;
    coord_of_min_in_matrix(matrix, rows, *columns, &x, &y);

    unsigned cur_x = 0, cur_y = 0;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < *columns; j++)
        {
            if (j != y)
            {
                matrix[cur_x][cur_y] = matrix[i][j];
                cur_y++;
            }
        }
        cur_y = 0;
        cur_x++;
    }

    (*columns)--;
    return 0;
}