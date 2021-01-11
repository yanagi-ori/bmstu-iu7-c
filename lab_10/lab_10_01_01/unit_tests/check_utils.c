//
// Created by Ivan Bogatyrev on 1/11/2021.
//

#include <check.h>
#include <stdlib.h>
#include "../inc/utils.h"

START_TEST(test_strdup)
{
    char source[10] = "hello";
    char *test = my_strdup(source);
    if (strcmp(source, test) != 0)
    {
        ck_abort();
    }
    free(test);
}
END_TEST

Suite *test_utils_suite(void)
{

    Suite *suite = suite_create("utils_suite");
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_strdup);
    suite_add_tcase(suite, tc_pos);

    return suite;
}