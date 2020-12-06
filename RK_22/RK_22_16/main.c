#include <stdio.h>
#include <string.h>
#include "utils.h"

#define MAX_LENGTH_OF_LINE 256
#define MAX_LINES 16
#define MAX_WORD_LENGTH 16

#define ERROR_INCORRECT_INPUT -1
#define ERROR_NUMBER_OF_LINE_IS_EXCEEDED -2
#define ERROR_FILE_NAME -3
#define ERROR_IO -4


int main()
{
    int n;
    int temp;
    char set[] = { ' ', ',', ';', ':', '-', '.', '!', '?' };
    char filename[MAX_LENGTH_OF_LINE];
    char last_word[MAX_WORD_LENGTH] = { '\0' };
    char string[MAX_WORD_LENGTH * MAX_LINES * MAX_LENGTH_OF_LINE][17] = { { '\0' } };
    char temp_line[MAX_LENGTH_OF_LINE];
    char *pword;

    printf("Please, enter the number of lines (n <= 16): \n");
    temp = scanf("%d \n", &n);
    if (temp != 1)
    {
        printf("Input error");
        return ERROR_INCORRECT_INPUT;
    }
    else if (n > 16 || n <= 0)
    {
        printf("Wrong number of lines.");
        return ERROR_NUMBER_OF_LINE_IS_EXCEEDED;
    }

    if (read_line(filename, MAX_LENGTH_OF_LINE) == ERROR_FILE_NAME)
    {
        printf("Wrong file name");
        return ERROR_FILE_NAME;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not exists");
        return ERROR_IO;
    }
    int words = 0;

    int i = 0;
    while ((i < n) & !feof(file))
    {
        fgets(temp_line, 257, file);

        pword = my_strtok(temp_line, set);

        while (pword != NULL)
        {
            trim(pword);
            my_strcpy(string[words], pword, (int) strlen(pword));
            pword = my_strtok(NULL, set);
            words++;
        }
        i++;
    }
    my_strcpy(last_word, string[words - 1], strlen(string[words - 1]));

    i = 0;
    while (string[i][0] != '\0')
    {
        if (!is_equal(string[i], last_word))
        {
            for (int j = 0; j < strlen(string[i]); j++)
            {
                printf("%c", string[i][j]);
            }
            printf("\n");

        }
        i++;
    }
    return 0;
}
