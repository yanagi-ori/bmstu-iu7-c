#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/struct.h"
#include "../inc/list_utils.h"
#include "../inc/io.h"
#include "../inc/memory_management.h"

// 1 2 2 1

int main(int argc, char **argv)
{
    int rc = 0;
    if (argc >= 3)
    {
        FILE *file = fopen(argv[1], "r");
        if (file != NULL)
        {
            memory_manager_t *memory_manager = malloc(sizeof(memory_manager_t));
            rc = create_memory_manager(memory_manager, 125);
            if (rc == 0)
            {
                linked_list_t list_head;
                rc = create_liked_list(&list_head);
                if (rc == 0)
                {
                    rc = load_file(file, &list_head, memory_manager);
                    if (rc == 0)
                    {
                        if (strcmp(argv[2], "pop_front") == 0 && argc == 3)
                        {
                            student_t *student = (student_t *) pop_front(&list_head.head);
                            printf("%s %s %s %s\n", student->surname, student->name, student->year, student->group);
                        }
                        else if (strcmp(argv[2], "find") == 0)
                        {
                            node_t *node = find(list_head.head, argv[3], comparator);
                            if (node == NULL)
                            {
                                rc = FIND_ERROR;
                            }
                            else
                            {
                                student_t *student = (student_t *) (node->data);
                                printf("%s %s %s %s\n",
                                       student->surname, student->name,
                                       student->year, student->group);
                            }
                        }
                        else if (strcmp(argv[2], "append") == 0 && argc == 4)
                        {
                            FILE *new_file = fopen(argv[3], "r");
                            if (new_file != NULL)
                            {
                                memory_manager_t *new_mm = malloc(sizeof(memory_manager_t));
                                rc = create_memory_manager(new_mm, 125);
                                if (rc == 0)
                                {
                                    linked_list_t new_list;
                                    rc = create_liked_list(&new_list);
                                    if (rc == 0)
                                    {
                                        rc = load_file(new_file, &new_list, new_mm);
                                        if (rc == 0)
                                        {
                                            append(&(list_head.head), &(new_list.head));
                                            printf("Output of list a: \n");
                                            print_list(list_head.head);
                                            printf("\nOutput of list b: \n");
                                            print_list(new_list.head);
                                        }
                                    }
                                    free_memory_manager(new_mm);
                                    free(new_mm->nodes_heap);
                                    free(new_mm);
                                }

                            }
                            else
                            {
                                rc = IO_ERROR;
                            }
                        }
                    }
                }
                free_memory_manager(memory_manager);
                free(memory_manager->nodes_heap);
                free(memory_manager);
            }

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
