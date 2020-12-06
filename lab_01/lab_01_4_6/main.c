#include <stdio.h>
#include <math.h>

void is_on_line(double x1, double y1, double x2, double y2, double xa, double ya)
{
    double length, sum_of_distances;
    length = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    sum_of_distances = sqrt(pow(x1 - xa, 2) + pow(y1 - ya, 2)) + sqrt(pow(x2 - xa, 2) + pow(y2 - ya, 2));
    if (fabs(length - sum_of_distances) < 0.0001)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}

int main()
{
    double x1, y1, x2, y2, xa, ya;
    int temp = 0;
    temp += scanf("%lg %lg", &x1, &y1);
    temp += scanf("%lg %lg", &x2, &y2);
    temp += scanf("%lg %lg", &xa, &ya);
    if (temp == 6 && !(x1 == x2 && y1 == y2))
    {
        is_on_line(x1, y1, x2, y2, xa, ya);
        return 0;
    }
    else
    {
        printf("Input Error");
        return 1;
    }
}
