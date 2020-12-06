//
// Created by yanag on 6/13/2020.
//

#include <stdio.h>
#include "utils.h"


int get_number_by_pos(FILE *file, int *number, size_t position)
{
    fseek(file, position * (sizeof(int)), SEEK_SET);

    int error = fread(number, sizeof(int), 1, file) != 1;

    if (error < 0)
    {
        return ERROR_IO;
    }
    return 0;
}

int put_number_by_pos(FILE *file, int number, size_t position)
{
    int error = fseek(file, position * (sizeof(int)), SEEK_SET) < 0;
    if (!error)
    {
        error = fwrite(&number, sizeof(int), 1, file) != 1;
    }
    if (error < 0)
    {
        return ERROR_IO;
    }
    return 0;
}

int get_size(FILE *file, size_t *size)
{
    if (fseek(file, 0, SEEK_END) == -1)
    {
        return ERROR_IO;
    }

    *size = ftell(file) / (sizeof(int));

    if (fseek(file, 0, SEEK_SET) == -1)
    {
        return ERROR_IO;
    }
    return 0;
}

int get_total_len(FILE *file, size_t *len)
{
    if (fseek(file, 0, SEEK_END) == -1)
    {
        return ERROR_IO;
    }
    *len = ftell(file);
    if (fseek(file, 0, SEEK_SET) == -1)
    {
        return ERROR_IO;
    }
    return 0;
}