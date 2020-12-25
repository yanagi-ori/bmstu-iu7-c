//
// Created by Ivan Bogatyrev on 12/22/2020.
//

#ifndef LAB_10_01_01_STRUCT_H
#define LAB_10_01_01_STRUCT_H

#include <stdbool.h>

typedef struct student
{
    char *surname;
    char *name;
    char *group;
    char *year;
} student_t;

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

typedef struct linked_list
{
    node_t *head;
} linked_list_t;

typedef struct memory_manager
{
    node_t **nodes_heap;
    int current_size;
    int limit;
} memory_manager_t;

#endif //LAB_10_01_01_STRUCT_H
