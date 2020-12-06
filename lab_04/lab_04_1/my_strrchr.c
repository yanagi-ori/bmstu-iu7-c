//
// Created by yanag on 6/1/2020.
//

#include "my_strrchr.h"
char *my_strrchr(char *string, int symbol)
{
    char *found = 0;
    do
    {
        if (*string == symbol)
            found = (char *) string;
    } while (*string++);
    return found;
}
