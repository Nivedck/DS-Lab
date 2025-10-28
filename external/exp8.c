#include <stdio.h>
#include <stdlib.h>

int stack[20];
int top=-1;

void push(int val){
    if(top==19){
        return;
    }
    top++;
    stack[top]=val;
}

int pop(){
    if(top==-1){
        return -1;
    }
    int data=stack[top];
    top--;
    return data;
}


typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

void insert_head(int val){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
        return;
    }
    Node* temp = head;
    head=newnode;
    head->next=temp;
}

void insert_tail(int val){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next = NULL;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
        return;
    }else if(head->next==NULL){
        head->next = newnode;
        newnode->next = NULL;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->next = NULL;
}

void delete_head(){
    if(head==NULL){
        printf("Empty List!\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }

    Node* temp=head;
    head=head->next;
    free(temp);
}

void delete_tail(){
    if(head==NULL){
        printf("Empty List");
        return;
    }

    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }

    Node* temp= head;

    while(temp->next->next!=NULL){
        temp=temp->next;
    
    }
    free(temp->next);
    temp->next=NULL;
}

void reverse(){
    Node* temp = head;
    while(temp!=NULL){
        push(temp->data);
        temp=temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data=pop();
        temp=temp->next;
    }
}

void count_nodes(){
    int count=0;
    Node* temp=head;

    while(temp!=NULL){
        temp=temp->next;
        count++;
    }

    printf("Number of Nodes:%d\n",count);
}

void display_list(){
    Node* temp=head;
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
                printf("Enter a valuse:");
                scanf("%d",&val);
                insert_tail(val);
                break;
            case 3:
                delete_head();
                break;
            case 4:
                delete_tail();
                break;
            case 5:
                reverse();
                break;
            case 6:
                count_nodes();
                break;
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


