//
// Created by yanag on 6/2/2020.
//

#include "utils.h"
#include <string.h>
#include <stdio.h>


int read_line(char *s, int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < n - 1)
        {
            s[i++] = ch;
        }
    }
    s[i] = '\0';
    if (i < 257)
    {
        return i;
    }
    else
    {
        return -3;
    }
}

char *my_strtok(char *str, const char *delim)
{
    static char *last = 0;
    if (str)
    {
        last = str;
    }
    if ((last == 0) || (*last == 0))
    {
        return 0;
    }
    char *c = last;
    while (strchr(delim, *c))
    {
        ++c;
    }
    if (*c == 0)
    {
        return 0;
    }
    char *start = c;
    while (*c && (strchr(delim, *c) == 0))
    {
        ++c;
    }
    if (*c == 0)
    {
        last = c;
        return start;
    }
    *c = 0;
    last = c + 1;
    return start;
}

void my_strcpy(char *target, const char *source, int len)
{
    for (int i = 0; i < len; i++)
    {
        target[i] = source[i];
    }
}

int get_len(const char string[17])
{
    int len = 0;
    int i = 0;
    while ((string[i] != '\0') & (string[i] != '\n'))
    {
        if (i == 17)
        {
            return -1;
        }
        len++;
        i++;
    }
    return len;
}

void trim(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == '\n')
        {
            string[i] = '\0';
            return;
        }
        i++;
    }
}

int is_equal(char first[17], char second[17])
{
    int j = 0;
    while (first[j] != '\0')
    {
        if (first[j] != second[j])
        {
            return 0;
        }
        j++;
    }
    if (get_len(first) != get_len(second))
    {
        return 0;
    }
    return 1;
}
