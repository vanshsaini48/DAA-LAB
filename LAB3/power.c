#include <stdio.h>

int power(int base, int exp) {
    int result = 1;

    for (int i = 0; i < exp; i++) {
        result = result * base;
    }

    return result;
}

int main() {
    int base = 2;
    int exp = 5;

    int res = power(base, exp);

    printf("%d^%d = %d\n", base, exp, res);

    return 0;
}