#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to rotate the linked list to the right by k places
Node* rotateRight(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    // 1. Find the length of the list and the tail node
    Node* tail = head;
    int len = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    // 2. Connect the tail to the head to make it circular
    tail->next = head;

    // 3. Calculate effective rotations
    k = k % len;
    if (k == 0) {
        // If k is 0 (or multiple of len), break the circle and return original head
        tail->next = NULL;
        return head;
    }

    // 4. Find the new tail (which is at position len - k - 1 from start)
    // We need to move (len - k) steps from the current head to reach the new head
    // So the node before that is the new tail.
    Node* newTail = head;
    for (int i = 0; i < len - k - 1; i++) {
        newTail = newTail->next;
    }

    // 5. The new head is the next node of newTail
    Node* newHead = newTail->next;

    // 6. Break the circle
    newTail->next = NULL;

    return newHead;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int n, val, k;

    // Read number of elements
    scanf("%d", &n);

    // Read list elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    // Read k
    scanf("%d", &k);

    // Perform rotation
    head = rotateRight(head, k);

    // Print result
    printList(head);

    // Clean up
    freeList(head);

    return 0;
}