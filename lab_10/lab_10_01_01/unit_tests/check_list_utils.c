//
// Created by Ivan Bogatyrev on 1/11/2021.
//

#include <check.h>
#include <stdio.h>
#include "../inc/struct.h"
#include "../inc/memory_management.h"
#include "../inc/list_utils.h"
#include "../inc/io.h"

START_TEST(test_create_node)
{
    student_t *student = create_data("surname", "name", "year", "1");
    node_t *node = create_node(student);

    student_t *data = node->data;
    if (strcmp("surname", data->surname) != 0 || strcmp("name", data->name) != 0)
    {
        ck_abort();
    }
    if (strcmp("year", data->year) != 0 || strcmp("1", data->group) != 0)
    {
        ck_abort();
    }

    free_list(node);
}
END_TEST

Suite *test_create_node_suite(void)
{
    Suite *suite = suite_create("create_node_suite");
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_create_node);
    suite_add_tcase(suite, tc_pos);

    return suite;
}


START_TEST(test_comparator_equal)
{
    student_t *student = create_data("surname", "name", "year", "1");
    int rc = comparator(student, "1");
    if (rc != 0)
    {
        ck_abort();
    }

    free_data(student);
}
END_TEST

START_TEST(test_comparator_not_equal)
{
    student_t *student = create_data("surname", "name", "year", "1");
    int rc = comparator(student, "2");
    if (rc == 0)
    {
        ck_abort();
    }

    free_data(student);
}
END_TEST

Suite *test_comparator_suite(void)
{
    Suite *suite = suite_create("comparator_suite");
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_comparator_equal);
    tcase_add_test(tc_pos, test_comparator_not_equal);
    suite_add_tcase(suite, tc_pos);

    return suite;
}

START_TEST(test_pop_front_positive)
{
    FILE* file = fopen("./unit_tests/data.txt", "r");
    if (!file)
    {
        ck_abort_msg("could not open file");
    }

    node_t *head = NULL;
    int rc = load_file(file, &head);
    if (rc != 0)
    {
        ck_abort_msg("could not load data from file");
    }

    int len = get_len(head);

    student_t *data = pop_front(&head);
    if (strcmp(data->surname, "Ageev") != 0)
    {
        ck_abort_msg("returned incorrect data");
    }

    if (len != (get_len(head) + 1))
    {
        ck_abort_msg("deleted incorrect num of nodes");
    }

    free_data(data);

    free_list(head);

    fclose(file);
}
END_TEST

START_TEST(test_pop_front_negative)
{
    node_t *head = NULL;
    student_t *data = pop_front(&head);
    if (data != NULL)
    {
        ck_abort();
    }
}
END_TEST

Suite *test_pop_front_suite(void)
{
    Suite *suite = suite_create("pop_front_suite");
    TCase *tc_pos;
    TCase *tc_neg;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_pop_front_positive);
    suite_add_tcase(suite, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_pop_front_negative);
    suite_add_tcase(suite, tc_neg);

    return suite;
}

START_TEST(test_find_one)
{
    FILE* file = fopen("./func_tests/pos_01_in.txt", "r");
    if (!file)
    {
        ck_abort_msg("could not open file");
    }

    node_t *head = NULL;
    int rc = load_file(file, &head);
    if (rc != 0)
    {
        ck_abort_msg("could not load data from file");
    }

    node_t *node = find(head, "20", comparator);
    if (strcmp(((student_t *) node->data)->surname, "Klimov") != 0)
    {
        ck_abort_msg("found incorrect node");
    }

    fclose(file);
    free_list(head);
}
END_TEST

START_TEST(test_find_several)
{
    FILE* file = fopen("./func_tests/pos_01_in.txt", "r");
    if (!file)
    {
        ck_abort_msg("could not open file");
    }

    node_t *head = NULL;
    int rc = load_file(file, &head);
    if (rc != 0)
    {
        ck_abort_msg("could not load data from file");
    }

    node_t *node = find(head, "32", comparator);
    if (strcmp(((student_t *) node->data)->surname, "Batrakov") != 0)
    {
        ck_abort_msg("found incorrect node");
    }

    fclose(file);
    free_list(head);
}
END_TEST

START_TEST(test_find_no)
{
    FILE* file = fopen("./func_tests/pos_01_in.txt", "r");
    if (!file)
    {
        ck_abort_msg("could not open file");
    }

    node_t *head = NULL;
    int rc = load_file(file, &head);
    if (rc != 0)
    {
        ck_abort_msg("could not load data from file");
    }

    node_t *node = find(head, "99", comparator);
    if (node != NULL)
    {
        ck_abort();
    }

    fclose(file);
    free_list(head);
}
END_TEST

Suite *test_find_suite(void)
{
    Suite *suite = suite_create("find_suite");
    TCase *tc_pos;
    TCase *tc_neg;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_find_one);
    tcase_add_test(tc_pos, test_find_several);
    suite_add_tcase(suite, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_find_no);
    suite_add_tcase(suite, tc_neg);

    return suite;
}


START_TEST(test_append_normal)
{
    int len = 0;

    FILE* file1 = fopen("./func_tests/pos_01_in.txt", "r");
    if (!file1)
    {
        ck_abort_msg("could not open file1");
    }

    node_t *head1 = NULL;
    int rc = load_file(file1, &head1);
    if (rc != 0)
    {
        ck_abort_msg("could not load data from file1");
    }

    len += get_len(head1);

    FILE* file2 = fopen("./func_tests/pos_01_in.txt", "r");
    if (!file2)
    {
        ck_abort_msg("could not open file2");
    }

    node_t *head2 = NULL;
    rc = load_file(file2, &head2);
    if (rc != 0)
    {
        ck_abort_msg("could not load data from file2");
    }

    len += get_len(head2);

    append(&head1, &head2);

    if (len != get_len(head1))
    {
        ck_abort_msg("incorrect len of result list");
    }

    fclose(file1);
    fclose(file2);
    free_list(head1);
}
END_TEST

START_TEST(test_append_null)
{
    FILE* file = fopen("./func_tests/pos_01_in.txt", "r");
    if (!file)
    {
        ck_abort_msg("could not open file");
    }

    node_t *head1 = NULL;
    node_t *head2 = NULL;
    int rc = load_file(file, &head2);
    if (rc != 0)
    {
        ck_abort_msg("could not load data from file");
    }
    int len = get_len(head2);

    append(&head1, &head2);
    if (len != get_len(head1))
    {
        ck_abort_msg("incorrect len of result list");
    }

    fclose(file);
    free_list(head1);
}
END_TEST

Suite *test_append_suite(void)
{
    Suite *suite = suite_create("append_suite");
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_append_normal);
    tcase_add_test(tc_pos, test_append_null);
    suite_add_tcase(suite, tc_pos);

    return suite;
}