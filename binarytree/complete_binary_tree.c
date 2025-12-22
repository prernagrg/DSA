#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node
{
    int data;
    struct Node *left, *right;
};

// Queue structure for Level Order Traversal
struct Queue
{
    struct Node *arr[MAX];
    int front, rear;
};

// Create new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Create Queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

// Enqueue
void enqueue(struct Queue *q, struct Node *node)
{
    q->arr[q->rear++] = node;
}

// Dequeue
struct Node *dequeue(struct Queue *q)
{
    return q->arr[q->front++];
}

// Insert into Complete Binary Tree
void insert(struct Node **root, int value)
{
    struct Node *newNode = createNode(value);

    if (*root == NULL)
    {
        *root = newNode;
        return;
    }

    struct Queue *q = createQueue();
    enqueue(q, *root);

    while (q->front < q->rear)
    {
        struct Node *temp = dequeue(q);

        if (temp->left == NULL)
        {
            temp->left = newNode;
            return;
        }
        else
        {
            enqueue(q, temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = newNode;
            return;
        }
        else
        {
            enqueue(q, temp->right);
        }
    }
}

// Preorder Traversal (Root → Left → Right)
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal (Left → Root → Right)
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder Traversal (Left → Right → Root)
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Level Order Traversal (BFS)
void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Queue *q = createQueue();
    enqueue(q, root);

    while (q->front < q->rear)
    {
        struct Node *temp = dequeue(q);
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(q, temp->left);

        if (temp->right != NULL)
            enqueue(q, temp->right);
    }
}

// Main function
int main()
{
    struct Node *root = NULL;

    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 6);

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
