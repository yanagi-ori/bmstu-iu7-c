#include "utils.h"

int get_item_list(struct object array[ITEMS_ARRAY], FILE *file)
{
    int i = 0;

    int temp = fscanf(file, "%25s%f%f", array[i].name, &(array[i].weight), &(array[i].volume));

    while (temp != EOF)
    {
        if (temp != 3)
        {
            return TOO_LONG_ITEM_NAME;
        }
        if (i >= 15)
        {
            return OUT_OF_RANGE;
        }
        if (strlen(array[i].name) == 0)
        {
            return EMPTY_ITEM_NAME;
        }
        if (array[i].volume <= 0 || array[i].weight <= 0)
        {
            return WRONG_DATA;
        }
        i++;
        temp = fscanf(file, "%25s%f%f", array[i].name, &(array[i].weight), &(array[i].volume));
    }
    return i;
}