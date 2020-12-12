//
// Created by Ivan Bogatyrev on 12/12/2020.
//

#include "../inc/struct_ctrl.h"
#include "../inc/struct.h"
#include <stdlib.h>
#include <string.h>

struct object *create_object(char *name, double weight, double value)
{
    struct object *item = malloc(sizeof(struct object));

    if (item)
    {
        item->name = strdup(name);
        if (item->name)
        {
            item->weight = weight;
            item->volume = value;
        }
        else
        {
            free(item);
            item = NULL;
        }
    }
    return item;
}

void free_array(struct object **array, int len)
{
    for (int i = 0; i < len; i++)
    {
        free(array[i]->name);
        free(array[i]);
    }
    free(array);
}