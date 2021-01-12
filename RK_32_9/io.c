
#include <stdio.h>
#include "list.h"
#include "io.h"
#include "errors.h"

int read_file(FILE *file, node_t **head)
{
    char value[11];
    int rv = fscanf(file, "%10s", value);
    if (rv != 1)
    {
        return IO_ERROR;
    }

    int i = 0;
    while (value[i] != '\0')
    {
        node_t *temp = init_node(value[i] - '0');
        if (temp == NULL)
        {
            list_free(*head);
            return MEMORY_ALLOCATION_ERROR;
        }
        append(&temp, head);
        *head = temp;
        i++;
    }

    return 0;
}

void print_num(FILE *stream, node_t *node)
{
    node_t *temp = node;
    if (temp == NULL)
    {
        printf("The number is empty\n");
        return;
    }
    while (temp != NULL)
    {
        fprintf(stream, "%d", temp->data);
        temp = temp->next;
        if (temp != NULL)
        {
            fprintf(stream, "->");
        }
    }
    fprintf(stream, "\n");

}