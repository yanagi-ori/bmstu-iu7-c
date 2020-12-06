#include <stdio.h>
#include <math.h>

double approximator(double x, int n)
{
    return pow(-1, n + 1) * (n * (n + 1) * pow(x, n - 1)) / 2;
}

double accurate_root(double x)
{
    return pow(1 + x, -3);
}

int main()
{
    double x, eps;
    double sx_next = 10, fx = 0, sum = 0;
    int i = 0;
    short temp;
    printf("Enter x and epsilon:\n");
    temp = scanf("%lg %lg", &x, &eps);
    if ((temp == 2) && (fabs(x) < 1) && (eps < 1))
    {
        while (fabs(sx_next) > eps)
        {
            sx_next = approximator(x, ++i);
            sum += sx_next;
        }
        printf("%.5lg \n", sum);
        fx = accurate_root(x);
        printf("%.5lg \n", fx);
        printf("%.5lg \n", fabs(fx - sum));
        printf("%.5lg \n", fabs((fx - sum) / fx));
    }
    else
    {
        printf("Input Error");
        return 1;
    }
}