//
// Created by Ivan Bogatyrev on 1/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "../inc/struct.h"
#include "../inc/sort.h"

int sort_cmp(const void *a, const void *b)
{
    student_t *student_a = (student_t *) a;
    student_t *student_b = (student_t *) b;
    int stgr_1 = atoi(student_a->group);
    int stgr_2 = atoi(student_b->group);
    return stgr_1 - stgr_2;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (*head == NULL)
    {
        element->next = *head;
        *head = element;
    }
    else
    {
        node_t *tnode = *head;

        for (; tnode->next != NULL && comparator(element->data, tnode->next->data) > 0; tnode = tnode->next);

        if (comparator(tnode->data, element->data) > 0)
        {
            element->next = *head;
            *head = element;
        }
        else
        {
            element->next = tnode->next;
            tnode->next = element;
        }
    }
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head == NULL || comparator == NULL)
    {
        return NULL;
    }

    node_t *head_sorted = NULL;

    for (node_t *next; head; head = next)
    {
        next = head->next;

        sorted_insert(&head_sorted, head, comparator);
    }

    return head_sorted;
}

