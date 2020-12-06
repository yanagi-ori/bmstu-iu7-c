//
// Created by yanag on 6/15/2020.
//

#include <stdio.h>
#include "sort.h"
#define WRONG_FILE -1

struct student
{
    char last_name[26];
    char first_name[11];
    unsigned long int grades[4];
};

int sort(char *name)
{
    FILE *bin_file;
    bin_file = fopen(name, "r+");
    if (bin_file == NULL){
        return WRONG_FILE;
    }



    return 0;
}

