//
// Created by Ivan Bogatyrev on 12/23/2020.
//

#ifndef LAB_10_01_01_MEMORY_MANAGEMENT_H
#define LAB_10_01_01_MEMORY_MANAGEMENT_H

#include "./struct.h"

int create_memory_manager(memory_manager_t *memory_manager, int limit);

void free_memory_manager(memory_manager_t *memory_manager);


#endif //LAB_10_01_01_MEMORY_MANAGEMENT_H
