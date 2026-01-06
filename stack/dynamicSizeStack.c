#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int size;

// Push
void push(int value)
{
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = value;
    }
}

// Pop
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped\n", stack[top--]);
    }
}

// Display
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter stack size: ");
    scanf("%d", &size);

    stack = (int *)malloc(size * sizeof(int));

    push(5);
    push(15);
    push(25);

    display();
    pop();

    free(stack);
    return 0;
}
