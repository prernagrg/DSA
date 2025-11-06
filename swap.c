#include <stdio.h>

int  main(){
    int a = 0, b = 0, temp = 0;

    printf("Enter first number");
    scanf("%d", &a);

    printf("Enter second number");
    scanf("%d", &b);

    printf("The two numbers before swapping are:\n");
    printf(" a = %d and b = %d \n", a, b);

    temp = a;
    a = b;
    b = temp;

    // after swapping
    printf("After swapping the numbers:\n");
    printf("a = %d and b = %d", a, b);

    return 0;
}