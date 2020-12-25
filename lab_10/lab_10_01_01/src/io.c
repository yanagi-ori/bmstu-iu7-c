//
// Created by Ivan Bogatyrev on 12/22/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/struct.h"
#include "../inc/memory_management.h"
#include "../inc/io.h"
#include "../inc/errors.h"
#include "../inc/list_utils.h"


short load_file(FILE *file, linked_list_t *list, memory_manager_t *memory_manager)
{
    char temp_surname[41], temp_name[41], temp_year[5], temp_group[41];

    int rv = 4;
    int rc;

    if (list == NULL)
    {
        return MEMORY_ALLOCATION_ERROR;
    }
    node_t *node = list->head;
    memory_manager->nodes_heap[memory_manager->current_size] = node;
    while (true)
    {

        if (node->data == NULL)
        {
            return MEMORY_ALLOCATION_ERROR;
        }
        rv = fscanf(file, "%40s%40s%4s%40s", temp_surname, temp_name, temp_year, temp_group);
        if (rv == EOF)
        {
            break;
        }
        if (rv != 4)
        {
            return IO_ERROR;
        }
        ((student_t *) node->data)->surname = strdup(temp_surname);
        ((student_t *) node->data)->name = strdup(temp_name);
        ((student_t *) node->data)->year = strdup(temp_year);
        ((student_t *) node->data)->group = strdup(temp_group);

        rc = append_node(node);
        if (rc == MEMORY_ALLOCATION_ERROR)
        {
            return MEMORY_ALLOCATION_ERROR;
        }
        memory_manager->current_size++;
        if (memory_manager->current_size > memory_manager->limit)
        {
            memory_manager->limit += 10;
            memory_manager->nodes_heap = realloc(memory_manager->nodes_heap, memory_manager->limit);
            if (memory_manager->nodes_heap == NULL)
            {
                return MEMORY_ALLOCATION_ERROR;
            }
        }
        node = node->next;
        memory_manager->nodes_heap[memory_manager->current_size] = node;
    }

    return 0;
}