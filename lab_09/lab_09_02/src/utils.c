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

int density(const double weight, const double value, double *density)
{
    if (value <= 0 || weight <= 0)
    {
        return WRONG_DATA;
    }
    *density = ((double) weight) / ((double) value);
    return 0;
}

void swap(struct object *a, struct object *b)
{
    struct object temp = *a;
    *a = *b;
    *b = temp;
}

int selection_sort(struct object **array_start, struct object **array_end)
{
    int rc = 0;
    for (struct object **i = array_start; i < array_end - 1; i++)
    {
        double minz = 0;
        rc = density((*i)->weight, (*i)->volume, &minz);
        if (rc != 0)
        {
            return WRONG_DATA;
        }
        if (fabs(minz + 1) < EPS)
        {
            return WRONG_DATA;
        }
        struct object **ind = i;
        for (struct object **j = i + 1; j < array_end; j++)
        {
            double temp;
            rc = density((*j)->weight, (*j)->volume, &temp);
            if (rc != 0)
            {
                return WRONG_DATA;
            }
            if (temp < minz)
            {
                rc = density((*j)->weight, (*j)->volume, &minz), ind = j;
                if (rc != 0)
                {
                    return WRONG_DATA;
                }
                if (fabs(minz + 1) < EPS)
                {
                    return WRONG_DATA;
                }
            }
        }
        swap(*i, *ind);
    }
    return rc;
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
