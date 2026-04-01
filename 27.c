#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
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

// Function to calculate the length of the linked list
int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find the intersection point
void findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    
    // Calculate difference in lengths
    int diff = abs(len1 - len2);
    
    // Move the pointer of the longer list 'diff' steps ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            ptr1 = ptr1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            ptr2 = ptr2->next;
        }
    }
    
    // Traverse both lists simultaneously to find the first common value
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    printf("No Intersection\n");
}

// Function to free memory
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n, m, val;

    // Input for first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&list1, val);
    }

    // Input for second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        append(&list2, val);
    }

    // Find and print intersection
    findIntersection(list1, list2);

    // Free allocated memory
    freeList(list1);
    freeList(list2);

    return 0;
}