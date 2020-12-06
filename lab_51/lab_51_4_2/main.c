#include <stdio.h>
#include "utils.h"

#define ERROR_START -11
#define ERROR_IO -12
#define ERROR_POINTER -21


int main(int argc, char **argv)
{
    int error = 0;
    double result;
    FILE *file;


    if (argc != 2)
    {
        printf("There is no arguments");
        return ERROR_START;
    }

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Invalid file ");
        return ERROR_IO;
    }

    error = process(file, &result);
    if (error == 0)
    {
        printf("Result: %lf\n", result);
    }
    else if (error == ERROR_IO)
    {
        printf("IO error.");
        return ERROR_IO;
    }
    else if (error == ERROR_POINTER)
    {
        printf("Pointer error");
        return ERROR_POINTER;
    }
    fclose(file);

    return 0;
}
