#include <check.h>

Suite *test_dvd_suite(void);
Suite *test_ddx_suite(void);
Suite *test_val_suite(void);
Suite *test_sum_suite(void);

int main(void)
{
    SRunner *runner;
    int exit_code = 0;

    runner = srunner_create(test_dvd_suite());
    srunner_run_all(runner, CK_VERBOSE);
    exit_code += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_ddx_suite());
    srunner_run_all(runner, CK_VERBOSE);
    exit_code += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_val_suite());
    srunner_run_all(runner, CK_VERBOSE);
    exit_code += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(test_sum_suite());
    srunner_run_all(runner, CK_VERBOSE);
    exit_code += srunner_ntests_failed(runner);
    srunner_free(runner);

    return exit_code;
}
