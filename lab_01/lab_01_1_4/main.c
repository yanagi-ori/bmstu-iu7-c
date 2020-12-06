#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of apartment:\n");
    scanf("%i", &n);
    n--;
    printf("Porch number is %i \n", n / 36 + 1);
    printf("Floor number is %i \n", (n - 36 * ((n / 36 + 1) - 1)) / 4 + 1);
    return 0;
}