#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

int stack[256];
int count=0;

void push(int x){

    if(count==256){
        fprintf(stderr,"There is no space in the stack");
        return;
    }

    stack[count]=x;
    count++;
}


int pop(){

    if(count==0){
        fprintf(stderr,"empty stack !!");
        exit(1);
    }
    
    int res=stack[count-1];
    count--;
    return res;
}

int peek(){
    return stack[count];
}


int main(){
    push(1);
    push(2);
    push(3);

    int i;

    for(i=0;i<3;i++){
        printf("%d ",pop());
    }
}