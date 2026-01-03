#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

/* Initialize hash table */
void init()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1; // -1 indicates empty slot
    }
}

/* Insert key using Linear Probing */
void insert(int key)
{
    int index = key % SIZE;

    // Linear probing in case of collision
    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
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
    int keys[] = {23, 43, 13, 27};
    int n = 4, i;

    init();

    for (i = 0; i < n; i++)
    {
        insert(keys[i]);
    }

    display();

    return 0;
}
