#include <stdio.h>

void decomposition(int n, int div)
{
    if (n > 1)
    {
        while (n % div == 0)
        {
            printf("%i ", div);
            n = n / div;
        }
        decomposition(n, ++div);
    }
}

int main()
{
    int n, temp;
    printf("Input any number: \n");
    temp = scanf("%d", &n);
    if (temp == 1 && n > 0)
    {
        decomposition(n, 2);
    }
    else
    {
        printf("Input Error");
        return 1;
    }
    return 0;
}
