#include <stdio.h>

#define ERROR_INPUT -1
#define ERROR_MATRIX_INPUT -2
#define WARNING_NO_CHANGE -3

int input_check(int input_amount, int input_number)
{
    if (input_amount != 1 || input_number <= 0 || input_number > 10)
    {
        return ERROR_INPUT;
    }
    else
    {
        return 0;
    }
}

int find_line_with_max(int array[10][10], int lines, int rows)
{
    int max = array[0][0];
    int line = 0;
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
                line = i;
            }
        }
    }
    return line;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int lines, rows, temp;
    int min_line;
    int array[10][10];


    printf("Enter the number of lines in the array: \n");
    temp = scanf("%d", &lines);
    if (input_check(temp, lines) == ERROR_INPUT)
    {
        printf("Wrong number of lines");
        return ERROR_INPUT;
    }

    printf("Enter the number of rows in the array: \n");
    temp = scanf("%d", &rows);
    if (input_check(temp, rows) == ERROR_INPUT)
    {
        printf("Wrong number of rows");
        return ERROR_INPUT;
    }

    printf("Now enter array items: \n");
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            temp = scanf("%d", &array[i][j]);
            if (temp != 1)
            {
                printf("Array input error");
                return ERROR_MATRIX_INPUT;
            }
        }
    }

    printf("Source array: \n");
    for (int k = 0; k < lines; k++)
    {
        for (int i = 0; i < rows; i++)
        {
            printf("%d ", array[k][i]);
        }
        printf("\n");
    }


    min_line = find_line_with_max(array, lines, rows);
    if (min_line == 0)
    {
        printf("There is nothing to replace");
        return WARNING_NO_CHANGE;
    }

    for (int i = 0; i < rows; i++)
    {
        swap(&array[0][i], &array[min_line][i]);
    }


    printf("Output: \n");
    for (int k = 0; k < lines; k++)
    {
        for (int i = 0; i < rows; i++)
        {
            printf("%d ", array[k][i]);
        }
        printf("\n");
    }

    return 0;
}
