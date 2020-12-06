#include <stdio.h>

#define ERROR_INPUT_MATRIX -3
#define INPUT_ERROR -1


int matrix_input(int rows, int columns, int matrix[][10])
{
    int temp;
    for (int i = 0; i < rows; i++)
    {
        printf("Enter the next line: \n");
        for (int j = 0; j < columns; j++)
        {
            temp = scanf("%d", &matrix[i][j]);
            if (temp != 1)
            {
                return ERROR_INPUT_MATRIX;
            }
        }
    }
    return 0;
}

int row_search(int rows, int column, int matrix[][10])
{
    if (rows == 1)
    {
        return 0;
    }
    else
    {
        for (int i = 1; i < rows; i++)
        {
            int prev = matrix[i - 1][column];
            int next = matrix[i][column];
            if (next >= prev)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    int input[10][10];
    int output[10];
    int rows, columns, temp;

    printf("Enter number of rows and columns: ");
    temp = scanf("%d %d", &rows, &columns);
    if (rows > 10 || rows <= 0 || columns > 10 || columns <= 0 || temp != 2)
    {
        printf("Wrong input!");
        return INPUT_ERROR;
    }

    temp = matrix_input(rows, columns, input);
    if (temp != 0)
    {
        printf("The error caused by incorrect input");
        return ERROR_INPUT_MATRIX;
    }

    for (int column = 0; column < columns; column++)
    {
        output[column] = row_search(rows, column, input);
        printf("%d ", output[column]);
    }
    printf("\n");

    return 0;
}