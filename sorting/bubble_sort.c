#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    int temp;
    // for n passes
    for (int i = 0; i < n - 1; i++)
    {
        // to avoid sorted elements
        for (int j = 0; j < n - i - 1; j++)
        {
            // to compare with the adjacent elements and swap
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter No. of elements you want to sort\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation Failed");
        return 1;
    }

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    free(arr);
    return 0;
}