#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, b % a);
    }
}

int main()
{
    int a, b;
    printf("Enter number 'a'");
    scanf("%d", &a);

    printf("Enter number 'b'");
    scanf("%d", &b);

    printf("The GCD of two number is %d", gcd(a, b));
}