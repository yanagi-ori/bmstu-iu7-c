//
// Created by Ivan Bogatyrev on 1/12/2021.
//
#include <check.h>
#include <stdio.h>
#include "../inc/list.h"
#include "../inc/operations.h"

START_TEST(test_dvd)
{
    node_t *head_test = NULL, *head_test_1 = NULL, *head_test_2 = NULL;
    node_t *head_test_out_1 = NULL, *head_test_out_2 = NULL;
    FILE *file_test_in = fopen("./func_tests/pos_04_in.txt", "r");
    FILE *file_test_out = fopen("./func_tests/pos_04_out.txt", "r");

    fscanf(file_test_in, "%*s");
    int coefficient, power;
    while (fscanf(file_test_in, "%d", &coefficient) == 1 && fscanf(file_test_in, "%d", &power) == 1)
    {
        node_t *node = create_node(coefficient, (short) power);
        append(&head_test, &node);
    }

    fscanf(file_test_out, "%*s");
    while (fscanf(file_test_out, "%d", &coefficient) == 1 && fscanf(file_test_out, "%d", &power) == 1)
    {
        node_t *node = create_node(coefficient, (short) power);
        append(&head_test_out_1, &node);
    }

    fscanf(file_test_out, "%*s");
    fscanf(file_test_out, "%*s");
    while (fscanf(file_test_out, "%d", &coefficient) == 1 && fscanf(file_test_out, "%d", &power) == 1)
    {
        node_t *node = create_node(coefficient, (short) power);
        append(&head_test_out_2, &node);
    }

    dvd(head_test, &head_test_1, &head_test_2);

    for (int i = 0; i < get_len(head_test_out_1); i++)
    {
        if (head_test_1->coefficient != head_test_out_1->coefficient || head_test_1->power != head_test_out_1->power)
        {
            ck_abort();
        }
    }

    for (int i = 0; i < get_len(head_test_out_2); i++)
    {
        if (head_test_2->coefficient != head_test_out_2->coefficient || head_test_2->power != head_test_out_2->power)
        {
            ck_abort();
        }
    }

    fclose(file_test_in);
    fclose(file_test_out);

    free_list(head_test);
    free_list(head_test_1);
    free_list(head_test_2);
    free_list(head_test_out_1);
    free_list(head_test_out_2);
}

END_TEST

Suite *test_dvd_suite(void)
{
    Suite *suite = suite_create("dvd_suite");

    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_dvd);

    suite_add_tcase(suite, tc_pos);

    return suite;
}


START_TEST(test_ddx)
{
    node_t *head_test_in = NULL, *head_test_out = NULL;
    FILE *file_test_in = fopen("./func_tests/pos_02_in.txt", "r");
    FILE *file_test_out = fopen("./func_tests/pos_02_out.txt", "r");

    fscanf(file_test_in, "%*s");

    int coefficient, power;
    while (fscanf(file_test_in, "%d", &coefficient) == 1 && fscanf(file_test_in, "%d", &power) == 1)
    {
        node_t *node = create_node(coefficient, (short) power);
        append(&head_test_in, &node);
    }

    fscanf(file_test_out, "%*s");
    while (fscanf(file_test_out, "%d", &coefficient) == 1 && fscanf(file_test_out, "%d", &power) == 1)
    {
        node_t *node = create_node(coefficient, (short) power);
        append(&head_test_out, &node);
    }

    node_t *tail = ddx(head_test_in);

//    if (tail != NULL)
//    {
//        del_node_by_pointer(head_test_in, tail);
//    }

    for (int i = 0; i < get_len(head_test_out); i++)
    {
        if (tail->coefficient != head_test_out->coefficient || tail->power != head_test_out->power)
        {
            ck_abort();
        }
    }


    fclose(file_test_in);
    fclose(file_test_out);

    free_list(head_test_in);
    free_list(head_test_out);
    free_list(tail);
}

END_TEST

Suite *test_ddx_suite(void)
{
    Suite *suite = suite_create("ddx_suite");

    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ddx);

    suite_add_tcase(suite, tc_pos);

    return suite;
}


START_TEST(test_polynomial_value)
{
    int var;
    node_t *head_test = NULL;
    FILE *file_test = fopen("./func_tests/pos_01_in.txt", "r");

    fscanf(file_test, "%*s");
    int coefficient, power;
    while (fscanf(file_test, "%d", &coefficient) == 1 && fscanf(file_test, "%d", &power) == 1)
    {
        node_t *node = create_node(coefficient, (short) power);
        append(&head_test, &node);
    }

    fscanf(file_test, "%d", &var);

    ck_assert_int_eq(val(head_test, var), 197);

    fclose(file_test);

    free_list(head_test);
}

END_TEST

Suite *test_val_suite(void)
{
    Suite *suite = suite_create("val_suite");

    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_polynomial_value);

    suite_add_tcase(suite, tc_pos);

    return suite;
}

START_TEST(test_polynomial_sum)
{
    node_t *head_test_1 = NULL, *head_test_2 = NULL;
    node_t *result = NULL, *head_test_out = NULL;
    FILE *file_test_in = fopen("./func_tests/pos_03_in.txt", "r");
    FILE *file_test_out = fopen("./func_tests/pos_03_out.txt", "r");

    fscanf(file_test_in, "%*s");
    int coefficient, power;
    while (fscanf(file_test_in, "%d", &coefficient) == 1 && fscanf(file_test_in, "%d", &power) == 1)
    {
        node_t *node = create_node(coefficient, (short) power);
        append(&head_test_1, &node);
    }

    while (fscanf(file_test_in, "%d", &coefficient) == 1 && fscanf(file_test_in, "%d", &power) == 1)
    {
        node_t *node = create_node(coefficient, (short) power);
        append(&head_test_2, &node);
    }

    fscanf(file_test_out, "%*s");
    while (fscanf(file_test_out, "%d", &coefficient) == 1 && fscanf(file_test_out, "%d", &power) == 1)
    {
        node_t *node = create_node(coefficient, (short) power);
        append(&head_test_out, &node);
    }

    result = sum(head_test_1, head_test_2);

    for (int i = 0; i < get_len(head_test_out); i++)
    {
        if (result->coefficient != head_test_out->coefficient || result->power != head_test_out->power)
        {
            ck_abort();
        }
    }

    fclose(file_test_in);
    fclose(file_test_out);

    free_list(head_test_1);
    free_list(head_test_2);
    free_list(result);
    free_list(head_test_out);
}

END_TEST

Suite *test_sum_suite(void)
{
    Suite *suite = suite_create("sum_suite");

    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_polynomial_sum);

    suite_add_tcase(suite, tc_pos);

    return suite;
}
