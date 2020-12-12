//
// Created by Ivan Bogatyrev on 12/12/2020.
//

#include <check.h>


Suite *io_suite(void);

int main(void)
{
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(io_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;
}

