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
    *length = 0;
    int i = 0;
    char temp_name[256];
    double temp_weight = -1, temp_volume = -1;
    struct object *temp_object = NULL;
    int rv;

    rv = fscanf(file, "%100s%lf%lf", temp_name, &temp_weight, &temp_volume);
    while (rv != EOF)
    {
        if (rv != 3)
        {
            if (*array != NULL)
            {
                free_array(*array, i);
            }
            return TOO_LONG_ITEM_NAME;
        }
        if (strlen(temp_name) == 0)
        {
            if (*array != NULL)
            {
                free_array(*array, i);
            }
            return EMPTY_ITEM_NAME;
        }
        if (temp_weight <= 0 || temp_volume <= 0)
        {
            if (*array != NULL)
            {
                free_array(*array, i);
            }
            return WRONG_DATA;
        }
        temp_object = create_object(temp_name, temp_weight, temp_volume);
        if (temp_object)
        {
            struct object **new_array = add_to_array(*array, temp_object, &i);
            if (new_array == NULL)
            {
                free_array(*array, i);
                return MEMORY_ALLOCATION_ERROR;
            }
            *array = new_array;
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
        if (*array != NULL)
        {
            free_array(*array, 1);
        }
        return NO_ELEMENTS;
    }
    return 0;
}