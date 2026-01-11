#include <stdio.h>

int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    int n = 5, pos = 3, val = 99, i;

    for (i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = val;
    n++;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
