#include <stdio.h>
#include <math.h>


int sum_of_even(int array[10], int length)
{
    int sum = 0, amount = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] % 2 == 0)
        {
            sum += array[i];
            amount++;
        }
    }
    if (amount < 1)
    {
        return -1;
    }
    return sum;
}


int main()
{
    int amount, temp;
    float f_amount;
    int array[10];
    int entered = 0;
    printf("Enter the amount of input numbers:\n");
    temp = scanf("%f", &f_amount);
    amount = (int) f_amount;
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
    }
    temp = sum_of_even(array, amount);
    if (temp == -1)
    {
        printf("There is no even numbers");
        return 2;
    }
    printf("%d", temp);
    return 0;
}

