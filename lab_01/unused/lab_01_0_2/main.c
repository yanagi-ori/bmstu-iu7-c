#include <stdio.h>
#include <math.h>
int main(void)
{
    int a, b, height;

    printf("Enter the values of both sides and the height of the isosceles trapezoid:\n");
    scanf("%d %d %d", &a, &b, &height);
    printf("The trapezoid perimeter is %e \n", 2* sqrt(pow((abs(a - b) / 2), 2) + pow(height, 2)) + a + b);
    return 0;
}
