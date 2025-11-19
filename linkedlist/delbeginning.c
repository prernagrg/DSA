#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
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
    // Creating a list
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = NULL;

    display();
    deleteBeginning();
    display();
    return 0;
}
