#include <stdio.h>

void insertion(int a[], int n)
{
    int key, j;

    if (n <= 1)
        return;

    insertion(a, n - 1);

    key = a[n - 1];
    j = n - 2;

    while (j >= 0 && a[j] > key)
    {
        a[j + 1] = a[j];
        j--;
    }

    a[j + 1] = key;
}

int main()
{
    int a[] = {5, 2, 8, 1, 3, 7};
    int n = sizeof(a) / sizeof(a[0]);

    insertion(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}