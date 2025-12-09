#include <stdio.h>

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
};

int main()
{
    int target;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // input for target element
    printf("Enter the target element\n");
    scanf("%d", &target);

    int ans = linearSearch(arr, n, target);

    if (ans == -1)
    {

        printf("not found");
    }
    else
    {
        printf(" found at index %d", ans);
    }
    return 0;
}