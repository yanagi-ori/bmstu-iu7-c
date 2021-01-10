#include <stdio.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/struct.h"
#include "../inc/list_utils.h"
#include "../inc/io.h"
#include "../inc/sort.h"
#include "../inc/memory_management.h"

// 1 2 2 1

int main(int argc, char **argv)
{
    int rc;
    if (argc >= 3)
    {
        FILE *file = fopen(argv[1], "r");
        if (file != NULL)
        {
            node_t *head = NULL;

            rc = load_file(file, &head);
            if (rc == 0)
            {
                if (strcmp(argv[2], "pop_front") == 0 && argc == 3)
                {
                    student_t *student = (student_t *) pop_front(&head);
                    printf("%s %s %s %s\n", student->surname, student->name, student->year, student->group);
                    free_data(student);
                }
                else if (strcmp(argv[2], "find") == 0)
                {
                    node_t *node = find(head, argv[3], comparator);
                    if (node == NULL)
                    {
                        rc = FIND_ERROR;
                    }
                    else
                    {
                        student_t *student = (student_t *) (node->data);
                        printf("%s %s %s %s\n", student->surname, student->name, student->year, student->group);
                    }
                }
                else if (strcmp(argv[2], "sort") == 0 && argc == 3)
                {
                    node_t *sorted_list = sort(head, sort_cmp);
                    if (sorted_list == NULL)
                    {
                        rc = SORT_ERROR;
                    }
                    else
                    {
                        print_list(sorted_list);
                    }
                }
                else if (strcmp(argv[2], "append") == 0 && argc == 4)
                {
                    FILE *new_file = fopen(argv[3], "r");
                    if (new_file != NULL)
                    {
                        node_t *head2 = NULL;

                        rc = load_file(new_file, &head2);
                        if (rc == 0)
                        {
                            append(&head, &head2);
                            printf("Output of list a: \n");
                            print_list(head);
                            printf("\nOutput of list b: \n");
                            print_list(head2);
                        }

                        fclose(new_file);
                    }
                    else
                    {
                        rc = IO_ERROR;
                    }
                }
            }

            free_list(head);

            fclose(file);
        }
        else
        {
            rc = IO_ERROR;
        }
    }
    else
    {
        rc = INVALID_ARGUMENTS;
    }
    return rc;
}
