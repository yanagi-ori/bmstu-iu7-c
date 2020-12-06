#include <stdio.h>
#include "utils.h"

#define ERROR_POINTER -11
#define ERROR_IO -12

void shift(long long *previous, long long *this, const long long *next)
{
    *previous = *this;
    *this = *next;
}

int process(FILE *stream, int *amount)
{
    if (!stream || !amount)
    {
        return ERROR_POINTER;
    }

    *amount = 0;
    int error;
    long long previous, this, next;

    error = fscanf(stream, "%lld", &this);
    if (error != 1)
    {
        return ERROR_IO;
    }

    error = fscanf(stream, "%lld", &next);
    if (error != 1)
    {
        return ERROR_IO;
    }

    shift(&previous, &this, &next);

    while (fscanf(stream, "%lld", &next) == 1)
    {
        if ((this > previous) && (this > next))
        {
            (*amount)++;
        }
        shift(&previous, &this, &next);
    }

    return error;
}
