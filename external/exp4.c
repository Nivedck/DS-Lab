#include <stdio.h>
#define MAX 10

int queue[MAX];

int front,rear=-1;

void enqueue(int val){
    if(rear==MAX-1){
        printf("Queue overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    rear++;
    queue[rear]=val;
    printf("Enqueued %d",val);
}

void dequeue(){
    if(front==-1){
        printf("Queue Underflow");
        return;
    }

    
}