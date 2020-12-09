//
// Created by Ivan Bogatyrev on 12/9/2020.
//


#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../inc/array_utils.h"


/*sort*/

#define SIZE 25

int int_cmp(const void *x, const void *y)
{
    return *(int *) x - *(int *) y;
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
    {
        buffer[i] = rand() % 1000 - 500;
    }

    mysort(buffer, SIZE, sizeof(int), int_cmp);
    for (size_t i = 0; i < SIZE - 1; i++)
        ck_assert_int_le(buffer[i], buffer[i + 1]);
}
END_TEST

START_TEST(test_sort_ordered)
{
    int buffer[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        buffer[i] = i;
    }

    mysort(buffer, SIZE, sizeof(int), int_cmp);
    for (size_t i = 0; i < SIZE - 1; i++)
        ck_assert_int_le(buffer[i], buffer[i + 1]);
}
END_TEST

START_TEST(test_sort_reversed)
{
    int buffer[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        buffer[i] = SIZE - i;
    }

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