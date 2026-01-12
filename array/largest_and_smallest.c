#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, n, i;
    int max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Dynamic memory allocation */
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    max = min = arr[0];

    /* Finding highest and smallest elements */
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Highest element = %d\n", max);
    printf("Smallest element = %d\n", min);

    free(arr);
    return 0;
}
