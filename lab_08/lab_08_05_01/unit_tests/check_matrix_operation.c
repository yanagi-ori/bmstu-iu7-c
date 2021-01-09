//
// Created by Ivan Bogatyrev on 12/28/2020.
//

#include <check.h>
#include "../inc/matrix_creation.h"
#include "../inc/matrix_operations.h"
#include "../inc/matrix_utils.h"

START_TEST(test_squaring_col_last)
{
    int success = 0;
    int **matrix = create_matrix(2, 3);
    if (matrix != NULL)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = 2 + i - j;
            }
        }
        int rc = squaring(matrix, 2, 3, 2);
        if (rc == 0)
        {
            if (matrix[0][0] == 2 && matrix[1][1] == 2)
            {
                success = 1;
            }
        }
        free_matrix(matrix);
    }
    if (success == 0)
    {
        ck_abort();
    }
}
END_TEST

START_TEST(test_squaring_col_first)
{
    int success = 0;
    int **matrix = create_matrix(2, 3);
    if (matrix != NULL)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = i + j;
            }
        }
        int rc = squaring(matrix, 2, 3, 2);
        if (rc == 0)
        {
            if (matrix[0][0] == 1 && matrix[1][1] == 3)
            {
                success = 1;
            }
        }
        free_matrix(matrix);
    }
    if (success == 0)
    {
        ck_abort();
    }
}
END_TEST

START_TEST(test_squaring_row_first)
{
    int success = 0;
    int **matrix = create_matrix(3, 2);
    if (matrix != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                matrix[i][j] = i + j;
            }
        }
        int rc = squaring(matrix, 3, 2, 2);
        if (rc == 0)
        {
            if (matrix[0][0] == 1 && matrix[1][1] == 3)
            {
                success = 1;
            }
        }
        free_matrix(matrix);
    }
    if (success == 0)
    {
        ck_abort();
    }
}
END_TEST

START_TEST(test_squaring_row_several)
{
    int success = 0;
    int **matrix = create_matrix(3, 2);
    if (matrix != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                matrix[i][j] = i + j;
            }
        }
        matrix[1][0] = 0;
        int rc = squaring(matrix, 3, 2, 2);
        if (rc == 0)
        {
            if (matrix[0][1] == 2 && matrix[1][1] == 3)
            {
                success = 1;
            }
        }
        free_matrix(matrix);
    }
    if (success == 0)
    {
        ck_abort();
    }
}
END_TEST

Suite *squaring_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("squaring_suite");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_squaring_col_last);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_squaring_col_last);
    tcase_add_test(tc_pos, test_squaring_col_first);
    tcase_add_test(tc_pos, test_squaring_row_first);
    tcase_add_test(tc_pos, test_squaring_row_several);

    suite_add_tcase(s, tc_pos);

    return s;
}

// enlargement

START_TEST(enlargement_add_one_col_row)
{
    int **matrix = create_matrix(4, 4);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9, 8, 9, 2};
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }

    int **new_matrix = matrix_enlargement(matrix, 3, 3, 4);
    if (new_matrix == NULL)
    {
        ck_abort();
        free_matrix(matrix);
    }

    free_matrix(matrix);

    if (new_matrix[2][0] != 0 || new_matrix[2][1] != 2 || new_matrix[1][2] != 2)
    {
        free_matrix(new_matrix);
        ck_abort();
    }

    free_matrix(new_matrix);
}
END_TEST

START_TEST(enlargement_add_sveral_rows_cols)
{
    int **matrix = create_matrix(4, 4);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9, 8, 9, 2};
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }

    int **new_matrix = matrix_enlargement(matrix, 3, 3, 5);
    if (new_matrix == NULL)
    {
        ck_abort();
        free_matrix(matrix);
    }

    free_matrix(matrix);

    if (new_matrix[2][0] != 0 || new_matrix[2][1] != 2 || new_matrix[1][2] != 2)
    {
        free_matrix(new_matrix);
        ck_abort();
    }
    if (new_matrix[3][2] != 5 || new_matrix[2][3] != 9 || new_matrix[3][3] != 5 || new_matrix[1][1] != 2){
        free_matrix(new_matrix);
        ck_abort();
    }

    free_matrix(new_matrix);
}
END_TEST


START_TEST(enlargement_no_add)
{
    int **matrix = create_matrix(4, 4);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9, 8, 9, 2};
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }

    int **new_matrix = matrix_enlargement(matrix, 3, 3, 3);
    if (new_matrix == NULL)
    {
        ck_abort();
        free_matrix(matrix);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] != new_matrix[i][j])
            {
                free_matrix(matrix);
                free_matrix(new_matrix);
                ck_abort();
            }
        }
    }
    free_matrix(matrix);
    free_matrix(new_matrix);
}
END_TEST

START_TEST(enlargement_zero)
{
    int **matrix = create_matrix(4, 4);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9, 8, 9, 2};
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }

    int **new_matrix = matrix_enlargement(matrix, 0, 3, 4);
    if (new_matrix != NULL)
    {
        free_matrix(matrix);
        free_matrix(new_matrix);
        ck_abort();
    }
    free_matrix(matrix);
}
END_TEST

START_TEST(enlargement_target_less)
{
    int **matrix = create_matrix(4, 4);
    int array[12] = {0, 2, 9, 1, 2, 2, 0, 2, 9, 8, 9, 2};
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = array[k++];
        }
    }

    int **new_matrix = matrix_enlargement(matrix, 3, 3, 2);
    if (new_matrix != NULL)
    {
        free_matrix(matrix);
        free_matrix(new_matrix);
        ck_abort();
    }
    free_matrix(matrix);
}
END_TEST

Suite *enlargement_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("enlargement_suite");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, enlargement_zero);
    tcase_add_test(tc_neg, enlargement_target_less);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, enlargement_add_one_col_row);
    tcase_add_test(tc_pos, enlargement_add_sveral_rows_cols);
    tcase_add_test(tc_pos, enlargement_no_add);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(mult_matrices_basic)
{
    int **matrix_a = create_matrix(3, 3);
    int **matrix_b = create_matrix(3, 3);
    int array_a[9] = {0, 2, 9, 1, 2, 2, 3, 3, 3};
    int array_b[9] = {3, 3, 3, 8, 9, 2, 1, 2, 2};
    int k = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix_a[i][j] = array_a[k];
            matrix_b[i][j] = array_b[k];
            k++;
        }
    }

    int rc = mult_matrices(matrix_a, matrix_b, 3);
    if (rc != 0)
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        ck_abort();
    }

    if (matrix_a[0][0] != 25 || matrix_a[1][2] != 11 || matrix_a[2][1] != 42 || matrix_a[2][2] != 21)
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        ck_abort();
    }

    free_matrix(matrix_a);
    free_matrix(matrix_b);
}
END_TEST


START_TEST(mult_matrices_identity)
{
    int **matrix_a = create_matrix(3, 3);
    int **matrix_b = create_matrix(3, 3);
    int array_a[9] = {0, 2, 9, 1, 2, 2, 3, 3, 3};
    int k = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix_a[i][j] = array_a[k];
            k++;
        }
    }
    identity_matrix(matrix_b, 3);

    int rc = mult_matrices(matrix_a, matrix_b, 3);
    if (rc != 0)
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        ck_abort();
    }

    if (matrix_a[0][0] != 0 || matrix_a[1][2] != 2 || matrix_a[2][1] != 3 || matrix_a[2][2] != 3)
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        ck_abort();
    }

    free_matrix(matrix_a);
    free_matrix(matrix_b);
}
END_TEST

START_TEST(mult_matrices_out_of_range)
{
    int **matrix_a = create_matrix(3, 3);
    int **matrix_b = create_matrix(3, 3);
    int array_a[9] = {0, 2, 9, 1, 2, 2, 3, 3, 3};
    int k = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix_a[i][j] = array_a[k];
            k++;
        }
    }
    identity_matrix(matrix_b, 3);

    int rc = mult_matrices(matrix_a, matrix_b, -1);
    free_matrix(matrix_a);
    free_matrix(matrix_b);
    if (rc == 0)
    {
        ck_abort();
    }
}
END_TEST

Suite *mult_matrices_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("mult_matrices_suite");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, mult_matrices_out_of_range);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, mult_matrices_basic);
    tcase_add_test(tc_pos, mult_matrices_identity);
    suite_add_tcase(s, tc_pos);

    return s;
}