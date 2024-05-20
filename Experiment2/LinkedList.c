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


void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertAtNthPosition(struct Node** head, int data, int position) {
    if (position < 0)
        return;
    if (position == 0 || *head == NULL) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteAtBeginning(struct Node** head) {
    if (*head == NULL)
        return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}


void deleteAtEnd(struct Node** head) {
    if (*head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}


void deleteAtNthPosition(struct Node** head, int position) {
    if (*head == NULL || position < 0)
        return;
    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

    
    deleteAtNthPosition(&head, 2);
    printf("List after delete at 2nd position: ");
    display(head);

    return 0;
}
