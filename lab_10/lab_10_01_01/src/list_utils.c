//
// Created by Ivan Bogatyrev on 12/24/2020.
//

#include "../inc/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "../inc/list_utils.h"
#include "../inc/memory_management.h"

node_t *create_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
    {
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void free_list(node_t *head)
{
    while (head)
    {
        node_t *next = head->next;
        free_data(head->data);
        free(head);
        head = next;
    }
}

int comparator(const void *a, const void *b)
{
    student_t *student_a = (student_t *) a;
    int stgr_1 = atoi(student_a->group);
    int stgr_2 = atoi((char *) b);
    return stgr_1 - stgr_2;
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