#include <stdio.h>
#include <conio.h>
 #define N 5
 int queue [N];
 int rear = -1;
 int front = -1;
 void enqueue(int x){
    if (rear == N-1){
        printf("queue is full\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
        printf("%d ");
    }
    else{
        rear ++;
        queue [rear] = x;
    }
 }
 void main(){
    int n;
    for(int i = 0; i<5; i++){
        printf("Enter a mumber");
    scanf("%d", &n);
    }
    for(int i =0; i<5; i++){
        printf("the numbers are %d" , n);
    }
 }