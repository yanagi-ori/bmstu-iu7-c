//
// Created by Ivan Bogatyrev on 1/12/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/list.h"
#include "../inc/io.h"
#include "../inc/errors.h"


int get_line(node_t **head)
{
    char buf[101], *end;
    long ko, po;

    if (!fgets(buf, 100, stdin))
    {
        return IO_ERROR;
    }
    if (buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = '\0';

    end = buf;

    do
    {
        ko = strtol(end, &end, 10);
        if (*end == '\0')
        {
            free_list(*head);
            return PARSE_ERROR;
        }
        po = strtol(end, &end, 10);
        node_t *node = create_node(ko, (short) po);
        if (!node)
        {
            free(*head);
            return MEMORY_ALLOCATION_ERROR;
        }
        append(head, &node);
    }
    while (*end != '\0');

    return 0;
}

void print_list(node_t *head)
{
    node_t *temp = head;
    if (temp == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d %d ", (temp->coefficient), (temp->power));
        temp = temp->next;
    }
}