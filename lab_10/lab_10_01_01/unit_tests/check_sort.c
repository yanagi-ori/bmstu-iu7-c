//
// Created by Ivan Bogatyrev on 1/11/2021.
//

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/struct.h"
#include "../inc/io.h"
#include "../inc/sort.h"

int get_len(node_t *head)
{
    int len = 0;
    node_t *temp = head;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

START_TEST(test_sort)
{
    int len;
    node_t *head = NULL;
    FILE *file = fopen("./func_tests/pos_01_in.txt", "r");
    if (!file){
        ck_abort();
    }
    int rc = load_file(file, &head);
    if (rc == 0)
    {
        len = get_len(head);
        if (len == -1)
        {
            ck_abort();
        }
        node_t *sorted = sort(head, sort_cmp);
        if (!sorted)
        {
            ck_abort();
        }
        if (len != get_len(sorted))
        {
            ck_abort_msg("incorrect len");
        }

        node_t *temp_node = sorted;
        while (temp_node->next != NULL)
        {
            student_t *student1 = temp_node->data;
            student_t *student2 = temp_node->next->data;
            if (atoi(student1->group) > atoi(student2->group))
            {
                ck_abort_msg("sort order incorrect %s %s", student1->group, student2->group);
            }
            temp_node = temp_node->next;
        }
    }
    else
    {
        ck_abort();
    }
}
END_TEST

Suite *test_sort_suite(void)
{
    Suite *suite = suite_create("utils_suite");
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort);

    suite_add_tcase(suite, tc_pos);

    return suite;
}