#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear == N-1){
        printf("Overflow");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear]= x;
    }
}
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
 void main(){
    int num;
    for(int i = 0; i<N; i++){
        printf("enter number %d:", i+1);
        scanf("%d", &num);
        enqueue(num);
    }

    printf("Display after enqueueing");
    display ();

 }