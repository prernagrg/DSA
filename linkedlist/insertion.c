#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

void insterAtBeginning(struct Node *head, int newData){
    if(head == NULL){
        printf("List is empty");
    }

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;

}

void printList(struct Node *n){
    while(n != NULL){
        printf("%d ->", n->data);
        n = n->next;
    }
    printf("NULL \n");
}

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct NOde *) malloc (sizeof(struct Node));

    head->data = 10;
    head -> next =second;

    second-> data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Original linked list");
    printList(head);
}