
#include <stdlib.h>
#include "list.h"

node_t *init_node(int data)
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

void list_free(node_t *head)
{
    while (head)
    {
        node_t *next = head->next;
        free(head);
        head = next;
    }
}

void append(node_t **head_1, node_t **head_2)
{
    if (!head_1)
    {
        return;
    }
    if (!head_2)
    {
        return;
    }

    node_t *node = *head_1;
    if (node)
    {
        while (node->next != NULL)
        {
            node = node->next;
        }
        node->next = *head_2;
        *head_2 = NULL;
    }
    else
    {
        *head_1 = *head_2;
        *head_2 = NULL;
    }
}


int get_length(node_t *head)
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
        node_t *node = init_node(head->data);
        append(head_copy, &node);
        head = head->next;
    }
}

node_t *sum(node_t *num1, node_t *num2)
{
    node_t *result = NULL;
    node_t *temp1 = num1;
    node_t *temp2 = num2;
    int len1 = get_length(temp1);
    int len2 = get_length(temp2);

    if (len2 > len1)
    {
        len1 = len2;
    }

    int temp;
    int add = 0;
    for (int i = 0; i < len1; ++i)
    {
        temp = temp1->data + temp2->data;
        if (add == 1)
        {
            temp++;
        }
        if (temp >= 10)
        {
            add = 1;
            temp -= 10;
        }
        else
        {
            add = 0;
        }

        node_t *new = init_node(temp);
        append(&new, &result);
        result = new;

        if (temp1->next == NULL)
        {
            temp1->data = 0;
        }
        else
        {
            temp1 = temp1->next;
        }
        if (temp2->next == NULL)
        {
            temp2->data = 0;
        }
        else
        {
            temp2 = temp2->next;
        }
    }
    list_free(num1);
    list_free(num2);

    return result;
}