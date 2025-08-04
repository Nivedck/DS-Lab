#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256


int stack[MAX_SIZE];
int top=-1;

void push(int val){
    if(top>=MAX_SIZE){
        printf("\nStack Overflow !\n");
        return;
    }
    
    stack[++top] = val;
    printf("\n Pushed %d to Stack \n",val);
}

void pop(){
    if(top==-1){
        printf("\nStack Underflow!\n");
        return;
    }

    printf("\n Popped %d \n", stack[top]);
    top=top-1;
}

void display(){
    printf("\n");
    for(int i=0;i<top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){

    while(1){

    printf("\n");
    printf("1.Push \n");
    printf("2.Pop \n");
    printf("3.Display \n");
    printf("4.Exit");
    printf("\n");
    printf("\nEnter a choice : ");
    int choice;
    scanf("%d",&choice);

    switch (choice) {
        case 1:
            int val;
            printf("Enter value: ");
            scanf("%d",&val);
            push(val);
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
            printf("\nInvalid choice !\n");
            break;        
    }

    }
}
