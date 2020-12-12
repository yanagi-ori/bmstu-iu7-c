//
// Created by Ivan Bogatyrev on 12/12/2020.
//

#include "../inc/struct.h"
#include "../inc/io.h"
#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/struct_ctrl.h"

#include <stdlib.h>
#include <string.h>

void array_print(struct object **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n%f\n%f\n", array[i]->name, array[i]->weight, array[i]->volume);
    }
}

void custom_output(struct object **array, int size, char *substring)
{
    for (int i = 0; i < size; i++)
    {
        if (starts_with(array[i]->name, substring) == 1)
        {
            printf("%s\n%f\n%f\n", array[i]->name, array[i]->weight, array[i]->volume);
        }
    }
}


int get_item_list(struct object ***array, FILE *file, int *length)
{
    int i = 0;
    char temp_name[100];
    double temp_weight = -1, temp_volume = -1;
    struct object *temp_object = NULL;
    int rv;

    rv = fscanf(file, "%100s%lf%lf", temp_name, &temp_weight, &temp_volume);
    while (rv != EOF)
    {
        if (rv != 3)
        {
            return TOO_LONG_ITEM_NAME;
        }
        if (strlen(temp_name) == 0)
        {
            return EMPTY_ITEM_NAME;
        }
        if (temp_weight <= 0 || temp_volume <= 0)
        {
            return WRONG_DATA;
        }
        temp_object = create_object(temp_name, temp_weight, temp_volume);
        if (temp_object)
        {
            *array = add_to_array(*array, temp_object, &i);
            if (array == NULL)
            {
                return MEMORY_ALLOCATION_ERROR;
            }
        }
        else
        {
            return MEMORY_ALLOCATION_ERROR;
        }
        rv = fscanf(file, "%100s%lf%lf", temp_name, &temp_weight, &temp_volume);
    }
    *length = i;
    if (*length == 0)
    {
        *array = malloc(1);
    }
    return 0;
}