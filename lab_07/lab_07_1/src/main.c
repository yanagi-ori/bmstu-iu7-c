#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/errors.h"
#include "../inc/io.h"
#include "../inc/array_utils.h"

// 5 3

int main(int argc, char *argv[])
{
    short int code_error;
    if (argc > 2 && argc < 5)
    {
        FILE *file = fopen(argv[1], "r");
        if (file != NULL)
        {
            unsigned short int elements_amount;
            code_error = elements_counter(file, &elements_amount);
            if (code_error == 0)
            {
                int *array_pointer = NULL;
                array_pointer = malloc(elements_amount * sizeof(int));
                if (!array_pointer)
                {
                    code_error = ARRAY_MEMORY_ALLOCATION_ERROR;
                }
                else
                {
                    int *array_end = array_pointer + elements_amount;
                    code_error = array_filling(file, array_pointer, array_end);
                    if (code_error == 0)
                    {
                        int *pb_dst = NULL, *pe_dst = NULL;
                        if (argc == 4)
                        {
                            if (strcmp(argv[3], "f") == 0)
                            {
                                code_error = key(array_pointer, array_end, &pb_dst, &pe_dst);
                                if (code_error == 0)
                                {
                                    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare);
                                    code_error = create_new_file(&file, argv[2]);
                                    if (code_error == 0)
                                    {
                                        write_new_data(file, pb_dst, pe_dst);
                                    }
                                    else
                                    {
                                        code_error = ERROR_IO;
                                    }
                                    free(pb_dst);
                                }
                            }
                            else
                            {
                                code_error = WRONG_ARGUMENTS;
                            }
                        }
                        else
                        {
                            mysort(array_pointer, array_end - array_pointer, sizeof(int), compare);
                            code_error = create_new_file(&file, argv[2]);
                            if (code_error == 0)
                            {
                                write_new_data(file, array_pointer, array_end);
                            }
                            else
                            {
                                code_error = ERROR_IO;
                            }
                        }
                        free(array_pointer);
                    }
                }
            }
            fclose(file);
        }
        else
        {
            code_error = ERROR_IO;
        }
    }
    else
    {
        code_error = WRONG_ARGUMENTS;
    }

    return code_error;
}