//
// Created by Ivan Bogatyrev on 12/28/2020.
//

#include <check.h>
#include "../inc/matrix_creation.h"
#include "../inc/matrix_operations.h"

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


Suite *enlargement_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("enlargement_suite");
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