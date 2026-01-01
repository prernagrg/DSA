#include <stdio.h>
#include <stdlib.h>

// Function to check if pairs can be formed
int canPairs(int *arr, int n, int k)
{

    // If number of elements is odd, pairing not possible
    if (n % 2 == 1)
        return 0;

    int count = 0;

    // Visited array (dynamically allocated)
    int *vis = (int *)malloc(n * sizeof(int));

    // Initialize visited array with -1
    for (int i = 0; i < n; i++)
    {
        vis[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            // Check divisibility and visited status
            if ((arr[i] + arr[j]) % k == 0 &&
                vis[i] == -1 && vis[j] == -1)
            {

                count++;
                vis[i] = 1;
                vis[j] = 1;
                break; // move to next i once paired
            }
        }
    }

    free(vis);

    return (count == n / 2);
}

// Driver code
int main()
{
    int n = 6;
    int k = 10;

    // Dynamically allocate array
    int *arr = (int *)malloc(n * sizeof(int));

    // Initialize values
    arr[0] = 92;
    arr[1] = 75;
    arr[2] = 65;
    arr[3] = 48;
    arr[4] = 45;
    arr[5] = 35;

    if (canPairs(arr, n, k))
        printf("True\n");
    else
        printf("False\n");

    free(arr);
    return 0;
}
