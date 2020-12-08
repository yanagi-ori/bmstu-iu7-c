//
// Created by Ivan Bogatyrev on 11/25/2020.
//

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "../inc/io.h"
#include "../inc/array_utils.h"
#include "../inc/errors.h"

/* elements_counter function */
START_TEST(test_elements_counter_casual)
{
    FILE *file = fopen("./unit_tests/counter_check1.txt", "r");
    short int rc;
    unsigned short int counter;
    rc = elements_counter(file, &counter);
    fclose(file);
    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(counter, 7);
}
END_TEST

START_TEST(test_elements_counter_one)
{
    FILE *file = fopen("./unit_tests/counter_check3.txt", "r");
    short int rc;
    unsigned short int counter;
    rc = elements_counter(file, &counter);
    fclose(file);
    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(counter, 1);
}
END_TEST

START_TEST(test_elements_counter_with_chars)
{
    FILE *file = fopen("./unit_tests/counter_check4.txt", "r");
    short int rc;
    unsigned short int counter;
    rc = elements_counter(file, &counter);
    fclose(file);
    ck_assert_int_eq(rc, WRONG_DATA);
}
END_TEST

START_TEST(test_elements_counter_no_elements)
{
    FILE *file = fopen("./unit_tests/counter_check2.txt", "r");
    short int rc;
    unsigned short counter;
    rc = elements_counter(file, &counter);
    fclose(file);
    ck_assert_int_eq(rc, EMPTY_FILE);
}
END_TEST

Suite *element_counter_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("elements_counter");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_elements_counter_no_elements);
    tcase_add_test(tc_neg, test_elements_counter_with_chars);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_elements_counter_casual);
    tcase_add_test(tc_pos, test_elements_counter_one);
    suite_add_tcase(s, tc_pos);

    return s;
}

/* filter */
START_TEST(test_filter_mixed)
{
    int array[] = {-1, 6, -8, 2, -3, 3, -4, 1, -5, 9};
    int *pb_dst = NULL, *pe_dst = NULL;
    if (key(array, array + 10, &pb_dst, &pe_dst) != 0)
    {
        ck_abort_msg("Error in the filter function");
    }
    ck_assert_int_eq(pe_dst - pb_dst, 9);
    ck_assert_int_eq(array[0], pb_dst[0]);
    ck_assert_int_eq(array[1], pb_dst[1]);
    ck_assert_int_eq(array[2], pb_dst[2]);
    ck_assert_int_eq(array[3], pb_dst[3]);
    ck_assert_int_eq(array[4], pb_dst[4]);
    ck_assert_int_eq(array[5], pb_dst[5]);
    ck_assert_int_eq(array[6], pb_dst[6]);
    ck_assert_int_eq(array[7], pb_dst[7]);
    ck_assert_int_eq(array[8], pb_dst[8]);
    free_memory(pb_dst);
}
END_TEST

START_TEST(test_filter_one)
{
    int array[] = {2};
    int *pb_dst = NULL, *pe_dst = NULL;
    if (key(array, array + 1, &pb_dst, &pe_dst) != 0)
    {
        ck_abort_msg("Error in the filter function");
    }
    ck_assert_int_eq(pe_dst - pb_dst, 1);
    ck_assert_int_eq(array[0], pb_dst[0]);
    free_memory(pb_dst);
}
END_TEST

START_TEST(test_filter_all_neg)
{
    int array[] = {-1, -5, -2, -7};
    int *pb_dst = NULL, *pe_dst = NULL;
    if (key(array, array + 4, &pb_dst, &pe_dst) != 0)
    {
        ck_abort_msg("Error in the filter function");
    }
    ck_assert_int_eq(pe_dst - pb_dst, 4);
    ck_assert_int_eq(array[0], pb_dst[0]);
    ck_assert_int_eq(array[1], pb_dst[1]);
    ck_assert_int_eq(array[2], pb_dst[2]);
    ck_assert_int_eq(array[3], pb_dst[3]);
    free_memory(pb_dst);
}
END_TEST

START_TEST(test_filter_all_pos)
{
    int array[] = {1, 5, 2, 7, 1};
    int *pb_dst = NULL, *pe_dst = NULL;
    if (key(array, array + 5, &pb_dst, &pe_dst) != 0)
    {
        ck_abort_msg("Error in the filter function");
    }
    ck_assert_int_eq(pe_dst - pb_dst, 5);
    ck_assert_int_eq(array[0], pb_dst[0]);
    ck_assert_int_eq(array[1], pb_dst[1]);
    ck_assert_int_eq(array[2], pb_dst[2]);
    ck_assert_int_eq(array[3], pb_dst[3]);
    ck_assert_int_eq(array[4], pb_dst[4]);
    free_memory(pb_dst);
}
END_TEST

START_TEST(test_filter_one_neg)
{
    int array[] = {-2};
    int *pb_dst = NULL, *pe_dst = NULL;
    if (key(array, array + 1, &pb_dst, &pe_dst) != 0)
    {
        ck_abort_msg("Error in the filter function");
    }
    ck_assert_int_eq(pe_dst - pb_dst, 1);
    ck_assert_int_eq(array[0], pb_dst[0]);
    free_memory(pb_dst);
}
END_TEST

START_TEST(test_filter_invalid_params)
{
    int err, *pb_dst, *pe_dst;
    int array[2];

    err = key(NULL, array, &pb_dst, &pe_dst);
    ck_assert_int_eq(err, WRONG_DATA);
    err = key(array, NULL, &pb_dst, &pe_dst);
    ck_assert_int_eq(err, WRONG_DATA);
    err = key(array + 1, array, &pb_dst, &pe_dst);
    ck_assert_int_eq(err, WRONG_DATA);
}
END_TEST

Suite *filter_suite(void)
{
    Suite *suite = suite_create("filter");
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_filter_one);
    tcase_add_test(tc_pos, test_filter_mixed);
    tcase_add_test(tc_pos, test_filter_all_neg);
    tcase_add_test(tc_pos, test_filter_all_pos);
    tcase_add_test(tc_pos, test_filter_one_neg);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_filter_invalid_params);

    suite_add_tcase(suite, tc_pos);
    suite_add_tcase(suite, tc_neg);
    return suite;
}

/*sort*/

#define SIZE 25
int int_cmp(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

START_TEST(test_sort_single)
{
    int buffer[] = {123};
    mysort(buffer, 1, sizeof(int), int_cmp);
    ck_assert_int_eq(buffer[0], 123);
}
END_TEST

START_TEST(test_sort_random)
{
    int buffer[SIZE];
    srand(time(NULL));
    for (size_t i = 0; i < SIZE; i++)
        buffer[i] = rand() % 1000 - 500;

    mysort(buffer, SIZE, sizeof(int), int_cmp);
    for (size_t i = 0; i < SIZE - 1; i++)
        ck_assert_int_le(buffer[i], buffer[i + 1]);
}
END_TEST

START_TEST(test_sort_ordered)
{
    int buffer[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        buffer[i] = i;

    mysort(buffer, SIZE, sizeof(int), int_cmp);
    for (size_t i = 0; i < SIZE - 1; i++)
        ck_assert_int_le(buffer[i], buffer[i + 1]);
}
END_TEST

START_TEST(test_sort_reversed)
{
    int buffer[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        buffer[i] = SIZE - i;

    mysort(buffer, SIZE, sizeof(int), int_cmp);
    for (size_t i = 0; i < SIZE - 1; i++)
        ck_assert_int_le(buffer[i], buffer[i + 1]);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s = suite_create("mysort");
    TCase *t = tcase_create("core");
    tcase_add_test(t, test_sort_single);
    tcase_add_test(t, test_sort_random);
    tcase_add_test(t, test_sort_ordered);
    tcase_add_test(t, test_sort_reversed);
    suite_add_tcase(s, t);
    return s;
}

int main(void)
{
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(element_counter_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(filter_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(sort_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;
}

