#include <stdio.h>
#include "../inc/matrix_creation.h"
#include "../inc/errors.h"
#include "../inc/utils.h"
#include "../inc/matrix_operations.h"
#include "../inc/io.h"

int main()
{
    int rc;

    // first matrix data input
    unsigned int m, n;
    int **matrix_a;

    printf("Input number of rows and columns of the matrix A: \n");
    rc = scanf("%d%d", &m, &n);
    if (rc != 2)
    {
        return MATRIX_DATA_INPUT_ERROR;
    }

    matrix_a = create_matrix(m, n);
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
                free_matrix(matrix_a);
                return MATRIX_DATA_INPUT_ERROR;
            }
        }
    }

    // second matrix data input
    unsigned int p, q;
    int **matrix_b;

    printf("Input number of rows and columns of the matrix B: ");
    rc = scanf("%d%d", &p, &q);
    if (rc != 2)
    {
        free_matrix(matrix_a);
        return MATRIX_DATA_INPUT_ERROR;
    }
    matrix_b = create_matrix(p, q);
    if (matrix_b == NULL)
    {
        free_matrix(matrix_a);
        return MATRIX_MEMORY_ALLOCATION_ERROR;
    }
    printf("Input elements of the matrix B: \n");
    for (unsigned int i = 0; i < p; i++)
    {
        for (unsigned int j = 0; j < q; j++)
        {
            if (scanf("%d", &matrix_b[i][j]) != 1)
            {
                free_matrix(matrix_a);
                free_matrix(matrix_b);
                return MATRIX_DATA_INPUT_ERROR;
            }
        }
    }

    // squaring matrix A
    unsigned int k = min(m, n);

    if (m != n)
    {
        rc = squaring(matrix_a, m, n, k);
        if (rc == MATRIX_MEMORY_ALLOCATION_ERROR)
        {
            free_matrix(matrix_a);
            free_matrix(matrix_b);
            return MATRIX_MEMORY_ALLOCATION_ERROR;
        }
    }

    // squaring matrix B
    unsigned int s = min(p, q);

    if (p != q)
    {
        rc = squaring(matrix_b, p, q, s);
        if (rc == MATRIX_MEMORY_ALLOCATION_ERROR)
        {
            free_matrix(matrix_a);
            free_matrix(matrix_b);
            return MATRIX_MEMORY_ALLOCATION_ERROR;
        }
    }

    // matrices enlargement
    int z = max(k, s);

    int **matrix_a_new = matrix_enlargement(matrix_a, k, k, z);
    if (matrix_a_new == NULL)
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        return MATRIX_ENLARGEMENT_ERROR;
    }
    free_matrix(matrix_a);

    int **matrix_b_new = matrix_enlargement(matrix_b, s, s, z);
    if (matrix_b_new == NULL)
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        free_matrix(matrix_a_new);
        return MATRIX_ENLARGEMENT_ERROR;
    }
    free_matrix(matrix_b);

    output_matrix(matrix_a_new, z, z);
    output_matrix(matrix_b_new, z, z);

    // from here no need to free the memory reserved by old matrices
    // multiplication
    int **result_matrix = multiply_matrices(matrix_a_new, matrix_b_new, z);
    free_matrix(matrix_a_new);
    free_matrix(matrix_b_new);
    if (result_matrix == NULL)
    {
        return MATRIX_MULTIPLICATION_ERROR;
    }

    output_matrix(result_matrix, z, z);

    return 0;
}
