#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Global head pointer
struct Node *head = NULL;

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
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
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning\n", data);
}

// Insert at end
void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    printf("Inserted %d at end\n", data);
}

// Delete from beginning
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if (temp->next == NULL)
    {
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted %d from end\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

// Display forward
void displayForward()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List (Forward): ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display backward
void displayBackward()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Move to last node
    while (temp->next != NULL)
        temp = temp->next;

    printf("List (Backward): ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    int choice, data;

    do
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;

        case 3:
            deleteFromBeginning();
            break;

        case 4:
            deleteFromEnd();
            break;

        case 5:
            displayForward();
            break;

        case 6:
            displayBackward();
            break;

        case 7:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
