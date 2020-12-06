#include <stdio.h>

#define ARRAY_LEN 10
#define RC_INPUT_ERROR -1
#define MATRIX_INPUT_ERROR -2
#define ABORT_OPERATION 1

int matrix_input(int rows, int columns, int matrix[][ARRAY_LEN], int sub_array[ARRAY_LEN])
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void matrix_process(int matrix[][ARRAY_LEN], int rows, int columns, int sub_array[ARRAY_LEN])
{
    int least_sum, index_to_change;
    for (int i = 0; i < rows; i++)
    {
        least_sum = sub_array[i];
        index_to_change = -1;
        for (int j = i + 1; j < rows; j++)
        {
            if (sub_array[j] < least_sum)
            {
                index_to_change = j;
                least_sum = sub_array[index_to_change];
            }
        }
        if (index_to_change != -1)
        {
            swap(&sub_array[i], &sub_array[index_to_change]);
            for (int j = 0; j < columns; j++)
            {
                swap(&matrix[i][j], &matrix[index_to_change][j]);
            }
        }
    }
}

int main()
{
    int matrix[ARRAY_LEN][ARRAY_LEN], rows, columns;
    int sub_array[ARRAY_LEN];
    int temp;

    printf("Enter numbers of rows and columns: ");
    temp = scanf("%d %d", &rows, &columns);
    if (temp != 2 || rows > ARRAY_LEN || rows <= 0 || columns > ARRAY_LEN || columns <= 0)
    {
        printf("Wrong input");
        return RC_INPUT_ERROR;
    }
    if (matrix_input(rows, columns, matrix, sub_array))
    {
        printf("Matrix input error");
        return MATRIX_INPUT_ERROR;
    }

    matrix_process(matrix, rows, columns, sub_array);
    matrix_output(rows, columns, matrix);
    return 0;
}
