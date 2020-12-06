#include <stdio.h>

# define ERROR_INPUT -1
# define ERROR_ARRAY_INPUT -2
# define WARNING_NO_NEGATIVE_ITEMS -3
# define WARNING_FIRST_OR_LAST_INDEX -4

int input_check(int input_amount, int input_number)
{
    if (input_amount != 1 || input_number <= 0 || input_number > 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int find_first_negative(const int *array, int length)
{
    int index = -1;
    for (int i = 0; i < length; i++)
    {
        if (array[i] < 0)
        {
            return i;
        }
    }
    return index;
}

int main()
{
    int length, temp, array_length;
    int negative_index;
    int array[10];


    printf("Enter the number of items in the array: \n");
    temp = scanf("%d", &length);
    if (input_check(temp, length) == 1)
    {
        printf("Wrong input for array's length.");
        return ERROR_INPUT;
    }

    array_length = length;
    printf("Now enter array items: \n");
    for (int *i = array; i < array + length; i++)
    {
        temp = scanf("%d", i);
        if (temp != 1)
        {
            printf("Array input error.");
            return ERROR_ARRAY_INPUT;
        }
    }

    printf("Source array: \n");
    for (int i = 0; i < array_length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");


    negative_index = find_first_negative(array, length);
    if (negative_index == WARNING_NO_NEGATIVE_ITEMS)
    {
        printf("There is no negative items.");
        return WARNING_NO_NEGATIVE_ITEMS;
    }
    else if (negative_index == 0 || negative_index == (length - 1))
    {
        printf("A negative number has the first or last index.");
        return WARNING_FIRST_OR_LAST_INDEX;
    }


    for (int i = negative_index - 1; i < array_length - 3; i++)
    {
        array[i] = array[i + 3];
    }


    printf("Output: \n");
    if ((array_length - 3) == 0)
    {
        printf("The array is empty now.");
    }

    for (int i = 0; i < array_length - 3; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
