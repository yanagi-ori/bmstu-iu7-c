//
// Created by Ivan Bogatyrev on 1/9/2021.
//

#include <stdlib.h>
#include <string.h>
#include "../inc/utils.h"

char *my_strdup(char *source)
{
    char *temp = malloc((strlen(source) + 1) * sizeof(char));

    if (temp)
    {
        strcpy(temp, source);
        return temp;
    }
    else
    {
        return NULL;
    }
}