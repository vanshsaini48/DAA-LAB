#include <stdio.h>

void selectionSort(int a[], int n, int i) {

    if (i == n - 1)
        return;

    int min = i;

    for (int j = i + 1; j < n; j++)
        if (a[j] < a[min])
            min = j;

    int temp = a[i];
    a[i] = a[min];
    a[min] = temp;

    selectionSort(a, n, i + 1);
}

int main() {

    int a[] = {64, 25, 12, 22, 11};
    int n = 5;

    selectionSort(a, n, 0);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}