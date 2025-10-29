#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

void insert_head(int val){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
        head->next=head;
        return;
    }
    if(head->next==head){
        head->next=newnode;
        newnode->next=head;
    }

    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->next=head;
    head=newnode;
}

void insert_tail(int val){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
        head->next=head;
        return;
    }

    if(head->next==head){
        head->next=newnode;
        newnode->next = head;
        return;
    }

    Node* temp= head;

    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->next=head;

}

void delete_head(){
    if(head==NULL){
        printf("List is Empty!\n");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    Node* temp=head;
    
    while(temp->next!=head){
        temp=temp->next;
    }

    Node* delete=head;
    temp->next=head->next;
    head=head->next;

    free(delete);
}


void delete_tail(){
    if(head==NULL){
        printf("List is Empty!\n");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }

    free(temp->next);
    temp->next=head;
}

void display_list(){
    if(head==NULL){
        printf("Empty List!\n");
        return;
    }

    Node* temp =head;

    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("(Back to head)n");
}




int main() {
    int choice, val;

    while (1) {
        printf("\n===== Circular Singly Linked List =====\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Delete Head\n");
        printf("4. Delete Tail\n");
        printf("5. Display List\n");
        printf("6. Count Nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_head(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_tail(val);
                break;

            case 3:
                delete_head();
                break;

            case 4:
                delete_tail();
                break;

            case 5:
                display_list();
                break;

            // case 6:
            //     count_nodes();
            //     break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}