#include "utils.h"

bool starts_with(const char *a, const char *b)
{
    if (strcmp(b, "ALL") == 0)
    {
        return 1;
    }
    return (strncmp(a, b, strlen(b)) == 0);
}

double density(const float weight, const float value)
{
    if (value == 0)
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

int selection_sort(struct object *array_start, struct object *array_end)
{
    for (struct object *i = array_start; i < array_end; i++)
    {
        double minz = density(i->weight, i->volume);
        if (minz == -1)
        {
            return WRONG_DATA;
        }
        struct object *ind = i;
        for (struct object *j = i + 1; j < array_end; j++)
        {
            if (density(j->weight, j->volume) < minz)
            {
                minz = density(j->weight, j->volume), ind = j;
                if (minz == -1)
                {
                    return WRONG_DATA;
                }
            }
        }
        swap(i, ind);
    }
    return 0;
}
