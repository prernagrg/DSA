#include <stdio.h>

int stack[20];
int top = -1;

void push(int n)
{
    stack[++top] = n;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int num, digit, reversed = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    while (num > 0)
    {
        digit = num % 10;
        push(digit);
        num /= 10;
    }

    while (top != -1)
    {
        reversed = reversed * 10 + pop();
    }

    printf("Reversed number: %d\n", reversed);

    return 0;
}
