//
// Created by Ivan Bogatyrev on 1/9/2021.
//

#include <check.h>
#include "../inc/matrix_creation.h"
#include "../inc/matrix_utils.h"

START_TEST(imc_even)
{
    int **matrix = create_matrix(2, 2);
    identity_matrix(matrix, 2);
    if (matrix[0][0] != 1 || matrix[0][1] != 0 || matrix[1][1] != 1 || matrix[1][0] != 0)
    {
        ck_abort_msg("Invalid identity matrix");
    }
    free_matrix(matrix);

}
END_TEST

START_TEST(imc_odd)
{
    int **matrix = create_matrix(3, 3);
    identity_matrix(matrix, 3);
    if (matrix[0][0] != 1 || matrix[0][1] != 0 || matrix[1][1] != 1 || matrix[1][0] != 0 || matrix[2][2] != 1)
    {
        ck_abort_msg("Invalid identity matrix");
    }
    free_matrix(matrix);

}
END_TEST

Suite *imc_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("identity_matrix_creation_suite");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, imc_even);
    tcase_add_test(tc_pos, imc_odd);
    suite_add_tcase(s, tc_pos);

    return s;
}

//

START_TEST(cmm_basic_1)
{
    int **matrix = create_matrix(3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = i + j;
        }
    }
    unsigned int x = 0, y = 0;
    coord_of_min_in_matrix(matrix, 3, 3, &x, &y);
    if (x != 0 || y != 0)
    {
        ck_abort();
    }
    free_matrix(matrix);
}
END_TEST

START_TEST(cmm_basic_2)
{
    int k = 0;
    int **matrix = create_matrix(3, 3);
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            matrix[i][j] = k++;
        }
    }
    unsigned int x = 0, y = 0;
    coord_of_min_in_matrix(matrix, 3, 3, &x, &y);
    if (x != 2 || y != 2)
    {
        ck_abort();
    }
    free_matrix(matrix);
}
END_TEST

Suite *cmm_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("coord_of_min_in_matrix_suite");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, cmm_basic_1);
    tcase_add_test(tc_pos, cmm_basic_2);

    suite_add_tcase(s, tc_pos);

    return s;
}

//

START_TEST(dr_basic)
{
    int **matrix = create_matrix(4, 3);
    int array[12] = {0, 2, 9, 1, 2, 2, 3, 3, 3, 8, 9, 2};
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }
    int rows = 4;
    delete_row(matrix, &rows, 3);
    if (rows != 3)
    {
        ck_abort_msg("wrong num of rows\n");
    }
    k = 0;
    int new_array[9] = {1, 2, 2, 3, 3, 3, 8, 9, 2};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] != new_array[k++])
            {
                ck_abort_msg("not correctly deleted row");
            }
        }
    }
    free_matrix(matrix);
}
END_TEST

START_TEST(dr_several)
{
    int **matrix = create_matrix(4, 3);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9, 8, 9, 2};
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }
    int rows = 4;
    delete_row(matrix, &rows, 3);
    if (rows != 3)
    {
        ck_abort_msg("wrong num of rows\n");
    }
    k = 0;
    int new_array[9] = {1, 2, 2, 0, 2, 9, 8, 9, 2};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] != new_array[k++])
            {
                ck_abort_msg("not correctly deleted row");
            }
        }
    }
    free_matrix(matrix);
}
END_TEST

Suite *delete_row_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("delete_row_suite");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, dr_basic);
    tcase_add_test(tc_pos, dr_several);

    suite_add_tcase(s, tc_pos);

    return s;
}