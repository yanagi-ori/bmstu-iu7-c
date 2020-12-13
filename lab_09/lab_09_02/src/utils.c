#include "../inc/struct.h"
#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/struct_ctrl.h"

#include <string.h>
#include <stdlib.h>
#include <math.h>

int starts_with(const char *a, const char *b)
{
    if (strcmp(b, "ALL") == 0)
    {
        return 1;
    }
    return (strncmp(a, b, strlen(b)) == 0);
}

double density(const double weight, const double value)
{
    if (fabs(value) < EPS)
    {
        return -1;
    }
    return ((double) weight) / ((double) value);
}

void swap(struct object *a, struct object *b)
{
    struct object temp = *a;
    *a = *b;
    *b = temp;
}

int selection_sort(struct object **array_start, struct object **array_end)
{
    for (struct object **i = array_start; i < array_end - 1; i++)
    {
        double minz = density((*i)->weight, (*i)->volume);
        if (fabs(minz + 1) < EPS)
        {
            return WRONG_DATA;
        }
        struct object **ind = i;
        for (struct object **j = i + 1; j < array_end; j++)
        {
            if (density((*j)->weight, (*j)->volume) < minz)
            {
                minz = density((*j)->weight, (*j)->volume), ind = j;
                if (fabs(minz + 1) < EPS)
                {
                    return WRONG_DATA;
                }
            }
        }
        swap(*i, *ind);
    }
    return 0;
}

struct object **add_to_array(struct object **array, struct object *new_item, int *len)
{
    struct object **new_array;
    if (array == NULL)
    {
        new_array = malloc(sizeof(struct object *));
    }
    else
    {
        new_array = realloc(array, sizeof(struct object *) * ((*len) + 2));
    }
    if (new_array == NULL)
    {
        if (array != NULL)
        {
            free_array(array, *len);
        }
        return NULL;
    }
    new_array[*len] = new_item;
    (*len)++;
    return new_array;
}
