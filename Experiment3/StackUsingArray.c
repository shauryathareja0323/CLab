#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1; 
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push element %d\n", value);
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop element\n");
        exit(EXIT_FAILURE);
    }
    int poppedValue = stack->items[stack->top];
    stack->top--;
    return poppedValue;
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));

    display(&stack);

    return 0;
}
