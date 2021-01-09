//
// Created by Ivan Bogatyrev on 12/10/2020.
//

#include <check.h>
#include "../inc/errors.h"
#include "../inc/matrix_creation.h"

START_TEST(test_create_matrix_normal)
{
    int **matrix = create_matrix(3, 3);
    if (matrix != NULL)
    {
        free_matrix(matrix);
    }
    else
        ck_abort();
}

END_TEST

START_TEST(test_create_matrix_one)
{
    int **matrix = create_matrix(1, 1);
    if (matrix != NULL)
    {
        free_matrix(matrix);
    }
    else
        ck_abort();
}

END_TEST

START_TEST(test_create_matrix_zero)
{
    int **matrix = create_matrix(0, 0);
    if (matrix != NULL)
    {
        free_matrix(matrix);
        ck_abort();
    }
}

END_TEST

START_TEST(test_create_matrix_negative)
{
    int **matrix = create_matrix(0, -1);
    if (matrix != NULL)
    {
        free_matrix(matrix);
        ck_abort();
    }
}

END_TEST


Suite *matrix_creation_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("matrix_creation");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_create_matrix_zero);
    tcase_add_test(tc_neg, test_create_matrix_negative);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_create_matrix_one);
    tcase_add_test(tc_pos, test_create_matrix_normal);
    suite_add_tcase(s, tc_pos);

    return s;
}