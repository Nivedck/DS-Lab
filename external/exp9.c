#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* head=NULL;

void insert_head(int val){

    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=val;

    if(head==NULL){
        head=newnode;
        return;
    }

    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void insert_tail(int val){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=val;
    
    if(head==NULL){
        head=newnode;
        return;
    }
    if(head->next==NULL){
        head->next=newnode;
        newnode->prev=head;
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->prev=temp;
}

void delete_head(){
    if(head==NULL){
        printf("List is Empty!\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void delete_tail(){
    if(head==NULL){
        printf("List is Empty!\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void display_list(){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}






int main(){
    int choice;
    int val;

    while(1){
        printf("\n");
        printf("1.Insert at Head\n");
        printf("2.Insert at Tail\n");
        printf("3.Delete Head\n");
        printf("4.Delete Tail\n");
        printf("5.Reverse List\n");
        printf("6.Count Nodes\n");
        printf("7.Display List\n");
        printf("8.Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter a value:");
                scanf("%d",&val);
                insert_head(val);
                break;
            case 2:
                printf("Enter a value:");
                scanf("%d",&val);
                insert_tail(val);
                break;
            case 3:
                delete_head();
                break;
            case 4:
                delete_tail();
                break;
            // case 5:
            //     reverse();
            //     break;
            // case 6:
            //     count_nodes();
            //     break;
            case 7:
                display_list();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Enter a valid choice!\n");
                break;
            
        }
    }
}


