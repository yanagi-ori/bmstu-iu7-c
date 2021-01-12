//
// Created by Ivan Bogatyrev on 1/12/2021.
//

#include <stdlib.h>
#include "../inc/list.h"
#include "../inc/errors.h"

node_t *create_node(int temp_coef, short temp_power)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
    {
        return NULL;
    }

    node->coefficient = temp_coef;
    node->power = temp_power;
    node->next = NULL;

    return node;
}

void free_list(node_t *head)
{
    while (head)
    {
        node_t *next = head->next;
        free(head);
        head = next;
    }
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

void list_copy(node_t *head, node_t **head_copy)
{
    while (head)
    {
        node_t *node = create_node(head->coefficient, head->power);
        append(head_copy, &node);
        head = head->next;
    }
}

node_t *find_var_degree(node_t *head, node_t *node)
{
    for (; head; head = head->next)
    {
        if (head->power == node->power)
        {
            return head;
        }
    }

    return NULL;
}

int insert_node(node_t **head, node_t *node)
{
    node_t *temp_head = *head, *temp_node = create_node(node->coefficient, node->power);

    if (temp_node == NULL)
    {
        return MEMORY_ALLOCATION_ERROR;
    }

    for (; temp_head->next && temp_head->next->power > temp_node->power; temp_head = temp_head->next);

    if (temp_node->power > temp_head->power)
    {
        temp_node->next = *head;
        *head = temp_node;
    }
    else
    {
        temp_node->next = temp_head->next;
        temp_head->next = temp_node;
    }

    return 0;
}
