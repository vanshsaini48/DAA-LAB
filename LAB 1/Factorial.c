//WAP of factorial of a number using recursion and without recursion

//Using Recursion
#include <stdio.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial is not defined for negative numbers.");
    else
        printf("Factorial of %d = %d\n", n, factorial(n));

    return 0;
}

//Without Recursion

#include <stdio.h>

int main()
{
    int n, i;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Factorial is not defined for negative numbers.");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            fact = fact * i;
        }

        printf("Factorial of %d = %lld\n", n, fact);
    }

    return 0;
}