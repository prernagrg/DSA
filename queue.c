#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == N - 1) {
        printf("Queue is full! Cannot insert %d\n", x);
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else if (front == rear) {
        printf("Dequeued: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
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

int main() {
    int num;

    // Enqueue 5 numbers using for loop
    for (int i = 0; i < N; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        enqueue(num);
    }

    printf("\nAfter enqueuing:\n");
    display();

    // Dequeue all elements using for loop
    printf("\nDequeuing all elements:\n");
    for (int i = front; i <= rear; i++) {
        dequeue();
    }

    printf("\nAfter dequeuing:\n");
    display();

    return 0;
}
