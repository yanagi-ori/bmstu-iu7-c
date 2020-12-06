#include <stdio.h>
#include <math.h>

int main(void)
{
    int h, t, m;
    scanf("%d %d %d", &h, &t, &m);
    printf("first formula: %g \n", (float) h * t / 240);
    printf("second formula: %g", (float) (m/100) / pow(h, 2));
    return 0;
}
