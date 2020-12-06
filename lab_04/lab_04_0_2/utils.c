//
// Created by yanag on 6/2/2020.
//

#include <stdio.h>
#include "utils.h"

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
        return -1;
    }
}

int included(char ch, const char set[8])
{
    for (int i = 0; i < 8; i++)
    {
        if (ch == set[i])
        {
            return 1;
        }
    }
    return 0;
}

int get_len(const char string[17])
{
    int len = 0;
    int i = 0;
    while (string[i] != '\0')
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

int usage(char array[][17], int length, int word_index)
{
    int amount = 1;
    for (int i = 0; i < length; i++)
    {
        if (i != word_index)
        {
            int equals = is_equal(array[i], array[word_index]);
            if (equals == 1)
            {
                array[i][0] = '\0';
            }
            amount += equals;
        }
    }
    return amount;
}

