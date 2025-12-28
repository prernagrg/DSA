#include <stdio.h>
#include <stdlib.h>

struct Freq
{
    int element;
    int count;
};

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamic allocation instead of arr[n]
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Freq *freq = (struct Freq *)malloc(n * sizeof(struct Freq));
    int size = 0;

    // Count frequency
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < size; j++)
        {
            if (freq[j].element == arr[i])
            {
                freq[j].count++;
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            freq[size].element = arr[i];
            freq[size].count = 1;
            size++;
        }
    }

    // Sort by frequency (descending), then element (ascending)
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((freq[i].count < freq[j].count) ||
                ((freq[i].count == freq[j].count) &&
                 (freq[i].element > freq[j].element)))
            {
                struct Freq temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
            }
        }
    }

    // Print sorted array by frequency
    printf("Array sorted by frequency:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < freq[i].count; j++)
        {
            printf("%d ", freq[i].element);
        }
    }

    // Free allocated memory
    free(arr);
    free(freq);

    return 0;
}
