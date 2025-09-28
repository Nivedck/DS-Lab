#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val) {
    // Check if queue is full
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! (Full)\n");
        return;
    }

    // First element insertion
    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX; // Circular increment
    queue[rear] = val;
    printf("Inserted: %d\n", val);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! (Empty)\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    // If only one element is left
    if (front == rear) {
        front = rear = -1; // Reset to empty state
    } else {
        front = (front + 1) % MAX; // Circular increment
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break; // Stop when we reach the rear
        i = (i + 1) % MAX; // Circular increment
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    dequeue();
    dequeue();
    display();

    enqueue(50);
    enqueue(60); // Wrap-around insertion
    display();

    enqueue(70); // Should show overflow
    return 0;
}
