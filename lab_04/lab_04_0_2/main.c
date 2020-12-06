#include <stdio.h>
#include "utils.h"

#define LINE_LENGTH 257
#define WORD_LENGTH 17

#define ERROR_THE_LINE_IS_TOO_LONG -1
#define ERROR_THE_WORD_IS_TOO_LONG -2
#define WARNING_NO_RESULT -3

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

int main()
{
    char set[] = { ' ', ',', ';', ':', '-', '.', '!', '?' };
    char string[LINE_LENGTH];
    char array[256][WORD_LENGTH] = { { '\0' } };

    printf("enter the string: \n");
    int error = read_line(string, LINE_LENGTH + 1);
    if (error == -1)
    {
        printf("Error! The line you entered is too long...");
        return ERROR_THE_LINE_IS_TOO_LONG;
    }

    int i = 0, j = 0;
    int item = 0;
    int prev_is_word = 0;
    while (string[item] != '\0')
    {
        if (j == 16)
        {
            printf("The word #%d is too long...", i + 1);
            return ERROR_THE_WORD_IS_TOO_LONG;
        }
        if (included(string[item], set) == 1)
        {
            if (prev_is_word == 1)
            {
                prev_is_word = 0;
                i++;
                j = 0;
            }
        }
        else
        {
            prev_is_word = 1;
            array[i][j] = string[item];
            j++;
        }
        item++;
    }

    if (words_count(array) == 0)
    {
        printf("There is nothing to show");
        return WARNING_NO_RESULT;
    }

    int amount;

    printf("Result: \n");
    for (int k = 0; k < i + 1; k++)
    {
        if (array[k][0] != '\0')
        {
            amount = usage(array, i + 1, k);
            printf("%s %d\n", array[k], amount);
        }
    }

    return 0;
}