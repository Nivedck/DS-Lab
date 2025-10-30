#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;


Node* tail=NULL;

void enqueue(int val){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;

    if(tail==NULL){
        tail=newnode;
        tail->next=tail;
        return;
    }

    newnode->next=tail->next;
    tail->next = newnode;
    tail=newnode;
}

void dequeue(){
    if(tail==NULL){
        printf("Queue Underflow! \n");
        return;
    }
    
    Node* head = tail->next;
    
    if(head==tail){
        free(tail);
        tail=NULL;
        return;
    }

    tail->next=head->next;
    free(head);
}


void display_queue() {
    if (tail == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = tail->next; // start from head
    printf("Queue: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(back to front)\n");
}

// Function to check if queue is empty
int isEmpty() {
    return (tail == NULL);
}

int main() {
    int choice, val;

    while (1) {
        printf("\n===== Queue using Circular Singly Linked List =====\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            // case 3:
            //     peek();
            //     break;

            case 4:
                display_queue();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}