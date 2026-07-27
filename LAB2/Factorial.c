// Factorial of a number using recursion and call by reference 

#include <stdio.h>

void factorial(int n, long long *result) {
    if (n <= 1) {
        *result = 1;
        return;
    }
    long long temp = 1;
    factorial(n - 1, &temp);
    *result = n * temp;
}

int main() {
    int num;
    long long fact = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        factorial(num, &fact);
        printf("Factorial of %d is %lld\n", num, fact);
    }

    return 0;
}