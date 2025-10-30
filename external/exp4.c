#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    if (front == -1) front = 0;  
    rear++;
    queue[rear] = val;
    printf("Enqueued %d\n", val);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n===== Queue Using Array =====\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
