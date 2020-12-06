//
// Created by yanag on 5/21/2020.
//

#include <stdio.h>
#define MAX_ARR_SIZE 10
#define OK 0
#define INPUT_ERROR 1

int first_digit(int num)
{
    while (num >= 10)
        num /= 10;
    return num;
}

int balance_check(int *arr, int thenum, int col)
{
    int i;
    int start = 0;
    int end = 0;
    int cur;
    for (i = 0; i < col;i++)
    {
        cur = abs(arr[i]);
        if (cur % 10 == thenum)
            end++;
        if (first_digit(cur) == thenum)
            start++;
    }
    if (end == start && start > 0)
        return 1;
    else
        return 0;
}

int matrix_form(int (*matrix)[MAX_ARR_SIZE], int row, int col, int thenum)
{
    int i, j, k;
    int new_row = row;
    for (i = 0; i < new_row; i++)
    {
        if (balance_check(matrix[i], thenum, col))
        {
            for (k = new_row; k > i + 1; k--)
            {
                for (j = 0; j < col; j++)
                {
                    matrix[k][j] = matrix[k - 1][j];
                }
            }
            for (j = 0; j < col; j++)
            {
                matrix[i + 1][j] = 100;
            }
            new_row++;
        }
    }
    return new_row;
}

int matrix_input(int (*matrix)[MAX_ARR_SIZE], int row, int col)
{
    int i, j;
    int input_check;
    printf("Enter elements of matrix:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            input_check = scanf("%d", &matrix[i][j]);
            if (input_check != 1)
                return INPUT_ERROR;
        }
    }
    return OK;
}

void matrix_output(int (*matrix)[MAX_ARR_SIZE], int row, int col)
{
    int i, j;
    printf("Resulting matrix:\n");
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int thenum;
    int rows, columns;
    int input_check;
    int new_size;
    int matrix[2 * MAX_ARR_SIZE][MAX_ARR_SIZE];
    printf("Enter number of rows and columns: ");
    input_check = scanf("%d %d", &rows, &columns);
    if (rows > MAX_ARR_SIZE || rows <= 0 || columns > MAX_ARR_SIZE || columns <= 0 || input_check != 2)
    {
        printf("Wrong input!");
        return INPUT_ERROR;
    }
    input_check = matrix_input(matrix, rows, columns);
    if (input_check)
    {
        printf("Wrong input!");
        return INPUT_ERROR;
    }
    printf("Enter the critical number:");
    input_check = scanf("%d", &thenum);
    if (input_check != 1 || thenum < 0 || thenum > 9)
    {
        printf("Wrong input!");
        return INPUT_ERROR;
    }

    new_size = matrix_form(matrix, rows, columns, thenum);
    matrix_output(matrix, new_size, columns);
    return OK;
}