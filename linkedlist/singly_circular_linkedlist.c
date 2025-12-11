#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // Circular link
        return;
    }

    struct Node *temp = head;

    while (temp->next != head) // Reach the last node
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete from beginning
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    // Only one node
    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Node deleted from beginning.\n");
        return;
    }

    struct Node *last = head;

    while (last->next != head)
        last = last->next;

    last->next = head->next;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning.\n");
}

// Delete from end
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    // Only one node
    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    struct Node *prev = NULL;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);

    printf("Node deleted from end.\n");
}

// Display the list
void display()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Singly Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;

        case 3:
            deleteFromBeginning();
            break;

        case 4:
            deleteFromEnd();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
