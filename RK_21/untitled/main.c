#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ARR_SIZE 10
#define OK 0
#define INPUT_ERROR 1
#define NO_FITTING_NUMBERS 2

int prime_check(int n)
{
    if (n > 1)
    {
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

void array_reverse(int *arr, int size)
{
    int i;
    int temp;
    for (i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int matrix_input(int (*matrix)[MAX_ARR_SIZE], int row, int columns, int *arr, int *count)
{
    int check_input;
    int i, j;
    printf("Enter elements of matrix:\n");
    for (i = 0; i < row; i++)
        for (j = 0; j < columns; j++)
        {
            check_input = scanf("%d", &matrix[i][j]);
            if (check_input != 1)
                return INPUT_ERROR;
            if (prime_check(matrix[i][j]))
            {
                arr[*count] = matrix[i][j];
                *count += 1;
            }
        }
    if (*count == 0)
        return NO_FITTING_NUMBERS;
    return OK;
}

void matrix_form(int (*matrix)[MAX_ARR_SIZE], int row, int columns, int *arr, int *size)
{
    int count = 0;
    int i, j;
    array_reverse(arr, *size);
    for (i = 0; i < row; ++i)
        for (j = 0; j < columns; ++j)
            if (prime_check(matrix[i][j]))
            {
                matrix[i][j] = arr[count];
                count++;
            }
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

void arr_output(int *begin, int *end)
{
    printf("Resulting array:\n");
    while (begin < end)
    {
        printf("%d ", *(begin++));
    }
    printf("\n");
}

int main()
{
    int rows, columns;
    int rc;
    int check_input;
    int matrix[MAX_ARR_SIZE][MAX_ARR_SIZE] = { { 0 } };
    int array[MAX_ARR_SIZE] = { 0 };
    int arrsize = 0;
    printf("Enter numbers of rows and columns: ");
    rc = scanf("%d %d", &rows, &columns);
    if (rc != 2 || rows > MAX_ARR_SIZE || rows <= 0 || columns > MAX_ARR_SIZE || columns <= 0)
    {
        printf("Wrong input!");
        return INPUT_ERROR;
    }
    check_input = matrix_input(matrix, rows, columns, array, &arrsize);
    if (check_input == NO_FITTING_NUMBERS)
    {
        printf("No fitting numbers!");
        return NO_FITTING_NUMBERS;
    }
    if (check_input == INPUT_ERROR)
    {
        printf("Wrong input!");
        return INPUT_ERROR;
    }
    matrix_form(matrix, rows, columns, array, &arrsize);
    matrix_output(matrix, rows, columns);
    return OK;
}