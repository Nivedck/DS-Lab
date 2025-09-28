#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

void push(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Stack Overflow , Unable to Allocate Memory !! \n");
        return;
    }

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    printf("%d Pushed to the Stack \n",value);
}

void pop(){
    if(top==NULL){
        printf("Stack Underflow!! \n");
        return;
    }

    printf("Popped %d \n",top->data);
    Node* temp = top;
    top=top->next;
    free(top);
}

void display(){
    if(top==NULL){
        printf("Stack is Empty! \n");
        return;
    }

    Node* temp = top;
    
    printf("Stack Elements : ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");
}

int main(){
    int choice , value;

    while(1){
        printf("\n --------MENU--------\n");
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Display \n");
        printf("4. Exit \n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter Number: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\n Enter a valid choice !! \n");
                break;
            
        }
        
    }
}


