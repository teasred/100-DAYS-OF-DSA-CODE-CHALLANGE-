#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    int n, val;
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    Node *head = NULL;
    Node *tail = NULL;

    // Create the circular linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = val;
        
        if (head == NULL) {
            // First node: points to itself
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            // Append to the end
            tail->next = newNode;
            newNode->next = head; // Maintain circular property
            tail = newNode;       // Update tail to new node
        }
    }

    // Traverse and print
    if (head != NULL) {
        Node* current = head;
        
        // Print head first
        printf("%d", current->data);
        current = current->next;

        // Continue until we circle back to head
        while (current != head) {
            printf(" %d", current->data);
            current = current->next;
        }
        printf("\n");
    }

    // Free allocated memory
    // To free a circular list, we must break the circle first
    if (tail != NULL) {
        tail->next = NULL;
    }

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}