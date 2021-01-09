//
// Created by Ivan Bogatyrev on 12/10/2020.
//


#include <check.h>
#include <stdio.h>


Suite *matrix_creation_suite(void);

Suite *squaring_suite(void);

Suite *enlargement_suite(void);

Suite *imc_suite(void);

Suite *cmm_suite(void);

Suite *delete_row_suite(void);

Suite *delete_column_suite(void);

Suite *copy_old_to_new_suite(void);

Suite *find_geom_mean_of_col_suite(void);

Suite *add_new_row_suite(void);

Suite *find_max_in_row_suite(void);

Suite *add_new_col_suite(void);

Suite *find_mult_result_suite(void);

Suite *mult_matrices_suite(void);

Suite *matrix_pow_suite(void);

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
    runner = srunner_create(delete_column_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(copy_old_to_new_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(find_geom_mean_of_col_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(add_new_row_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(find_max_in_row_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(add_new_col_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(find_mult_result_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(mult_matrices_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    runner = srunner_create(matrix_pow_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    printf("%d errors\n", no_failed);
    return (no_failed == 0) ? 0 : 1;
}