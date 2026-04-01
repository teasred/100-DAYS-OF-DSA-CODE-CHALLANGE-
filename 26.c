#include <stdio.h>
#include <stdlib.h>

// Definition of the Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL; // Tail pointer helps in O(1) insertion at the end
    int n, val;

    // 1. Read the number of elements
    scanf("%d", &n);

    // 2. Insert nodes sequentially
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        // Allocate memory for the new node
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            // If the list is empty, the new node becomes both head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Link the new node after the current tail
            tail->next = newNode;
            // Link the new node's prev pointer to the current tail
            newNode->prev = tail;
            // Update tail to the new node
            tail = newNode;
        }
    }

    // 3. Traverse and print in forward order
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");

    // 4. Free allocated memory to avoid leaks
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}