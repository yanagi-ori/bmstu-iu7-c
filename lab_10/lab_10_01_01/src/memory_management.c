//
// Created by Ivan Bogatyrev on 12/23/2020.
//

#include <stdlib.h>
#include "../inc/struct.h"
#include "../inc/errors.h"
#include "../inc/memory_management.h"


int create_memory_manager(memory_manager_t *memory_manager, int limit)
{
    memory_manager->limit = limit;
    memory_manager->nodes_heap = malloc(sizeof(node_t *) * limit);
    if (memory_manager->nodes_heap == NULL)
    {
        return MEMORY_ALLOCATION_ERROR;
    }
    memory_manager->current_size = 0;

    return 0;
}


void free_memory_manager(memory_manager_t *memory_manager)
{
    for (int i = 0; i < memory_manager->current_size; i++)
    {
        free(((student_t *) memory_manager->nodes_heap[i]->data)->surname);
        free(((student_t *) memory_manager->nodes_heap[i]->data)->name);
        free(((student_t *) memory_manager->nodes_heap[i]->data));
        free(memory_manager->nodes_heap[i]);
    }
    free(((student_t *) memory_manager->nodes_heap[memory_manager->current_size]->data));
    free(memory_manager->nodes_heap[memory_manager->current_size]);
}
