//
// Created by Ivan Bogatyrev on 1/11/2021.
//

#include <check.h>
#include "../inc/struct.h"
#include "../inc/memory_management.h"

START_TEST(test_create_data)
{
    student_t *student = create_data("surname", "name", "year", "1");
    if (strcmp("surname", student->surname) != 0 || strcmp("name", student->name) != 0)
    {
        ck_abort();
    }
    if (strcmp("year", student->year) != 0 || strcmp("1", student->group) != 0)
    {
        ck_abort();
    }
    free_data(student);
}
END_TEST

Suite *test_memory_management_suite(void)
{

    Suite *suite = suite_create("memory_management_suite");
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_create_data);
    suite_add_tcase(suite, tc_pos);

    return suite;
}