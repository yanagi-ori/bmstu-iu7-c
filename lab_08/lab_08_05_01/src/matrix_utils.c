//
// Created by Ivan Bogatyrev on 12/7/2020.
//

#include <math.h>
#include "../inc/matrix_utils.h"
#include "../inc/errors.h"
#include "../inc/utils.h"

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

void delete_row(int **matrix, int *rows, int columns)
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
}

void delete_column(int **matrix, int rows, int *columns)
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
}

int copy_old_to_new(int **source_matrix, int **new_matrix, unsigned int rows, unsigned int cols, unsigned int target)
{
    if (target < rows || target < cols || target <= 0)
    {
        return MATRIX_OUT_OF_RANGE;
    }
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            new_matrix[i][j] = source_matrix[i][j];
        }
    }

    return 0;
}

int find_geom_mean_of_col(int **matrix, unsigned int rows, unsigned int column)
{
    int geom_mean = 1;
    for (unsigned int i = 0; i < rows; i++)
    {
        geom_mean *= abs(matrix[i][column]);
    }
    return (int) pow(geom_mean, 1.0 / rows);
}

int add_new_row(int **matrix, unsigned int *rows, unsigned int columns, unsigned int target)
{
    if (*rows == target)
    {
        return 0;
    }
    if (*rows > target || columns > target)
    {
        return MATRIX_OUT_OF_RANGE;
    }

    int geom_mean;
    for (unsigned int i = 0; i < columns; i++)
    {
        geom_mean = find_geom_mean_of_col(matrix, *rows, i);
        if (geom_mean < 0)
        {
            return WRONG_DATA;
        }
        matrix[*rows][i] = geom_mean;
    }

    (*rows)++;
    return 0;
}

int find_max_in_row(int **matrix, unsigned int row, unsigned columns)
{
    int max = matrix[row][0];
    for (unsigned int i = 0; i < columns; i++)
    {
        if (matrix[row][i] > max)
        {
            max = matrix[row][i];
        }
    }
    return max;
}

int add_new_column(int **matrix, unsigned int rows, unsigned int *columns, unsigned int target)
{
    if (*columns == target)
    {
        return 0;
    }
    if (rows > target || *columns > target)
    {
        return MATRIX_OUT_OF_RANGE;
    }

    int max;
    for (unsigned int i = 0; i < rows; i++)
    {
        max = find_max_in_row(matrix, i, *columns);
        if (max < 0)
        {
            return WRONG_DATA;
        }
        matrix[i][*columns] = max;
    }

    (*columns)++;
    return 0;
}

int find_mult_result(int **matrix_a, int **matrix_b, unsigned int size, unsigned int x, unsigned int y)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += (matrix_a[x][i] * matrix_b[i][y]);
    }
    return sum;
}

void identity_matrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
}
