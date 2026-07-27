//WAP of linear search usinhg recursion and without recursion

//Without recursion
#include <stdio.h>

int main()
{
    int arr[100], n, key, i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at position %d", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}

//With recursion

#include <stdio.h>

int linearSearch(int arr[], int n, int key, int index)
{
    if (index >= n)
        return -1;

    if (arr[index] == key)
        return index;

    return linearSearch(arr, n, key, index + 1);
}

int main()
{
    int arr[100], n, key, result, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key, 0);

    if(result == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", result + 1);

    return 0;
}

