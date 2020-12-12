#include <stdio.h>
#include "../inc/struct.h"
#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/io.h"
#include "../inc/struct_ctrl.h"


int main(int argc, char *argv[])
{
    int rc = 0;
    if (argc == 2 || argc == 3)
    {
        FILE *file_stream = fopen(argv[1], "r");
        if (file_stream != NULL)
        {
            struct object **array = NULL;

            if (argc == 2)
            {
                int length;
                rc = get_item_list(&array, file_stream, &length);
                if (rc == 0)
                {
                    if (length > 0)
                    {
                        rc = selection_sort(array, &array[length]);
                        array_print(array, length);
                    }
                    else
                    {
                        rc = WRONG_DATA;
                    }
                    free_array(array, length);
                }
            }
            if (argc == 3)
            {
                int length;
                rc = get_item_list(&array, file_stream, &length);
                if (rc == 0)
                {
                    if (length > 0)
                    {
                        custom_output(array, length, argv[2]);
                    }
                    else
                    {
                        rc = WRONG_DATA;
                    }
                }
                free_array(array, length);
            }
            fclose(file_stream);
        }
        else
        {
            rc = ERROR_IO;
        }
    }
    else
    {
        rc = WRONG_ARGUMENTS;
    }
    return rc;
}
/*
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
*/