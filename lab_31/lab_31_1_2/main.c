#include <stdio.h>

#include "errors.h"
#include "io.h"
#include "array.h"

int main(int argc, char *argv[])
{
    int code_error;

    if (argc != 2)
    {
        return WRONG_ARGUMENTS;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return IO_ERROR;
    }

    int rows, columns;

    code_error = get_matrix_size(file, &rows, &columns);
    if (code_error != 0)
    {
        fclose(file);
        return code_error;
    }
    if (rows != columns)
    {
        fclose(file);
        return MATRIX_SIZE_ERROR;
    }

    int **array = create_array(rows, columns);
    if (array == NULL)
    {
        free_matrix(array);
        fclose(file);
        return ARRAY_MEMORY_ALLOCATE_ERROR;
    }

    code_error = get_matrix(file, array, rows, columns);
    if (code_error != 0)
    {
        free_matrix(array);
        fclose(file);
        return code_error;
    }
    fclose(file);


    int number;

    code_error = find_number(array, &number, rows);
    if (code_error == NUMBER_NOT_FOUND)
    {
        free_matrix(array);
        return NUMBER_NOT_FOUND;
    }

    printf("%d\n", number);

    free_matrix(array);
    return 0;
}
