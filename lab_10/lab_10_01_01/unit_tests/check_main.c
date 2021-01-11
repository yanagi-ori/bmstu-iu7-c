//
// Created by Ivan Bogatyrev on 1/9/2021.
//

#include <check.h>

Suite *test_sort_suite(void);

int main(void)
{
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(test_sort_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;
}