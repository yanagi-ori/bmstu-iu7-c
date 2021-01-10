//
// Created by Ivan Bogatyrev on 12/24/2020.
//

#include "../inc/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/list_utils.h"
#include "../inc/errors.h"


short create_liked_list(linked_list_t *list)
{
    list->head = NULL;

    node_t *curr_element = malloc(sizeof(node_t));

    if (curr_element == NULL)
    {
        return MEMORY_ALLOCATION_ERROR;
    }

    curr_element->next = NULL;
    ((curr_element)->data) = malloc(sizeof(student_t));
    if (curr_element->data == NULL)
    {
        free(curr_element);
        return MEMORY_ALLOCATION_ERROR;
    }
    list->head = curr_element;
    return 0;
}

short append_node(node_t *node)
{
    node_t *new_element = malloc(sizeof(node_t));
    if (new_element == NULL)
    {
        return MEMORY_ALLOCATION_ERROR;
    }
    new_element->data = malloc(sizeof(student_t));
    if (new_element == NULL)
    {
        free(new_element);
        return MEMORY_ALLOCATION_ERROR;
    }
    new_element->next = NULL;
    node->next = new_element;
    return 0;
}

int comparator(const void *a, const void *b)
{
    student_t *student = ((node_t *) a)->data;
    if (strcmp(student->surname, (char *) b) == 0 || strcmp(student->name, (char *) b) == 0)
    {
        return 0;
    }
    if (strcmp(student->year, (char *) b) == 0 || strcmp(student->group, (char *) b) == 0)
    {
        return 0;
    }
    return -1;
}

void *pop_front(node_t **head)
{
    if (!head)
    {
        return NULL;
    }
    if ((*head) == NULL)
    {
        return NULL;
    }
    node_t *node;
    void *data = (*head)->data;
    node = (*head)->next;
    free(*head);
    (*head) = node;
    return data;
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    if (data == NULL || head == NULL)
    {
        return NULL;
    }
    node_t *temp_node = head;
    while (temp_node != NULL)
    {
        if (comparator(temp_node->data, data) == 0)
        {
            return temp_node;
        }
        temp_node = temp_node->next;
    }
    return NULL;
}

void append(node_t **head_a, node_t **head_b)
{
    if (!head_a)
    {
        return;
    }
    if (!head_b)
    {
        return;
    }

    node_t *temp_node = *head_a;
    if (temp_node)
    {
        while (temp_node->next != NULL)
        {
            temp_node = temp_node->next;
        }
        temp_node->next = *head_b;
        *head_b = NULL;
    }
    else
    {
        *head_a = *head_b;
        *head_b = NULL;
    }
}
