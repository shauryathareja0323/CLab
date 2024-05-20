#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete element.\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
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
    enqueue(3);
    display(); 
    dequeue();
    display(); 
    enqueue(4);
    display(); 
    return 0;
}
