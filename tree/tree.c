#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* firstChild;
    struct Node* nextSibling;
}Node;


Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> firstChild = NULL;
    newNode -> nextSibling = NULL;


    return  newNode;
}

void addChild(Node* parent , int childData){
    Node* child = createNode(childData);

    if(parent->firstChild == NULL){
        parent->firstChild = child;
    }
    else{
        Node* temp = parent->firstChild;
        while(temp->nextSibling!=NULL){
            temp=temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void preorder(Node* root){
    if (root == NULL) return;

    printf("%d ",root->data);
    preorder(root->firstChild);
    preorder(root->nextSibling);
}

int main(){

    Node* root = createNode(1);

    addChild(root,2);
    addChild(root,3);
    addChild(root,4);


    addChild(root->firstChild,5);
    addChild(root->firstChild ,6);
    addChild(root->firstChild->nextSibling,7);

    printf("preorder Travesal of tree: ");
    preorder(root);

    return 0;
}

