//
// Created by Ivan Bogatyrev on 1/9/2021.
//

#include <check.h>
#include <stdio.h>
#include "../inc/matrix_creation.h"
#include "../inc/matrix_utils.h"

START_TEST(imc_even)
{
    int **matrix = create_matrix(2, 2);
    identity_matrix(matrix, 2);
    if (matrix[0][0] != 1 || matrix[0][1] != 0 || matrix[1][1] != 1 || matrix[1][0] != 0)
    {
        free_matrix(matrix);
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
        free_matrix(matrix);
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
        free_matrix(matrix);
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
        free_matrix(matrix);
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
        free_matrix(matrix);
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
                free_matrix(matrix);
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
        free_matrix(matrix);
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
                free_matrix(matrix);
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

//

START_TEST(dc_basic)
{
    int **matrix = create_matrix(2, 3);
    int array[6] = {4, 1, 7, 3, 7, 2};
    int k = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }
    int columns = 3;
    delete_column(matrix, 2, &columns);
    if (columns != 2)
    {
        free_matrix(matrix);
        ck_abort_msg("wrong num of columns");
    }
    k = 0;
    int new_array[4] = {4, 7, 3, 2};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] != new_array[k++])
            {
                free_matrix(matrix);
                ck_abort_msg("not correctly deleted row");
            }
        }
    }
    free_matrix(matrix);
}
END_TEST

START_TEST(dc_several)
{
    int **matrix = create_matrix(2, 3);
    int array[6] = {4, 1, 7, 3, 7, 1};
    int k = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }
    int columns = 3;
    delete_column(matrix, 2, &columns);
    if (columns != 2)
    {
        free_matrix(matrix);
        ck_abort_msg("wrong num of columns");
    }
    k = 0;
    int new_array[4] = {4, 7, 3, 1};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] != new_array[k++])
            {
                free_matrix(matrix);
                ck_abort_msg("not correctly deleted row");
            }
        }
    }
    free_matrix(matrix);
}
END_TEST

Suite *delete_column_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("delete_column_suite");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, dc_basic);
    tcase_add_test(tc_pos, dc_several);

    suite_add_tcase(s, tc_pos);

    return s;
}

//

START_TEST(cotn_basic)
{
    int **source_matrix = create_matrix(3,3);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9};
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            source_matrix[i][j] = array[k++];
        }
    }

    int **new_matrix = create_matrix(3, 3);
    copy_old_to_new(source_matrix, new_matrix, 3, 3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (source_matrix[i][j] != new_matrix[i][j])
            {
                free_matrix(source_matrix);
                ck_abort();
            }
        }
    }
    free_matrix(source_matrix);
    free_matrix(new_matrix);
}
END_TEST

START_TEST(cotn_not_square)
{
    int **source_matrix = create_matrix(2,3);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9};
    int k = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            source_matrix[i][j] = array[k++];
        }
    }

    int **new_matrix = create_matrix(2, 3);
    int rc = copy_old_to_new(source_matrix, new_matrix, 2, 3, 2);
    if (rc == 0)
    {
        free_matrix(source_matrix);
        ck_abort();
    }
    free_matrix(source_matrix);
    free_matrix(new_matrix);
}
END_TEST

START_TEST(cotn_negative)
{
    int **source_matrix = create_matrix(2,3);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9};
    int k = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            source_matrix[i][j] = array[k++];
        }
    }

    int **new_matrix = create_matrix(2, 3);
    int rc = copy_old_to_new(source_matrix, new_matrix, -1, -1, 1);
    if (rc == 0)
    {
        free_matrix(source_matrix);
        ck_abort();
    }
    free_matrix(source_matrix);
    free_matrix(new_matrix);
}
END_TEST

Suite *copy_old_to_new_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("enlargement_suite");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, cotn_not_square);
    tcase_add_test(tc_neg, cotn_negative);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, cotn_basic);

    suite_add_tcase(s, tc_pos);

    return s;
}

//

START_TEST(fgmc_basic)
{
    int **source_matrix = create_matrix(3,3);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9};
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            source_matrix[i][j] = array[k++];
        }
    }

    int result = find_geom_mean_of_col(source_matrix, 3, 0);
    if (result - 0 >= 0.000001)
    {
        free_matrix(source_matrix);
        ck_abort();
    }
    result = find_geom_mean_of_col(source_matrix, 3, 1);
    if (result - 2 >= 0.000001)
    {
        free_matrix(source_matrix);
        ck_abort();
    }
    result = find_geom_mean_of_col(source_matrix, 3, 2);
    if (result - 5 >= 0.000001)
    {
        free_matrix(source_matrix);
        ck_abort();
    }

    free_matrix(source_matrix);
}
END_TEST

Suite *find_geom_mean_of_col_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("find_geom_mean_of_col_suite");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, fgmc_basic);

    suite_add_tcase(s, tc_pos);

    return s;
}


START_TEST(add_new_row_basic)
{
    int **matrix = create_matrix(3, 2);
    int array[4] = {4, 1, 7, 3};
    int k = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix[i][j] = array[k++];
        }
    }
    unsigned int rows = 2;
    int result_1 = find_geom_mean_of_col(matrix, 2, 0);
    int result_2 = find_geom_mean_of_col(matrix, 2, 1);
    int rc = add_new_row(matrix, &rows, 2, 3);
    if (rc != 0){
        free_matrix(matrix);
        ck_abort();
    }
    printf("%d %d", result_1, result_2);
    if (matrix[2][0] != result_1 || matrix[2][1] != result_2)
    {
        free_matrix(matrix);
        ck_abort();
    }
    free_matrix(matrix);
}
END_TEST

START_TEST(add_new_row_equal)
{
    int **matrix = create_matrix(2, 2);
    int array[4] = {4, 1, 7, 3};
    int k = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix[i][j] = array[k++];
        }
    }
    unsigned int rows = 2;
    int rc = add_new_row(matrix, &rows, 2, 2);
    if (rc != 0){
        free_matrix(matrix);
        ck_abort();
    }
    free_matrix(matrix);
}
END_TEST

START_TEST(add_new_row_less)
{
    int **matrix = create_matrix(2, 2);
    int array[4] = {4, 1, 7, 3};
    int k = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix[i][j] = array[k++];
        }
    }
    unsigned int rows = 2;
    int rc = add_new_row(matrix, &rows, 2, 1);
    if (rc == 0){
        free_matrix(matrix);
        ck_abort();
    }
    free_matrix(matrix);
}
END_TEST

Suite *add_new_row_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("add_new_row_suite");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, add_new_row_less);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, add_new_row_basic);
    tcase_add_test(tc_pos, add_new_row_equal);

    suite_add_tcase(s, tc_pos);

    return s;
}

//

START_TEST(fmir_basic)
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
    int max = find_max_in_row(matrix, 0, 3);
    if (max != 9)
    {
        free_matrix(matrix);
        ck_abort();
    }
    free_matrix(matrix);
}
END_TEST

START_TEST(fmir_several)
{
    int **matrix = create_matrix(4, 3);
    int array[12] = {0, 9, 9, 1, 2, 2, 3, 3, 3, 8, 9, 2};
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }
    int max = find_max_in_row(matrix, 0, 3);
    if (max != 9)
    {
        free_matrix(matrix);
        ck_abort();
    }
    free_matrix(matrix);
}
END_TEST

Suite *find_max_in_row_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("find_max_in_row_suite");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, fmir_basic);
    tcase_add_test(tc_pos, fmir_several);

    suite_add_tcase(s, tc_pos);

    return s;
}

