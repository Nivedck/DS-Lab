#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;


Node* create_node(int val){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;

    return new_node;
}

void print_list(Node* head){
    if(head==NULL){
        printf("Empty List !");
        return;
    }

    Node* current = head;
    while(current!=NULL){
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}



int main(){
   
    Node* head = create_node(1);

    printf("%d \n",head->data);
}
