#include <stdio.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int amount, temp;
    float f_amount;
    int array[10];
    int entered = 0;
    printf("Enter the amount of input numbers:\n");
    temp = scanf("%f", &f_amount);
    amount = (int) f_amount

    if (temp != 1 || amount > 10 || amount <= 0 || fabsf(f_amount - (float) amount) > 0.0001)
    {
        printf("Input error");
        return 1;
    }

    printf("Enter numbers: \n");
    while (entered < amount)
    {
        temp = scanf("%d", &array[entered]);
        if (temp == 1)
        {
            entered++;
        }
        else
        {
            fgetc(stdin);
        }
    }

    for (int i = 1; i < amount; i++)
    {
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
        {
            swap(&array[j - 1], &array[j]);
        }
    }

    for (int i = 0; i < amount; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}