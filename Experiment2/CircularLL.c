#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; 
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; 
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtNthPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp->next == *head) {
            printf("Position out of bounds.\n");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == temp) { 
        free(temp);
        *head = NULL;
    } else {
        struct Node* lastNode = *head;
        while (lastNode->next != *head) {
            lastNode = lastNode->next;
        }
        *head = temp->next;
        lastNode->next = *head;
        free(temp);
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == temp) { 
        free(temp);
        *head = NULL;
    } else {
        struct Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printf("List after insert at beginning: ");
    display(head);

    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    printf("List after insert at end: ");
    display(head);

    insertAtNthPosition(&head, 25, 2);
    printf("List after insert at 2nd position: ");
    display(head);

    deleteAtBeginning(&head);
    printf("List after delete at beginning: ");
    display(head);

    deleteAtEnd(&head);
    printf("List after delete at end: ");
    display(head);

    return 0;
}
