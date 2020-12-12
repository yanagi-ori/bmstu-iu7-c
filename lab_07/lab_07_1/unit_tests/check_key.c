//
// Created by Ivan Bogatyrev on 12/9/2020.
//
#include <check.h>

#include "../inc/array_utils.h"
#include "../inc/errors.h"

/* filter */

START_TEST(test_filter_mixed)
{
    int array[] = {-1, 6, -8, 2, -3, 3, -4, 1, -5, 9};
    int *pb_dst = NULL, *pe_dst = NULL;
    if (key(array, array + 10, &pb_dst, &pe_dst) == 0)
    {
        ck_assert_int_eq(pe_dst - pb_dst, 8);
        ck_assert_int_eq(array[0], pb_dst[0]);
        ck_assert_int_eq(array[1], pb_dst[1]);
        ck_assert_int_eq(array[2], pb_dst[2]);
        ck_assert_int_eq(array[3], pb_dst[3]);
        ck_assert_int_eq(array[4], pb_dst[4]);
        ck_assert_int_eq(array[5], pb_dst[5]);
        ck_assert_int_eq(array[6], pb_dst[6]);
        ck_assert_int_eq(array[7], pb_dst[7]);
    }
    else
    {
        ck_abort_msg("Error in the filter function");
    }
    free_memory(pb_dst);
}

END_TEST

START_TEST(test_filter_one)
{
    int array[] = {2};
    int *pb_dst = NULL, *pe_dst = NULL;
    if (key(array, array + 1, &pb_dst, &pe_dst) == 0)
    {
        ck_assert_int_eq(pe_dst - pb_dst, 1);
        ck_assert_int_eq(array[0], pb_dst[0]);
    }
    else
    {
        ck_abort_msg("Error in the filter function");
    }
    free_memory(pb_dst);
}
END_TEST

START_TEST(test_filter_all_neg)
{
    int array[] = {-1, -5, -2, -7};
    int *pb_dst = NULL, *pe_dst = NULL;
    if (key(array, array + 4, &pb_dst, &pe_dst) == 0)
    {
        ck_assert_int_eq(pe_dst - pb_dst, 3);
        ck_assert_int_eq(array[0], pb_dst[0]);
        ck_assert_int_eq(array[1], pb_dst[1]);
        ck_assert_int_eq(array[2], pb_dst[2]);
    }
    else
    {
        ck_abort_msg("Error in the filter function");
    }
    free_memory(pb_dst);
}
END_TEST

START_TEST(test_filter_all_pos)
{
    int array[] = {1, 5, 2, 7, 1};
    int *pb_dst = NULL, *pe_dst = NULL;
    if (key(array, array + 5, &pb_dst, &pe_dst) == 0)
    {
        ck_assert_int_eq(pe_dst - pb_dst, 5);
        ck_assert_int_eq(array[0], pb_dst[0]);
        ck_assert_int_eq(array[1], pb_dst[1]);
        ck_assert_int_eq(array[2], pb_dst[2]);
        ck_assert_int_eq(array[3], pb_dst[3]);
        ck_assert_int_eq(array[4], pb_dst[4]);
    }
    else
    {
        ck_abort_msg("Error in the filter function");
    }
    free_memory(pb_dst);
}
END_TEST

START_TEST(test_filter_one_neg)
{
    int array[] = {-2};
    int *pb_dst = NULL, *pe_dst = NULL;
    int error_code = key(array, array + 1, &pb_dst, &pe_dst);
    ck_assert_int_eq(error_code, WRONG_DATA);
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

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_filter_invalid_params);
    tcase_add_test(tc_neg, test_filter_one_neg);

    suite_add_tcase(suite, tc_pos);
    suite_add_tcase(suite, tc_neg);
    return suite;
}
