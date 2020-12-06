#include <stdio.h>

void existence_check(int *array, const int *item, int *counter)
{
    int bool = 0;
    int *end = array + *counter;
    for (int *i = array; i < end; i++)
    {
        if (*item == *i)
        {
            bool = 1;
        }
    }
    if (bool == 0)
    {
        *end = *item;
        (*counter)++;
    }
}

int main()
{
    int amount, temp = 0;
    int array[10], new_array[10];
    int *index, *end;
    int counter = 0;
    printf("Enter the amount of input numbers:\n");
    temp = scanf("%d", &amount);
    if (temp != 1 || amount > 10 || amount <= 0)
    {
        printf("Input error");
        return 1;
    }
    printf("Enter numbers: \n");
    index = array;
    end = index + amount;
    while (index < end)
    {
        temp = scanf("%d", index);
        if (temp == 1)
        {
            index++;
        }
        else
        {
            fgetc(stdin);
        }
    }

    index = array;
    for (int *i = index; i < end; i++)
    {
        existence_check(new_array, i, &counter);
    }
    printf("%d", counter);
    return 0;
}
