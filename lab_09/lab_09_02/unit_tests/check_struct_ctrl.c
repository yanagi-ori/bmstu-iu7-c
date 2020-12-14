//
// Created by Ivan Bogatyrev on 12/13/2020.
//

#include "../inc/struct.h"
#include "../inc/struct_ctrl.h"
#include "../inc/errors.h"
#include <math.h>
#include <check.h>
#include <stdlib.h>

START_TEST(test_create_object_normal_int)
{
    struct object *test_object = create_object("water", 1, 1);
    if (test_object == NULL)
    {
        ck_abort_msg("Object has not been created");
    }
    ck_assert(fabs(test_object->weight - 1) <= EPS);
    ck_assert(fabs(test_object->volume - 1) <= EPS);
    ck_assert_str_eq(test_object->name, "water");
    free(test_object->name);
    free(test_object);
}
END_TEST

START_TEST(test_create_object_normal_float)
{
    struct object *test_object = create_object("test", 3.333333, 0.78);
    if (test_object == NULL)
    {
        ck_abort_msg("Object has not been created");
    }
    ck_assert(fabs(test_object->weight - 3.333333) <= EPS);
    ck_assert(fabs(test_object->volume - 0.78) <= EPS);
    ck_assert_str_eq(test_object->name, "test");
    free(test_object->name);
    free(test_object);
}
END_TEST

START_TEST(test_create_object_null_name)
{
    struct object *test_object = create_object(NULL, 1, 1);
    if (test_object != NULL)
    {
        if (test_object->name)
        {
            free(test_object->name);
        }
        free(test_object);
        ck_abort_msg("Function returned not NULL");
    }
}
END_TEST

START_TEST(test_create_object_negative_value)
{
    struct object *test_object = create_object("test", -11, 1);
    if (test_object != NULL)
    {
        if (test_object->name)
        {
            free(test_object->name);
        }
        free(test_object);
        ck_abort_msg("Function returned not NULL");
    }
}
END_TEST

START_TEST(test_create_object_zero_value)
{
    struct object *test_object = create_object(NULL, 1, 0);
    if (test_object != NULL)
    {
        if (test_object->name)
        {
            free(test_object->name);
        }
        free(test_object);
        ck_abort_msg("Function returned not NULL");
    }
}
END_TEST



Suite *struct_ctrl_suite(void)
{
    Suite *suite = suite_create("struct_ctrl_suite");
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_create_object_normal_int);
    tcase_add_test(tc_pos, test_create_object_normal_float);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_create_object_null_name);
    tcase_add_test(tc_neg, test_create_object_negative_value);
    tcase_add_test(tc_neg, test_create_object_zero_value);

    suite_add_tcase(suite, tc_pos);
    suite_add_tcase(suite, tc_neg);
    return suite;
}
