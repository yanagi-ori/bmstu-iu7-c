//
// Created by Ivan Bogatyrev on 12/14/2020.
//

#include <check.h>
#include <stdlib.h>
#include "../inc/struct.h"
#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/struct_ctrl.h"

// starts_with function
START_TEST(test_starts_with_full)
{
    ck_assert(starts_with("test", "test") != 0);
}

END_TEST

START_TEST(test_starts_with_one)
{
    ck_assert(starts_with("test", "t") != 0);
}
END_TEST

START_TEST(test_starts_with_all)
{
    ck_assert(starts_with("test", "ALL") != 0);
}
END_TEST

START_TEST(test_starts_with_negative)
{
    ck_assert(starts_with("test", "no") == 0);
}
END_TEST

// density function
START_TEST(test_density_int)
{
    double temp;
    int rc = density(1, 1, &temp);
    ck_assert_int_eq(rc, 0);
    ck_assert(temp - 1 <= EPS);
}
END_TEST

START_TEST(test_density_normal)
{
    double temp;
    int rc = density(1, 2, &temp);
    ck_assert_int_eq(rc, 0);
    ck_assert(temp - 0.5 <= EPS);
}
END_TEST

START_TEST(test_density_zero_value)
{
    double temp;
    int rc = density(5, 0, &temp);
    ck_assert_int_eq(rc, WRONG_DATA);
}
END_TEST

START_TEST(test_density_negative_values)
{
    double temp;
    int rc = density(-1, 3, &temp);
    ck_assert_int_eq(rc, WRONG_DATA);
}
END_TEST


// add_to_array function
START_TEST(test_ata_to_empty)
{
    struct object *test = create_object("name", 1, 1);
    struct object **array = NULL;
    int len = 0;
    array = add_to_array(array, test, &len);
    ck_assert(len == 1);
    ck_assert(array != NULL);
    free(test->name);
    free(test);
    free(array);
}
END_TEST

START_TEST(test_ata_to_array)
{
    struct object *test1 = create_object("name", 1, 1);
    struct object **array = NULL;
    int len = 0;
    array = add_to_array(array, test1, &len);
    struct object *test2 = create_object("test", 1, 1);
    array = add_to_array(array, test2, &len);
    ck_assert(len == 2);
    ck_assert(array != NULL);
    free_array(array, len);
}
END_TEST

// sort
START_TEST(test_sort_one)
{
    struct object *test = create_object("name", 1, 1);
    struct object **array = NULL;
    int len = 0;
    array = add_to_array(array, test, &len);
    ck_assert_str_eq(array[0]->name, "name");
    free(test->name);
    free(test);
    free(array);
}
END_TEST

START_TEST(test_sort_array)
{
    struct object *test1 = create_object("name", 5, 1);
    struct object **array = NULL;
    int len = 0;
    array = add_to_array(array, test1, &len);
    struct object *test2 = create_object("test", 3, 1);
    array = add_to_array(array, test2, &len);
    ck_assert(array[0] == test2);
    ck_assert(array[1] == test1);
    free_array(array, len);
}
END_TEST


Suite *utils_suite(void)
{
    Suite *suite = suite_create("utils_suite");
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_starts_with_full);
    tcase_add_test(tc_pos, test_starts_with_one);
    tcase_add_test(tc_pos, test_starts_with_all);
    tcase_add_test(tc_pos, test_starts_with_negative);

    tcase_add_test(tc_pos, test_density_int);
    tcase_add_test(tc_pos, test_density_normal);

    tcase_add_test(tc_pos, test_ata_to_empty);
    tcase_add_test(tc_pos, test_ata_to_array);

    tcase_add_test(tc_pos, test_sort_one);
    tcase_add_test(tc_pos, test_sort_array);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_density_zero_value);
    tcase_add_test(tc_neg, test_density_negative_values);
    suite_add_tcase(suite, tc_pos);
    suite_add_tcase(suite, tc_neg);
    return suite;
}
