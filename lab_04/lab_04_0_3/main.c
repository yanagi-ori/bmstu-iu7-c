#include <stdio.h>
#include <string.h>
#include "utils.h"

#define LINE_LENGTH 257
#define WORD_LENGTH 17

#define ERROR_THE_LINE_IS_TOO_LONG -1
#define ERROR_THE_WORD_IS_TOO_LONG -2
#define WARNING_NO_RESULT -3


void chars_move1(char *string, int index)
{
    while (string[index] != '\0')
    {
        string[index] = string[index + 1];
        index++;
    }
}

char *cut_chars1(char *string)
{
    char first = string[0];
    int i = 1;

    while (string[i] != '\0')
    {
        if (string[i] == first)
        {
            chars_move1(string, i);
        }
        else
        {
            i++;
        }
    }
    return string;
}


int main()
{
    char set[] = { ' ', ',', ';', ':', '-', '.', '!', '?' };
    char string[LINE_LENGTH];
    char array[LINE_LENGTH - 1][WORD_LENGTH] = { { '\0' } };

    int error = read_line(string, LINE_LENGTH + 1);
    if (error == -1)
    {
        printf("Input error");
        return ERROR_THE_LINE_IS_TOO_LONG;
    }

    char *pword = strtok(string, set);
    if (pword != NULL)
    {
        if (strlen(pword) > 16)
        {
            return ERROR_THE_WORD_IS_TOO_LONG;
        }
    }

    int index = 0;
    while (pword != NULL)
    {
        if (strlen(pword) > 16)
        {
            return ERROR_THE_WORD_IS_TOO_LONG;
        }
        place(array[index++], pword);
        pword = strtok(NULL, set);
    }

    if (words_count(array) == 0)
    {
        return WARNING_NO_RESULT;
    }

    for (int j = 0; j < LINE_LENGTH; j++)
    {
        string[j] = '\0';
    }

    int new_index = 0;

    for (int i = index - 2; i >= 0; i--)
    {
        if (strcmp(array[i], array[index - 1]) != 0)
        {
            cut_chars1(array[i]);
            new_index = write_in_line(string, array[i], new_index);
            if (i != 0)
            {
                new_index += add_space(string, new_index);
            }
        }
    }

    if (new_index != 0)
    {
        printf("Result: %s\n", string);
    }

    return 0;
}
