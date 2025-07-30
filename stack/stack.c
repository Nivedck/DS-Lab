
#include <stdio.h>
#define MAX_SIZE 256


int stack[MAX_SIZE];
int top=-1;

void push(int val){
    
    if(top==MAX_SIZE-1){
        printf("Stack Underflow");
        return;
    }

    top=top+1;
    stack[top]=val;
}

void pop(){
    if(top==-1){
        printf("Stack Underflow");
        return;
    }

    printf("Popped %d \n",stack[top]);
    top=top-1;
}

void peek(){
    if(top==-1){
        printf("Stack is Empty!! ");
        return;
    }

    printf(" %d ",stack[top]);
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    peek();
}
