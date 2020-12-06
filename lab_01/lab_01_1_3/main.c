#include <stdio.h>

int main() {
    float v1, t1, v2, t2;
    printf("Enter the first water volume and it's temperature: \n");
    scanf("%f %f", &v1, &t1);
    printf("Enter the second water volume and it's temperature: \n");
    scanf("%f %f", &v2, &t2);
    printf("The total volume is %.5f and it's temperature is %.5f", v1 + v2, (v1 * t1 + v2 * t2) / (v1 + v2));
    return 0;
}
