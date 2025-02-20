#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertNode(struct Node** head, int data) {
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

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;
    struct Node* temp = *head, *prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to traverse and print the linked list
void traverseList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the entire linked list
void freeList(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    
    // Insert elements
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    printf("After insertion:\n");
    traverseList(head);
    
    // Delete an element
    deleteNode(&head, 20);
    printf("After deleting 20:\n");
    traverseList(head);
    
    // Free the linked list
    freeList(&head);
    printf("After freeing list:\n");
    traverseList(head);
    
    return 0;
}
