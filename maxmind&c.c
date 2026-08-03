#include <stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int low, int high) {
    struct MinMax result, leftResult, rightResult;
    int mid;

    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    mid = low + (high - low) / 2;
    leftResult = findMinMax(arr, low, mid);
    rightResult = findMinMax(arr, mid + 1, high);

    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;

    return result;
}

int main() {
    int arr[] = {3, 5, 1, 9, 2, 8, -4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct MinMax res = findMinMax(arr, 0, size - 1);

    printf("Min: %d\n", res.min);
    printf("Max: %d\n", res.max);

    return 0;
}
