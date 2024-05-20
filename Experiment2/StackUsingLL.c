#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}


int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = temp->next;
    free(temp);
    return poppedData;
}


int isEmpty(struct Node* top) {
    return top == NULL;
}


void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}


int main() {
    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    display(top);

    printf("Popped element: %d\n", pop(&top));

    display(top);

    return 0;
}
