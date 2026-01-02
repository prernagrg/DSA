#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Comparator function for qsort */
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/* Function to check if two arrays are equal */
bool checkEqual(int a[], int b[], int n, int m)
{
    /* If lengths are not equal, arrays are not equal */
    if (n != m)
        return false;

    /* Sort both arrays */
    qsort(a, n, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);

    /* Compare elements */
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            return false;
    }

    /* If all elements are same */
    return true;
}

int main()
{
    int a[] = {3, 5, 2, 5, 2};
    int b[] = {2, 3, 5, 5, 2};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    if (checkEqual(a, b, n, m))
        printf("true");
    else
        printf("false");

    return 0;
}
