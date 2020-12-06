#include "utils.h"


void array_print(struct object array[ITEMS_ARRAY], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n%f\n%f\n", array[i].name, array[i].weight, array[i].volume);
    }
}

void custom_output(struct object array[ITEMS_ARRAY], int size, char substring[])
{
    for (int i = 0; i < size; i++)
    {
        if (starts_with(array[i].name, substring) == 1)
        {
            printf("%s\n%f\n%f\n", array[i].name, array[i].weight, array[i].volume);
        }
    }
}