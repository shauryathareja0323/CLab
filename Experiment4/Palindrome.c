#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100


char queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear == MAX_SIZE - 1);
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(char value) {
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

char dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete element.\n");
        return '\0';
    } else {
        char value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return value;
    }
}

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        enqueue(str[i]);
    }
    for (int i = 0; i < len; i++) {
        char ch = dequeue();
        if (ch != str[len - i - 1]) {
            return 0;
        }
    }
    return 1; 
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
