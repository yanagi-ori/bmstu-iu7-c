//
// Created by Ivan Bogatyrev on 12/6/2020.
//

#include "../inc/matrix_operations.h"
#include "../inc/matrix_creation.h"
#include "../inc/matrix_utils.h"
#include "../inc/errors.h"


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

int **matrix_enlargement(int **source_matrix, unsigned int rows, unsigned int columns, unsigned int target){
    int **new_matrix = create_matrix(target, target);

}

