#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push
void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *temp = top;
        printf("%d popped\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Display
void display()
{
    struct Node *temp = top;
    if (temp == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    push(100);
    push(200);
    push(300);

    display();
    pop();

    return 0;
}
