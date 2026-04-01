#include <stdio.h>
#include <stdlib.h>

// Node structure for the Polynomial Linked List
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int c, int e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in decreasing order of exponent
void insert(Node** head, int c, int e) {
    Node* newNode = createNode(c, e);

    // If list is empty or new term has higher exponent than the current head
    if (*head == NULL || e > (*head)->exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse to find the correct position
    Node* current = *head;
    while (current->next != NULL && current->next->exp >= e) {
        current = current->next;
    }

    // Insert the node
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the polynomial
void display(Node* head) {
    while (head != NULL) {
        printf("%d", head->coeff);
        
        if (head->exp > 1) {
            printf("x^%d", head->exp);
        } else if (head->exp == 1) {
            printf("x");
        }
        // If exp is 0, we only print the coefficient

        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

// Function to free allocated memory
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
    int n, coeff, exp;

    // Read number of terms
    scanf("%d", &n);

    // Read terms and insert into the list
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(&head, coeff, exp);
    }

    // Display the polynomial
    display(head);

    // Clean up
    freeList(head);

    return 0;
}