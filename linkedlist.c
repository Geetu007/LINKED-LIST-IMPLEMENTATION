#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int data);
void delete(int data);
void traverse();

int main() {
    int choice, data;
    
    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }
    return 0;
}

void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node inserted successfully.\n");
}

void delete(int data) {
    struct Node *temp = head, *prev = NULL;
    
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }
    
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully.\n");
}

void traverse() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}