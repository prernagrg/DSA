#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertMiddle(int value, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void display()
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insertMiddle(10, 1);
    insertMiddle(20, 2);
    insertMiddle(15, 2);
    insertMiddle(5, 1);
    display();
    return 0;
}
