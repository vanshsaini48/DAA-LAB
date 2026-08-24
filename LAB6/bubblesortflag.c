#include <stdio.h>

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int temp[r - l + 1];

    while (i <= m && j <= r)
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void bubbleSort(int a[], int n)
{
    int i, j, flag;

    for (i = 0; i < n - 1; i++)
    {
        flag = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                flag = 1;
            }
        }

        if (!flag)
            break;
    }
}

void divide(int a[], int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;

    divide(a, l, m);
    divide(a, m + 1, r);

    bubbleSort(a + l, r - l + 1);
}

int main()
{
    int a[] = {5, 2, 8, 1, 3, 7};
    int n = sizeof(a) / sizeof(a[0]);

    divide(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}