#include <stdio.h>
#define MAX 10

int top=-1;
int stack[MAX];

void push(){
    if(top==MAX-1){
        printf("Stack Overflow");
        return;
    }
    int val;
    printf("Enter value: ");
    scanf("%d",&val);
    top++;
    stack[top]=val;
    printf("Pushed %d \n",val);
}

void pop(){
    if(top==-1){
        printf("Stack Underflow!");
        return;
    }

    printf("Popped %d \n",stack[top]);
    top--;
}

void display(){
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
        
    }
}

int main(){
    push();
    push();
    push();
    display();
}