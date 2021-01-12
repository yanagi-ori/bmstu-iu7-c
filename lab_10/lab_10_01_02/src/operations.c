//
// Created by Ivan Bogatyrev on 1/12/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "../inc/list.h"
#include "../inc/operations.h"
#include "../inc/errors.h"

int val(node_t *head, long a)
{
    int sum = 0;
    int power;
    while (head)
    {
        power = 1;
        for (int i = 0; i < head->power; i++)
        {
            power = power * a;
        }
        sum = sum + head->coefficient * power;
        head = head->next;
    }
    return sum;
}

node_t *ddx(node_t *head)
{
    node_t *new_list = NULL;
    int ko_new = 0;
    int po_new = 0;
    while (head)
    {
        if (head->power != 0)
        {
            ko_new = head->coefficient * head->power;
            po_new = head->power - 1;
            node_t *node = create_node(ko_new, (short) po_new);
            append(&new_list, &node);
        }
        head = head->next;
    }
    return new_list;
}

int push_1(node_t **head, long value_1, long value_2)
{
    node_t *tmp = malloc(sizeof(node_t));
    if (tmp == NULL)
    {
        //printf("Ошибка! Переполнение стека");
        //exit(-101);
        return MEMORY_ALLOCATION_ERROR;
    }
    tmp->next = *head;
    tmp->coefficient = value_1;
    tmp->power = (short) value_2;
    *head = tmp;
    //free(tmp);
    return 0;
}


node_t *sum(node_t *head1, node_t *head2)
{
    node_t *result = NULL;
    list_copy(head1, &result);

    node_t *temp_node, *temp_head = result;

    while (temp_head)
    {
        temp_node = find_var_degree(head2, temp_head);
        if (temp_node != NULL)
        {
            temp_head->coefficient += temp_node->coefficient;
        }
        temp_head = temp_head->next;
    }

    temp_head = head2;

    while (temp_head)
    {
        temp_node = find_var_degree(result, temp_head);
        if (temp_node == NULL)
        {
            if (insert_node(&result, temp_head) != 0)
            {
                free_list(head1);
                free_list(head2);
                free_list(result);
                return NULL;
            }
        }
        temp_head = temp_head->next;
    }

    return result;
}

void dvd(const node_t *head, node_t **head_even, node_t **head_odd)
{
    while (head)
    {
        node_t *node = create_node(head->coefficient, head->power);
        if (head->power % 2 == 0)
        {
            append(head_even, &node);
        }
        else
        {
            append(head_odd, &node);
        }
        head = head->next;
    }
}