#include <stdio.h>
#include "../inc/matrix_creation.h"
#include "../inc/errors.h"

int main()
{
    int rc;

    // first matrix data input
    int m, n;
    int **matrix_a;

    printf("Input number of rows and columns of the matrix A: \n");
    rc = scanf("%d%d", &m, &n);
    if (rc != 2)
    {
        return MATRIX_DATA_INPUT_ERROR;
    }

    matrix_a = create_martix(m, n);
    if (matrix_a == NULL)
    {
        return MATRIX_MEMORY_ALLOCATION_ERROR;
    }
    printf("Input elements of the matrix A: \n");
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            if (scanf("%d", &matrix_a[i][j]) != 1)
            {
                return MATRIX_DATA_INPUT_ERROR;
            }
        }
    }

    // second matrix data input
    int p, q;
    int **matrix_b;

    printf("Input number of rows and columns of the matrix B: ");
    rc = scanf("%d%d", &p, &q);
    if (rc != 2)
    {
        MATRIX_DATA_INPUT_ERROR;
    }
    matrix_b = create_martix(p, q);
    if (matrix_b == NULL)
    {
        return MATRIX_MEMORY_ALLOCATION_ERROR;
    }
    printf("Input elements of the matrix B: \n");
    for (unsigned int i = 0; i < p; i++)
    {
        for (unsigned int j = 0; j < q; j++)
        {
            if (scanf("%d", &matrix_b[i][j]) != 1)
            {
                return MATRIX_DATA_INPUT_ERROR;
            }
        }
    }

    free_matrix(matrix_a);
    free_matrix(matrix_b);
    return 0;
}
