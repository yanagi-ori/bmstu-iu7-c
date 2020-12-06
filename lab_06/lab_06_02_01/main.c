#include <stdio.h>
#include "utils.h"


int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 3)
    {
        return WRONG_ARGUMENTS;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return ERROR_IO;
    }

    struct object objects[ITEMS_ARRAY];

    if (argc == 2)
    {
        int length = get_item_list(objects, file);
        fclose(file);
        if (length <= 0)
        {
            return WRONG_DATA;
        }
        int rc = selection_sort(&objects[0], &objects[length]);
        if (rc == WRONG_DATA)
        {
            return WRONG_DATA;
        }
        array_print(objects, length);
    }
    if (argc == 3)
    {
        int length = get_item_list(objects, file);
        fclose(file);
        if (length <= 0)
        {
            return WRONG_DATA;
        }

        custom_output(objects, length, argv[2]);
    }

    return 0;
}
