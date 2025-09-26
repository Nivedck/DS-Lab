#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head= (Node*)malloc(sizeof(Node));
head->data=6;
head->next=NULL;

void insert_head(int val){

    if(head==NULL){
        printf("Empty List!!");
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    head = newNode;

};

void print_list(){
    Node* temp=head;

    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}





int main(){
    insert_head(5);
    print_list();


}
