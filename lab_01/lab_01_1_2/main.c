#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795

int main() {
    double a, b, alpha;
    printf("Enter the length of the larger base of the trapezoid: \n");
    scanf("%lf", &a);
    printf("Enter the length of the smaller base of the trapezoid: \n");
    scanf("%lf", &b);
    printf("Enter the angle for the larger base in degrees: \n");
    scanf("%lf", &alpha);
    if (fabs(a) > fabs(b)) {
        printf("%.5lf \n", (a + b) * ((a - b) * sin(alpha * PI / 180) / (2 * cos(alpha * PI / 180))) / 2);
    } else {
        printf("%.5lf \n", (a + b) * ((b - a) * sin(alpha * PI / 180) / (2 * cos(alpha * PI / 180))) / 2);
    }
    return 0;
}