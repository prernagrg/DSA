// #include <stdio.h>

// int MAXSIZE[5];
// int stack[5];
// int top = -1;

// int isFull()
// {
//     if (top == MAXSIZE - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int isEmpty()
// {
//     if (top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int push(int data)
// {
//     if (!isFull())
//     {
//         top = top + 1;
//         stack[top] = data;
//     }
//     else
//     {
//         printf("Stack is Full");
//     }
// }

// int pop(int data)
// {
//     if (!isEmpty())
//     {
//         data = stack[top];
//         top = top - 1;
//     }
//     else
//     {
//         printf("stack is empty");
//     }
// }

#include <stdio.h>
#define MAXSIZE 10
int top = -1;
int stack[10];

int isFull()
{
    if (top == MAXSIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(int data)
{
    if (!isFull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Stack is Full\n");
    }
}

void display()
{
    printf("Stack Elements\n");
    for (int i = top; i >= 1; i--)
    {
        printf("%d->", stack[i]);
    }
    printf("\t");
}
int main()
{
    int data;
    printf("Enter data\n");
    for (int i = 0; i <= MAXSIZE; i++)
    {
        scanf("%d", &data);
        push(data);
    }

    display();

    return 0;
}
