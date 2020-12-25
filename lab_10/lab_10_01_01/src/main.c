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
    if (argc == 3)
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
                        if (strcmp(argv[2], "pop_front") == 0)
                        {
                            student_t *student = (student_t *) pop_front(&list_head.head);
                            printf("%s\n", student->surname);
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
