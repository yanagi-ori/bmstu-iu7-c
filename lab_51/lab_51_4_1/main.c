#include <stdio.h>
#include "utils.h"

#define ERROR_POINTER -11
#define ERROR_IO -12

int main()
{
    int amount = 0;
    int temp;

    printf("Enter numbers: \n");
    temp = process(stdin, &amount);
    if (temp == 1)
    {
        printf("Result: %d\n", amount);
    }
    else if (temp == ERROR_POINTER)
    {
        printf("Pointer Error.");
        return ERROR_POINTER;
    }
    else
    {
        printf("IO Error.");
        return ERROR_IO;
    }

    return 0;
}
