/*
 * Сортировка пузырьком
 * Тип данных - int
 * Сортировка по возрастанию
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"


int main(int argc, char **argv)
{
    int error;
    for (int i = 0; i < argc; i++)
    {
        printf("|%s|\n", argv[i]);
    }
    if (strcmp(argv[1], "c") == 0)
    {
        error = create_file(atoi(argv[2]), argv[3]);
        if (error == ERROR_IO)
        {
            printf("A error was caused while creating the file.");
            return ERROR_IO;
        }
        else if (error == 0)
        {
            printf("Ok");
            return 0;
        }
        else
        {
            printf("Unexpected error was caused");
            return ERROR_UNKNOWN;
        }
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        error = output_file(argv[2]);
        if (error == 0)
        {
            printf("Everything is ok");
            return 0;
        }
        else if (error == ERROR_IO)
        {
            printf("A error was caused while reading the file");
            return ERROR_IO;
        }
        else
        {
            printf("Unknown error");
            return ERROR_UNKNOWN;
        }
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        error = sort_file(argv[2]);
        if (error == 0)
        {
            printf("everything is ok");
            return 0;
        }
        else if (error == ERROR_IO)
        {
            printf("A error was caused while sorting the file");
            return ERROR_IO;
        }
        else
        {
            printf("Unknown error");
            return ERROR_UNKNOWN;
        }
    }
    else
    {
        printf("Unknown argument");
        return WARNING_UNKNOWN_ARGUMENT;
    }
}
