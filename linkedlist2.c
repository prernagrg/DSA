
//Deletion of node in different positions in singly linked list

#include <stdio.h>
#include <stdlib.h>

//Structure for node in singly linked list

struct Node{
    int data;
    struct Node *next;
};

//deletion at beginning

void deleteAtBeginning(struct Node *head){
    if (head == NULL){
        printf("List is Empty\n");
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted first node");
};

//Deletion of node in between

void deleteInBetween(struct Node *head, int position){
    if(head == NULL){
        printf("List is empty");
    }
    struct Node *temp = head;

    //if deleting the first node
    if(position == 1){
        head = temp->next;
        free(temp);
        printf("Node at position 1 deleted");
    }

    //traverse to the node before the one to delete
    for(int i = 1; temp != NULL && i<position - 1; i++){
        temp = temp->next;
    }
    
    //if position is invalid
    if(temp == NULL || temp->next == NULL){
        printf("Position is out of range");
    }

    struct Node *del = temp->next; //node to delete
    temp->next = del->next;
    free(del);
    printf("Node at position %d deleted \n", position);
}

//deletion at the end

void deletionAtEnd(struct Node *head){
    if(head == NULL){
        printf("List is empty");
    }
     
    struct Node *temp = head;

    //if only one node

    if(temp->next == NULL){
        free(temp);
        head = NULL;
        printf("last node deleted");
    }

    //traverse to secondlast node
    while(temp->next->next != NULL){
        temp = temp->next;
    }
     free(temp->next); //delete last node
     temp->next = NULL; //make second last node the new end
     printf("Node deleted from the end \n");
}
