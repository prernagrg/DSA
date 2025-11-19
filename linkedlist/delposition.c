#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteFromPosition(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if (pos == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    deleteFromPosition(2);

    display();
    return 0;
}
