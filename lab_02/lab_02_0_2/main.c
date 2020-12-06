#include <stdio.h>
#include <math.h>


double arithmetical_mean(int array[10], int amount)
{
    int sum = 0;
    for (int i = 0; i < amount; i++)
    {
        sum += array[i];
    }
    return (double) sum / amount;
}


int main()
{
    int amount, temp;
    float f_amount;
    int array[10], new_array[10];
    int entered = 0;
    double average;
    printf("Enter the amount of input numbers:\n");
    temp = scanf("%f", &f_amount);
    amount = (int)f_amount;

    if (temp != 1 || amount > 10 || amount <= 0 || fabsf(f_amount - (float)amount) > 0.0001)
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
    average = arithmetical_mean(array, amount);

    temp = 0;
    for (int i = 0; i < amount; i++)
    {
        if (array[i] > average)
        {
            new_array[temp] = array[i];
            temp++;
        }
    }
    if (temp == 0)
    {
        printf("There is no items");
        return 2;
    }
    for (int i = 0; i < temp; i++)
    {
        printf("%d ", new_array[i]);
    }
    return 0;
}
