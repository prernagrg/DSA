#include <stdio.h>

int main()
{
    int n, i;
    int freq[101] = {0};
    int arr[100];
    int max = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Sorted array:\n");
    for (i = 1; i <= max; i++)
    {
        while (freq[i] > 0)
        {
            printf("%d ", i);
            freq[i]--;
        }
    }

    return 0;
}
