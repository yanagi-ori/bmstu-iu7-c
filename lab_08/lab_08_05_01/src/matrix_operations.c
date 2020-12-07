//
// Created by Ivan Bogatyrev on 12/6/2020.
//

#include <stdio.h>

#include "../inc/matrix_operations.h"
#include "../inc/matrix_creation.h"
#include "../inc/matrix_utils.h"
#include "../inc/errors.h"


int squaring(int **matrix, unsigned int rows, unsigned int columns, unsigned int target)
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

