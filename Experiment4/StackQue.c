#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int array[MAX_SIZE];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

int isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    } else if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->array[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete element.\n");
        return -1;
    } else if (queue->front == queue->rear) {
        int value = queue->array[queue->front];
        queue->front = queue->rear = -1;
        return value;
    } else {
        int value = queue->array[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
        return value;
    }
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return queue->array[queue->front];
}

typedef struct {
    Queue* q1;
    Queue* q2;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

void push(Stack* stack, int value) {
    if (isEmpty(stack->q1)) {
        enqueue(stack->q1, value);
        while (!isEmpty(stack->q2)) {
            enqueue(stack->q1, dequeue(stack->q2));
        }
    } else {
        enqueue(stack->q2, value);
        while (!isEmpty(stack->q1)) {
            enqueue(stack->q2, dequeue(stack->q1));
        }
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack->q1)) {
        return dequeue(stack->q1);
    } else if (!isEmpty(stack->q2)) {
        return dequeue(stack->q2);
    }
    printf("Stack is empty. Cannot pop.\n");
    return -1;
}

int top(Stack* stack) {
    if (!isEmpty(stack->q1)) {
        return peek(stack->q1);
    } else if (!isEmpty(stack->q2)) {
        return peek(stack->q2);
    }
    printf("Stack is empty. Cannot peek.\n");
    return -1;
}

int main() {
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element: %d\n", top(stack));

    printf("Popping elements: ");
    while (!isEmpty(stack->q1) || !isEmpty(stack->q2)) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    return 0;
}
