//
// Created by Ivan Bogatyrev on 12/22/2020.
//

#include <stdio.h>
#include "../inc/struct.h"
#include "../inc/io.h"
#include "../inc/errors.h"
#include "../inc/list_utils.h"
#include "../inc/memory_management.h"


short load_file(FILE *file, node_t **head)
{
    char temp_surname[41], temp_name[41], temp_year[5], temp_group[5];

    int rv;

    do
    {
        rv = fscanf(file, "%40s%40s%4s%4s", temp_surname, temp_name, temp_year, temp_group);
        if (rv == EOF)
        {
            break;
        }
        if (rv != 4)
        {
            return IO_ERROR;
        }

        student_t *new_student = create_data(temp_surname, temp_name, temp_year, temp_group);
        if (!new_student)
        {
            free_list(*head);
            return MEMORY_ALLOCATION_ERROR;
        }

        node_t *new_node = create_node(new_student);
        if (!new_node)
        {
            free_data(new_student);
            free_list(*head);
            return MEMORY_ALLOCATION_ERROR;
        }

        append(head, &new_node);
    } while (true);

    if (*head == NULL){
        return EMPTY_FILE;
    }

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
        printf("%s %s\n", ((student_t *) temp->data)->surname, ((student_t *) temp->data)->group);
        temp = temp->next;
    }
}