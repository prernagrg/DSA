#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[50], postfix[50];
    int k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[k++] = infix[i];
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
