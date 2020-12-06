//
// Created by yanag on 6/2/2020.
//
#include <string.h>
#include <stdio.h>
#include "utils.h"

int place(char *target, char *source)
{
    for (int i = 0; i < strlen(source); ++i)
    {
        target[i] = source[i];
    }
    return 0;
}

int words_count(char array[][17])
{
    int counter = 0;
    int i = 0;
    while (array[i][0] != '\0')
    {
        counter++;
        i++;
    }
    return counter;
}

void chars_move(char *string, int index)
{
    while (string[index] != '\0')
    {
        string[index] = string[index + 1];
        index++;
    }
}

char *cut_chars(char *string)
{
    char first = string[0];
    int i = 1;

    while (string[i] != '\0')
    {
        if (string[i] == first)
        {
            chars_move(string, i);
        }
        i++;
    }
    return string;
}

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

int write_in_line(char *target, char *source, int start_index)
{
    for (int i = 0; i < strlen(source); i++)
    {
        target[start_index++] = source[i];
    }
    return start_index;
}

int add_space(char *target, int index)
{
    target[index] = ' ';
    return 1;
}