//
// Created by Ivan Bogatyrev on 11/10/2020.
//

#include <stdio.h>
#include "../inc/io.h"
#include "../inc/errors.h"

short int elements_counter(FILE *file_stream, unsigned short int *counter)
{
    int amount = 1;
    int temp;

    while (amount != EOF)
    {
        amount = fscanf(file_stream, "%d", &temp);
        if (amount == 1)
        {
            (*counter)++;
        }
        if (amount == 0)
        {
            return WRONG_DATA;
        }
    }

    if ((*counter) == 0)
    {
        return EMPTY_FILE;
    }

    fseek(file_stream, 0, 0);
    return 0;
}

short int array_filling(FILE *file_stream, int *array_pointer, const int *const array_end_pointer)
{
    int temp;
    int counter = 0;
    int read_result;

    if (array_pointer == NULL)
    {
        return ARRAY_POINTER_ERROR;
    }

    for (int *i = array_pointer; i < array_end_pointer; i++)
    {
        read_result = fscanf(file_stream, "%d", &temp);
        if (read_result == 1)
        {
            *array_pointer = temp;
            array_pointer++;
            counter++;
        }
        else
        {
            fclose(file_stream);
            return WRONG_DATA;
        }
    }

    if (counter == 0)
    {
        fclose(file_stream);
        return EMPTY_FILE;
    }

    fseek(file_stream, 0, 0);
    return 0;
}

short int create_new_file(FILE *file_stream, char *name)
{
    file_stream = fopen(name, "w");
    if (file_stream == NULL)
    {
        return ERROR_IO;
    }

    return 0;
}

short int write_new_data(FILE *file_stream, int *array_b, const int *array_e)
{
    char temp[100];
    for (int *p_int = array_b; p_int < array_e; p_int++)
    {
        snprintf(temp, sizeof(temp), "%d", *p_int);
        fprintf(file_stream, "%s ", temp);
    }
    return 0;
}


void debug_array_print(int *start, int *end)
{
    int *i = start;
    while (i < end)
    {
        printf("%d ", *i);
        i++;
    }
    printf("\n");
}