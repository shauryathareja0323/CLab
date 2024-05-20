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

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    struct Stack stack;
    initializeStack(&stack);

    int i = 0; 
    int j = 0; 
    while (infix[i] != '\0') {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix[j++] = c; 
        } else if (c == '(') {
            push(&stack, c); 
        } else if (c == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                printf("Invalid expression\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&stack); 
            }
        } else {
            while (!isEmpty(&stack) && precedence(c) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack); 
            }
            push(&stack, c); 
        }
        i++; 
    }

    
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
