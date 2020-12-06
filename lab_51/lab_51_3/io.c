//
// Created by yanag on 6/13/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "utils.h"
#include <time.h>


int create_file(int number, char *name)
{
    srand(time(NULL));
    FILE *file = fopen(name, "wb");
    int random_number;
    if (file == NULL)
    {
        printf("File is not found");
        return ERROR_POINTER_ERROR;
    }
    int error;
    for (int i = 0; i < number; i++)
    {
        random_number = -100 + rand() % 200;
        printf("%d ", random_number);
        error = fwrite(&random_number, sizeof(int), 1, file);
        if (error < 0)
        {
            printf("E2\n");
            return ERROR_IO;
        }
    }
    fclose(file);
    return 0;
}

int output_file(char *name)
{
    FILE *file = fopen(name, "rb");
    if (file == NULL)
    {
        printf("File is not found");
        return ERROR_IO;
    }

    size_t size;
    if (get_size(file, &size) == ERROR_IO)
    {
        return ERROR_IO;
    }

    size_t len;
    if (get_total_len(file, &len) == ERROR_IO)
    {
        return ERROR_IO;
    }

    if (size <= 0 || len % sizeof(int))
    {
        return ERROR_IO;
    }

    int number;
    for (size_t i = 0; i < size; i++)
    {
        if (get_number_by_pos(file, &number, i) == ERROR_IO)
        {
            return ERROR_IO;
        }
        printf("%d ", number);
    }
    printf("\n");
    fclose(file);
    return 0;
}

int sort_file(char *name)
{
    FILE *file = fopen(name, "r+b");
    if (file == NULL)
    {
        printf("File is not found\n");
        return ERROR_POINTER_ERROR;
    }

    size_t size;
    if (get_size(file, &size) == ERROR_IO)
    {
        return ERROR_IO;
    }

    size_t len;
    if (get_total_len(file, &len) == ERROR_IO)
    {
        return ERROR_IO;
    }

    if (size <= 0 || len % sizeof(int))
    {
        return ERROR_IO;
    }


    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = (size - 1); j > i; j--)
        {
            int a, b;
            if (get_number_by_pos(file, &a, j - 1) == ERROR_IO)
            {
                return ERROR_IO;
            }

            if (get_number_by_pos(file, &b, j))
            {
                return ERROR_IO;
            }

            if (a > b)
            {
                if (put_number_by_pos(file, b, j - 1))
                {
                    return ERROR_IO;
                }
                if (put_number_by_pos(file, a, j))
                {
                    return ERROR_IO;
                }
            }
        }
    }
    fclose(file);
    return 0;
}