#include <stdio.h>

int main() {
    int num1, num2, result = 0;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    while (num2 != 0) {
        if (num2 & 1) {
            result += num1;
        }
        num1 <<= 1;
        num2 >>= 1;
    }

    printf("Product: %d\n", result);

    return 0;
}
