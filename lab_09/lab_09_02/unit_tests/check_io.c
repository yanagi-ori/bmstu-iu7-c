//
// Created by Ivan Bogatyrev on 12/12/2020.
//
#include "../inc/struct.h"
#include "../inc/io.h"
#include "../inc/struct_ctrl.h"

#include <check.h>
#include <stdio.h>

START_TEST(test_get_item_list_normal)
{
    FILE *file_stream = fopen("./func_tests/pos_01_in.txt", "r");\
    if (file_stream != NULL)
    {
        struct object **array = NULL;
        int length;
        int rc = get_item_list(&array, file_stream, &length);
        ck_assert_int_eq(rc, 0);
        ck_assert_int_eq(length, 15);
        free_array(array, length);
    }
}
END_TEST

START_TEST(test_get_item_list_empty){
    FILE *file_stream = fopen("./func_tests/pos_05_in.txt", "r");
    if (file_stream != NULL){
        struct object **array = NULL;
        int length;
        int rc = get_item_list(&array, file_stream, &length);
        ck_assert_int_eq(rc, 0);
        ck_assert_int_eq(length, 0);
        free_array(array, length);
    }
}
END_TEST


Suite *io_suite(void)
{
    Suite *suite = suite_create("filter");
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_get_item_list_normal);
    tcase_add_test(tc_pos, test_get_item_list_empty);
//    tcase_add_test(tc_pos, test_filter_all_neg);
//    tcase_add_test(tc_pos, test_filter_all_pos);

    tc_neg = tcase_create("negatives");
//    tcase_add_test(tc_neg, test_filter_invalid_params);
//    tcase_add_test(tc_neg, test_filter_one_neg);

    suite_add_tcase(suite, tc_pos);
    suite_add_tcase(suite, tc_neg);
    return suite;
}
