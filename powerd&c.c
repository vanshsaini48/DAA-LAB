#include <stdio.h>

long long power(int base, int exp) {

    // Base case
    if (exp == 0)
        return 1;

    // Divide
    long long half = power(base, exp / 2);

    // Conquer
    if (exp % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exp);

    printf("%d^%d = %lld\n", base, exp, power(base, exp));

    return 0;
}