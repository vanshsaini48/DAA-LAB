//maxmin of array without divide and conquer
#include <stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int size) {
    struct MinMax result;
    if (size <= 0) {
        result.min = 0;
        result.max = 0;
        return result;
    }

    result.min = arr[0];
    result.max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < result.min) {
            result.min = arr[i];
        } else if (arr[i] > result.max) {
            result.max = arr[i];
        }
    }

    return result;
}

int main() {
    int arr[] = {3, 5, 1, 9, 2, 8, -4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct MinMax res = findMinMax(arr, size);

    printf("Min: %d\n", res.min);
    printf("Max: %d\n", res.max);

    return 0;
}