//
// Created by Ivan Bogatyrev on 1/11/2021.
//

#include <check.h>
#include "../inc/struct.h"
#include "../inc/memory_management.h"
#include "../inc/list_utils.h"

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

    free_data(student);
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