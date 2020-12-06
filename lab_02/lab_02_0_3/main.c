#include <stdio.h>


int reverse(int source)
{
    int reversed = 0;
    while (source > 0)
    {
        reversed *= 10;
        reversed += source % 10;
        source /= 10;
    }
    return reversed;
}


int main()
{
    int amount, temp;
    float f_amount;
    int array[10], new_array[10];
    int entered = 0;
    printf("Enter the amount of input numbers:\n");
    temp = scanf("%f", &f_amount);
    amount = (int)f_amount;
    
    if (temp != 1 || amount > 10 || amount <= 0 || fabsf(f_amount-(float)amount) > 0.0001)
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
            while (scanf("%d", &array[entered]) != 1)
            {
                scanf("%*s");
            }
        }
    }

    temp = 0;
    for (int i = 0; i < amount; i++)
    {
        if ((array[i] != reverse(array[i])))
        {
            new_array[temp] = array[i];
            temp++;
        }
    }

    if (temp == 0)
    {
        return 2;
    }

    for (int i = 0; i < temp; i++)
    {
        printf("%d ", new_array[i]);
    }
    return 0;
}
