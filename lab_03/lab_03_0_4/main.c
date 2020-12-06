#include <stdio.h>
#include <stdlib.h>

#define RC_INPUT_ERROR -1
#define MATRIX_INPUT_ERROR -2
#define ABORT_OPERATION 1
#define NO_RESULT -3

int matrix_input(int rows, int columns, int matrix[][10], int sub_array[10])
{
    int temp;
    for (int i = 0; i < rows; i++)
    {
        sub_array[i] = 0;
        printf("Enter the next line: \n");
        for (int j = 0; j < columns; j++)
        {
            temp = scanf("%d", &matrix[i][j]);
            if (temp != 1)
            {
                return ABORT_OPERATION;
            }
            sub_array[i] += matrix[i][j];
        }
    }
    return 0;
}

void matrix_output(int matrix[][10], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int is_odd(int number)
{
    return abs(number % 2);
}

int matrix_process(int matrix[][10], int rows, int columns)
{
    int min, check = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (is_odd(matrix[i][j]) && (check == 0 || matrix[i][j] < min))
            {
                min = matrix[i][j];
                check = 1;
            }
        }
    }
    if (check)
    {
        return min;
    }
    return NO_RESULT;
}

int main()
{
    int matrix[10][10];
    int sub_array[10];
    int temp;
    int rows, columns;

    printf("Enter numbers of rows and columns: ");
    temp = scanf("%d %d", &rows, &columns);
    if (temp != 2 || rows > 10 || rows <= 0 || columns > 10 || columns <= 0 || columns != rows)
    {
        printf("Wrong input");
        return RC_INPUT_ERROR;
    }
    if (matrix_input(rows, columns, matrix, sub_array))
    {
        printf("Matrix input error");
        return MATRIX_INPUT_ERROR;
    }

    temp = matrix_process(matrix, rows, columns);
    if (temp == NO_RESULT)
    {
        return NO_RESULT;
    }
    printf("%d", temp);
    return 0;
}
