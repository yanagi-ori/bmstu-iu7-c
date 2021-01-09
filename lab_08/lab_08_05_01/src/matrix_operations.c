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
        delete_row(matrix, &rows, columns);
    }
    while (columns > target)
    {
        delete_column(matrix, rows, &columns);
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

int mult_matrices(int **matrix_base, int **matrix, int size)
{
    if (size <= 0)
    {
        return MATRIX_OUT_OF_RANGE;
    }
    int **temp_matrix = create_matrix(size, size);
    if (temp_matrix == NULL)
    {
        return MATRIX_MULTIPLICATION_ERROR;
    }
    copy_old_to_new(matrix_base, temp_matrix, size, size, size);
    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 0; j < size; j++)
        {
            matrix_base[i][j] = find_mult_result(temp_matrix, matrix, size, i, j);
            if (matrix_base[i][j] < 0)
            {
                free_matrix(temp_matrix);
                return MATRIX_MULTIPLICATION_ERROR;
            }
        }
    }
    free_matrix(temp_matrix);
    return 0;
}

int **matrix_pow(int **matrix_base, int pow, int size)
{
    if (pow < 0)
    {
        return NULL;
    }
    else
    {
        int **new_matrix = create_matrix(size, size);
        if (new_matrix == NULL)
        {
            return NULL;
        }
        identity_matrix(new_matrix, size);
        for (int i = 0; i < pow; i++)
        {
            int rc = mult_matrices(new_matrix, matrix_base, size);
            if (rc != 0)
            {
                return NULL;
            }
        }
        return new_matrix;
    }
}