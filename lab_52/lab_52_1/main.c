#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "avg_grade.h"

#define INVALID_ARGS 53
#define OPERATION_FAIL 50


int main(int argc, char *argv[])
{
    int error;

    if (argc != 3)
    {
        return INVALID_ARGS;
    }
    if (strcmp(argv[1], "sb") == 0)
    {
        if (sort(argv[2]) != 0)
        {
            return OPERATION_FAIL;
        }
    }
    else if (strcmp(argv[1], "db") == 0)
    {
        if (avg_grade(argv[2]) != 0)
        {
            return OPERATION_FAIL;
        }
    }
    else
    {
        return INVALID_ARGS;
    }

    return 0;
}
