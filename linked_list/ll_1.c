#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;


int main(){

Node* head=NULL;
Node* tail=NULL;

head=(Node*)malloc(sizeof(Node));
head->data=1;
head->next=tail;

printf("%d",head->data);

}
