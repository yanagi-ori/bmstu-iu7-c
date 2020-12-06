#include <stdio.h>

#define ARRAY_LEN 10
#define RC_INPUT_ERROR -1
#define MATRIX_INPUT_ERROR -2
#define ABORT_OPERATION 1
#define NO_RESULT -3


int is_prime(int n)
{
    if (n > 1)
    {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
            {
                return 0; // число не простое
            }
        return 1; // число простое
    }
    else
    {
        return 0; // число не простое
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int reverse_array(int array[], int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        swap(&array[i], &array[len - i - 1]);
    }
    return 0;
}

int matrix_input(int rows, int columns, int matrix[][ARRAY_LEN], int *sub_array, int *length)
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
            if (is_prime(matrix[i][j]))
            {
                *sub_array++ = matrix[i][j];
                (*length)++;
            }
        }
    }
    if (*length == 0)
    {
        return NO_RESULT;
    }
    return 0;
}

int matrix_process(int matrix[][10], int rows, int columns, int *sub_array, const int *array_length)
{
    int counter = 0;
    reverse_array(sub_array, *array_length);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (is_prime(matrix[i][j]))
            {
                matrix[i][j] = sub_array[counter++];
            }
        }
    }
    return 1;
}

void matrix_output(int rows, int columns, int matrix[][ARRAY_LEN])
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


int main()
{
    int matrix[ARRAY_LEN][ARRAY_LEN], rows, columns;
    int sub_array[ARRAY_LEN * ARRAY_LEN], array_length = 0;
    int temp;

    printf("Enter numbers of rows and columns: ");
    temp = scanf("%d %d", &rows, &columns);
    if (temp != 2 || rows > ARRAY_LEN || rows <= 0 || columns > ARRAY_LEN || columns <= 0)
    {
        printf("Wrong input");
        return RC_INPUT_ERROR;
    }
    temp = matrix_input(rows, columns, matrix, sub_array, &array_length);
    if (temp == ABORT_OPERATION)
    {
        printf("Matrix input error");
        return MATRIX_INPUT_ERROR;
    }
    else if (temp == NO_RESULT)
    {
        printf("There is nothing to do");
        return NO_RESULT;
    }

    matrix_process(matrix, rows, columns, sub_array, &array_length);
    matrix_output(rows, columns, matrix);
    return 0;
}
