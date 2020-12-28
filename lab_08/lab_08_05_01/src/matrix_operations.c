//
// Created by Ivan Bogatyrev on 12/6/2020.
//

#include <stdio.h>

#include "../inc/matrix_operations.h"
#include "../inc/matrix_creation.h"
#include "../inc/matrix_utils.h"
#include "../inc/errors.h"


int squaring(int **matrix, int rows, int columns, int target)
{
    int rc;

    if (rows == 0 || columns == 0 || target == 0)
    {
        return MATRIX_DATA_INPUT_ERROR;
    }

    if (rows < target && columns < target)
    {
        return MATRIX_RANGE_SUSPECT;
    }
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

int **matrix_enlargement(int **source_matrix, unsigned int rows, unsigned int columns, unsigned int target)
{
    int rc;

    if (rows == 0 || columns == 0 || target == 0)
    {
        return NULL;
    }

    if (target < rows || target < columns)
    {
        return NULL;
    }

    int **new_matrix = create_matrix(target, target);
    if (new_matrix == NULL)
    {
        return NULL;
    }

    rc = copy_old_to_new(source_matrix, new_matrix, rows, columns, target);
    if (rc == MATRIX_OUT_OF_RANGE)
    {
        free_matrix(new_matrix);
        return NULL;
    }

    if (rows == target && columns == target)
    {
        return new_matrix;
    }

    while (rows < target)
    {
        rc = add_new_row(new_matrix, &rows, columns, target);
        if (rc == WRONG_DATA)
        {
            free_matrix(new_matrix);
            return NULL;
        }
    }
    while (columns < target)
    {
        rc = add_new_column(new_matrix, rows, &columns, target);
        if (rc == WRONG_DATA)
        {
            free_matrix(new_matrix);
            return NULL;
        }
    }

    return new_matrix;
}

int **multiply_different_matrices(int **matrix_a, int **matrix_b, unsigned int size)
{
    if (size == 0)
    {
        return NULL;
    }

    int **result_matrix = create_matrix(size, size);
    if (result_matrix == NULL)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 0; j < size; j++)
        {
            result_matrix[i][j] = find_mult_result(matrix_a, matrix_b, size, i, j);
            if (result_matrix[i][j] < 0)
            {
                free_matrix(result_matrix);
                return NULL;
            }
        }
    }

    return result_matrix;
}

int matrix_power(int ***matrix_a, int ***matrix_b, int size)
{
    if (*matrix_a == NULL)
    {
        *matrix_a = create_matrix(size, size);
        if (matrix_a == NULL)
        {
            return MATRIX_MEMORY_ALLOCATION_ERROR;
        }
        int rc = copy_old_to_new(*matrix_b, *matrix_a, size, size, size);
        if (rc != 0)
        {
            return rc;
        }
        return 0;
    }

    int **temp_matrix;
    temp_matrix = multiply_different_matrices(*matrix_a, *matrix_b, size);
    if (temp_matrix == NULL)
    {
        return MATRIX_MEMORY_ALLOCATION_ERROR;
    }
    free_matrix(*matrix_a);
    *matrix_a = temp_matrix;
    return 0;
}