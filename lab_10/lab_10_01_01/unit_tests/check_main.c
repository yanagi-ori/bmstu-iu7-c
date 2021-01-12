//
// Created by Ivan Bogatyrev on 1/9/2021.
//

#include <check.h>

Suite *test_sort_suite(void);

Suite *test_memory_management_suite(void);

Suite *test_utils_suite(void);

Suite *test_io_suite(void);

Suite *test_create_node_suite(void);

Suite *test_comparator_suite(void);

Suite *test_pop_front_suite(void);

Suite *test_find_suite(void);

Suite *test_append_suite(void);

int main(void)
{
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(test_sort_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_memory_management_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_utils_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_io_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_create_node_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_comparator_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_pop_front_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_find_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_append_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;
}