#include <stdio.h>
#include "../inc/matrix_creation.h"
#include "../inc/errors.h"
#include "../inc/utils.h"
#include "../inc/matrix_operations.h"
#include "../inc/io.h"

int main()
{
    int rc = 0;

    // first matrix data input
    int m, n;
    int **matrix_a;

    printf("Input number of rows and columns of the matrix A: \n");
    if (scanf("%d%d", &m, &n) == 2)
    {
        matrix_a = create_matrix(m, n);
        if (matrix_a != NULL)
        {
            printf("Input elements of the matrix A: \n");
            if (matrix_input(matrix_a, m, n) != MATRIX_DATA_INPUT_ERROR)
            {
                // second matrix data input
                int p, q;
                int **matrix_b;

                printf("Input number of rows and columns of the matrix B: ");
                if (scanf("%d%d", &p, &q) == 2)
                {
                    matrix_b = create_matrix(p, q);
                    if (matrix_b != NULL)
                    {
                        printf("Input elements of the matrix B: \n");
                        if (matrix_input(matrix_b, p, q) != MATRIX_DATA_INPUT_ERROR)
                        {
                            // squaring matrix A
                            unsigned int k = min(m, n);

                            if (m != n)
                            {
                                rc = squaring(matrix_a, m, n, k);
                            }
                            if (rc != MATRIX_MEMORY_ALLOCATION_ERROR)
                            {
                                // squaring matrix B
                                unsigned int s = min(p, q);

                                if (p != q)
                                {
                                    rc = squaring(matrix_b, p, q, s);
                                }
                                if (rc != MATRIX_MEMORY_ALLOCATION_ERROR)
                                {
                                    // matrices enlargement
                                    int z = max(k, s);

                                    int **matrix_a_new = matrix_enlargement(matrix_a, k, k, z);
                                    if (matrix_a_new != NULL)
                                    {
                                        int **matrix_b_new = matrix_enlargement(matrix_b, s, s, z);
                                        if (matrix_b_new != NULL)
                                        {
                                            // multiplication
                                            int **result_matrix = multiply_matrices(matrix_a_new, matrix_b_new, z);
                                            if (result_matrix != NULL)
                                            {
                                                output_matrix(result_matrix, z, z);
                                                free_matrix(result_matrix);
                                            }
                                            else
                                            {
                                                rc = MATRIX_MULTIPLICATION_ERROR;
                                            }
                                        }
                                        else
                                        {
                                            rc = MATRIX_ENLARGEMENT_ERROR;
                                        }
                                        free_matrix(matrix_b_new);
                                    }
                                    else
                                    {
                                        rc = MATRIX_ENLARGEMENT_ERROR;
                                    }
                                    free_matrix(matrix_a_new);
                                }
                            }
                        }
                        else
                        {
                            rc = MATRIX_DATA_INPUT_ERROR;
                        }
                    }
                    else
                    {
                        rc = MATRIX_MEMORY_ALLOCATION_ERROR;
                    }
                    free_matrix(matrix_b);
                }
                else
                {
                    rc = MATRIX_DATA_INPUT_ERROR;
                }
            }
            else
            {
                rc = MATRIX_DATA_INPUT_ERROR;
            }
            free_matrix(matrix_a);
        }
        else
        {
            rc = MATRIX_MEMORY_ALLOCATION_ERROR;
        }
    }
    else
    {
        rc = MATRIX_DATA_INPUT_ERROR;
    }

    return rc;
}
