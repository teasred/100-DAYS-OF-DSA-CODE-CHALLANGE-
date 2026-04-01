#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Create queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->capacity = capacity;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

// Check if queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Enqueue
void enqueue(struct Queue* queue, struct Node* item) {
    if (queue->size == queue->capacity)
        return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Dequeue
struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return NULL;

    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue(100);

    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct Node* temp = dequeue(queue);
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(queue, temp->left);

        if (temp->right != NULL)
            enqueue(queue, temp->right);
    }
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}