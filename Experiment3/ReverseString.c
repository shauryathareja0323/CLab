#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
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

void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push element %c\n", value);
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop element\n");
        exit(EXIT_FAILURE);
    }
    char poppedValue = stack->items[stack->top];
    stack->top--;
    return poppedValue;
}

void reverseString(char *str) {
    int length = strlen(str);
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < length; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    
    reverseString(str);
    
    printf("Reversed string: %s\n", str);
    return 0;
}
