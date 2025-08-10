#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = val;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    display();
    enqueue(3);
    enqueue(4);
    dequeue();
    display();
    return 0;
}
