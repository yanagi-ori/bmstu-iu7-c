//
// Created by Ivan Bogatyrev on 12/9/2020.
//

#include <check.h>
#include <stdio.h>

#include "../inc/io.h"
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