#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a perfect binary tree
struct Node *buildPerfectTree(int depth, int *value)
{
    if (depth == 0)
        return NULL;

    struct Node *root = createNode((*value)++);

    root->left = buildPerfectTree(depth - 1, value);
    root->right = buildPerfectTree(depth - 1, value);

    return root;
}

// Inorder Traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Count total nodes
int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Main function
int main()
{
    int depth;
    int value = 1;

    printf("Enter depth of perfect binary tree: ");
    scanf("%d", &depth);

    struct Node *root = buildPerfectTree(depth, &value);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nTotal Nodes = %d\n", countNodes(root));

    return 0;
}
