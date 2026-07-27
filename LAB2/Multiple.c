// Multiple of two numbers using repeated addition (use recursion)

#include <stdio.h>

int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b < 0) {
        return -multiply(a, -b);
    }
    return a + multiply(a, b - 1);
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Product of %d and %d is %d\n", num1, num2, multiply(num1, num2));

    return 0;
}