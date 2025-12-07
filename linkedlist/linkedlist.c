// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node *next;
// };

// // Function to insert a new node after a given node
// void insertAfter(struct Node *prev_node, int newData) {
//     if (prev_node == NULL) {
//         printf("Previous node cannot be NULL.\n");
//         return;
//     }

//     // Step 1: Create a new node
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

//     // Step 2: Assign data
//     newNode->data = newData;

//     // Step 3: Link new node to the next node of prev_node
//     newNode->next = prev_node->next;

//     // Step 4: Link prev_node to newNode
//     prev_node->next = newNode;
// }

// // Function to print linked list
// void printList(struct Node *n) {
//     while (n != NULL) {
//         printf("%d -> ", n->data);
//         n = n->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     // Creating nodes
//     struct Node *head = (struct Node *)malloc(sizeof(struct Node));
//     struct Node *second = (struct Node *)malloc(sizeof(struct Node));
//     struct Node *third = (struct Node *)malloc(sizeof(struct Node));

//     // Assigning data
//     head->data = 10;
//     head->next = second;

//     second->data = 20;
//     second->next = third;

//     third->data = 30;
//     third->next = NULL;

//     printf("Original Linked List:\n");
//     printList(head);

//     // Insert 25 after the second node
//     insertAfter(second, 25);

//     printf("\nAfter inserting 25 in between:\n");
//     printList(head);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

// definition of node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to insert node at the end of the linked list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    // If list is empty
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Traverse to last node
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display linked list
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
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
    struct Node *head = NULL;
    int n, value;

    printf("How many elements do you want to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    displayList(head);

    return 0;
}
