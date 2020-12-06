#include <stdio.h>
#include <stdlib.h>

#define ERROR_WRONG_NUMBER_OF_ROWS_COLUMNS -1
#define ERROR_MATRIX_INPUT -3
#define ERROR_WRONG_NUMBER -4


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
                return ERROR_MATRIX_INPUT;
            }
        }
    }
    return 0;
}

// функция возврщает первую цифру числа
int get_first_digit(int number)
{
    while (number >= 10)
        number /= 10;
    return number;
}

// функиция считает, выполняется ли заданное условие
int row_check(int columns, int *row, int number)
{
    int start_with = 0, end_with = 0; // сколько числел, начинающихся с цифры, и сколько - заканчивается
    int *end_index = row + columns; // адрес последнего элемента строки
    int first_check, last_check;
    for (int *item = row; item < end_index; item++)
    {
        first_check = get_first_digit(abs(*item));
        last_check = (abs(*item)) % 10;
        if (first_check == number)
        {
            start_with++;
        }
        if (last_check == number)
        {
            end_with++;
        }
    }
    if (start_with == end_with && start_with > 0)
    {
        return 0; // условие выполняется
    }
    else
    {
        return 1; // условие не выполняется
    }
}

void matrix_output(int rows, int columns, int matrix[][10])
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

void free_space(int row, int rows, int columns, int matrix[][10])
{
    for (int i = rows; i > row; i--)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = matrix[i - 1][j];
        }
    }
}

void enter_new_row(int row, int columns, int matrix[][10])
{
    for (int i = 0; i < columns; i++)
    {
        matrix[row][i] = 100;
    }
}

int matrix_process(int rows, int columns, int matrix[][10], int number)
{
    for (int row = 0; row < rows; row++)
    {
        if (!row_check(columns, matrix[row], number))
        {
            rows++;
            free_space(row + 1, rows, columns, matrix);
            enter_new_row(row + 1, columns, matrix);
        }
    }
    return rows;
}


int main()
{
    int input[21][10];
    int temp, number;
    int rows, columns;

    printf("Enter number of rows and columns: ");
    temp = scanf("%d %d", &rows, &columns);
    if (rows > 10 || rows <= 0 || columns > 10 || columns <= 0 || temp != 2)
    {
        printf("Wrong input");
        return ERROR_WRONG_NUMBER_OF_ROWS_COLUMNS;
    }

    temp = matrix_input(rows, columns, input);
    if (temp != 0)
    {
        printf("Matrix input error");
        return ERROR_MATRIX_INPUT;
    }
    printf("Enter a number: ");
    temp = scanf("%d", &number);
    if (temp != 1 || number < 0 || number >= 10)
    {
        printf("Entered a wrong number");
        return ERROR_WRONG_NUMBER;
    }
    printf("\n");

    temp = matrix_process(rows, columns, input, number);

    matrix_output(temp, columns, input);

    return 0;
}
