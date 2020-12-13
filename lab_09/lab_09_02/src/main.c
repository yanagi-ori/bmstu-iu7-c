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
            int length;
            rc = get_item_list(&array, file_stream, &length);
            if (rc == 0)
            {
                if (length > 0)
                {
                    if (argc == 2)
                    {
                        rc = selection_sort(array, &array[length]);
                        if (rc == 0)
                        {
                            array_print(array, length);
                        }
                    }
                    if (argc == 3)
                    {
                        custom_output(array, length, argv[2]);
                    }
                }
                else
                {
                    rc = WRONG_DATA;
                }
                fclose(file_stream);
                free_array(array, length);
            }
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
