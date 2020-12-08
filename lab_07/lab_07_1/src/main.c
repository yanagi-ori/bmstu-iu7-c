#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/errors.h"
#include "../inc/io.h"
#include "../inc/array_utils.h"

// 5 3

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        printf("Wrong arguments.\n");
        return WRONG_ARGUMENTS;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fclose(file);
        printf("IO error.\n");
        return ERROR_IO;
    }

    if (argc == 4 && strcmp(argv[3], "f") != 0)
    {
        printf("The third argument is not 'f',\n");
        return WRONG_FILTER_FLAG;
    }

    unsigned short int elements_amount = 0;
    short int code_error;
    int *array_pointer = NULL;

    code_error = elements_counter(file, &elements_amount);
    if (code_error == EMPTY_FILE)
    {
        printf("The source file is empty.\n");
        return EMPTY_FILE;
    }
    if (code_error == WRONG_DATA)
    {
        printf("Wrong data in the file. (From elements counter)\n");
        return WRONG_DATA;
    }

    array_pointer = malloc(elements_amount * sizeof(int));
    if (array_pointer == NULL)
    {
        fclose(file);
        printf("An error occurred while allocating dynamic memory.\n");
        return ARRAY_MEMORY_ALLOCATION_ERROR;
    }

    int *array_end = array_pointer + elements_amount;
    code_error = array_filling(file, array_pointer, array_end);
    if (fclose(file) != 0)
    {
        printf("IO error occurred while closing file.\n");
        return ERROR_IO;
    }
    if (code_error == WRONG_DATA)
    {
        printf("Wrong data in the file. (From array filling)");
        return WRONG_DATA;
    }
    if (code_error == ARRAY_POINTER_ERROR)
    {
        printf("An error occurred while accessing the array pointer.\n");
        return ARRAY_POINTER_ERROR;
    }
    if (code_error == ARRAY_OVERFLOW)
    {
        printf("The array was overflowed while reading data from the file.\n");
        return ARRAY_OVERFLOW;
    }
    if (code_error == EMPTY_FILE)
    {
        printf("The source file is empty");
        return EMPTY_FILE;
    }
    if (code_error == ARRAY_FILLING_WARNING)
    {
        printf("WARNING: the program got less data than array can accommodate.\n");
        return ARRAY_FILLING_WARNING;
    }

    int *pb_dst = NULL, *pe_dst = NULL;
    int is_filtered = 0;
    if (argc == 4 && strcmp(argv[3], "f") == 0)
    {
        code_error = key(array_pointer, array_end, &pb_dst, &pe_dst);
        if (code_error == ARRAY_MEMORY_ALLOCATION_ERROR)
        {
            printf("An error occurred while creating filtered array.\n");
        }
        is_filtered = 1;
    }
    else
    {
        pb_dst = array_pointer, pe_dst = array_end;
    }

    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare);

    code_error = create_new_file(&file, argv[2]);
    if (code_error == ERROR_IO)
    {
        fclose(file);
        printf("IO error occurred wile creating output file.\n");
        return ERROR_IO;
    }

    write_new_data(file, pb_dst, pe_dst);

    code_error = fclose(file);
    if (code_error != 0)
    {
        printf("IO error occurred while closing file.\n");
        return ERROR_IO;
    }

    free_memory(array_pointer);
    if (is_filtered == 1)
    {
        free_memory(pb_dst);
    }
    return 0;
}

