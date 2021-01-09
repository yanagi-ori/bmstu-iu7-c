//
// Created by Ivan Bogatyrev on 12/10/2020.
//


#include <check.h>


Suite *matrix_creation_suite(void);

Suite *squaring_suite(void);

Suite *enlargement_suite(void);

Suite *imc_suite(void);

Suite *cmm_suite(void);

Suite *delete_row_suite(void);

int main(void)
{
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(matrix_creation_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(squaring_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(enlargement_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(imc_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(cmm_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(delete_row_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;
}