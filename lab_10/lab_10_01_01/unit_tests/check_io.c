//
// Created by Ivan Bogatyrev on 1/11/2021.
//

#include "../inc/struct.h"

#include <check.h>
#include <stdio.h>

#include "../inc/list_utils.h"
#include "../inc/io.h"

START_TEST(test_io)
{
    FILE *file = fopen("./unit_tests/data.txt", "r");
    if (!file)
    {
        ck_abort_msg("io error, couldn't access to the file");
    }

    node_t *head = NULL;
    int rc = load_file(file, &head);
    if (rc != 0)
    {
        ck_abort_msg("loading file error");
    }

    node_t *temp = head;
    char *list_surnames[3] = {"Ageev", "Alahov", "Batrakov"};
    for (int i = 0; i < 3; i++)
    {
        student_t *temp_student = head->data;
        if (strcmp(temp_student->surname, list_surnames[i]) != 0)
        {
            ck_abort_msg("comparing error");
        }
        head = head->next;
    }
    free_list(temp);

    fclose(file);
}

END_TEST

Suite *test_io_suite(void)
{

    Suite *suite = suite_create("io_suite");
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_io);
    suite_add_tcase(suite, tc_pos);

    return suite;
}