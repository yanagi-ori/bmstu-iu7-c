//
// Created by yanag on 6/15/2020.
//

#include <stdio.h>
#include "utils.h"

#define IO_ERROR -21

struct student
{
    char last_name[26];
    char first_name[11];
    unsigned long int grades[4];
};

int get_struct(FILE *file, struct student *student_struct, size_t pos)
{
    int error;
    error = fseek(file, pos * sizeof(*student_struct), SEEK_SET);
    if (!error)
    {
        return IO_ERROR;
    }
    error = fw
    return 0;
}