#include <stdio.h>

int table[100];

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    if (table[n] != -1)
        return table[n];

    table[n] = fib(n - 1) + fib(n - 2);

    return table[n];
}

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < 100; i++)
        table[i] = -1;

    printf("%d", fib(n));

    return 0;
}