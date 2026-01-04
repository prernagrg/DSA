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

/* Primary hash function */
int hash1(int key)
{
    return key % SIZE;
}

/* Secondary hash function */
int hash2(int key)
{
    return 1 + (key % (SIZE - 1));
}

/* Insert using Double Hashing */
void insert(int key)
{
    int index1 = hash1(key);
    int index2 = hash2(key);
    int i = 0;
    int index;

    while (i < SIZE)
    {
        index = (index1 + i * index2) % SIZE;

        if (hashTable[index] == -1)
        {
            hashTable[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table is full. Cannot insert %d\n", key);
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
