#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

/* Initialize hash table */
void init()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1; // -1 means empty
    }
}

/* Insert using Quadratic Probing */
void insert(int key)
{
    int index = key % SIZE;
    int i = 0;

    while (hashTable[(index + i * i) % SIZE] != -1)
    {
        i++;
    }

    hashTable[(index + i * i) % SIZE] = key;
}

/* Display hash table */
void display()
{
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : Empty\n", i);
    }
}

int main()
{
    int keys[] = {23, 43, 13};
    int n = 3, i;

    init();

    for (i = 0; i < n; i++)
    {
        insert(keys[i]);
    }

    display();

    return 0;
}
