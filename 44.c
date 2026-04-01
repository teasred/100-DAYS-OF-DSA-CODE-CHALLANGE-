#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Definition for a Queue node used for tree construction.
typedef struct QueueNode {
    TreeNode *tNode;
    struct QueueNode *next;
} QueueNode;

// Definition for the Queue.
typedef struct {
    QueueNode *front, *rear;
} Queue;

// Function to create a new tree node.
TreeNode* newTreeNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Queue operations
void enqueue(Queue *q, TreeNode *tn) {
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->tNode = tn;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

TreeNode* dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QueueNode *temp = q->front;
    TreeNode *tn = temp->tNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return tn;
}

int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

// Function to build the tree from level order traversal array.
TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    TreeNode* root = newTreeNode(arr[0]);
    Queue q = {NULL, NULL};
    enqueue(&q, root);

    int i = 1;
    while (!isQueueEmpty(&q) && i < n) {
        TreeNode* curr = dequeue(&q);

        // Process left child
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newTreeNode(arr[i]);
                enqueue(&q, curr->left);
            }
            i++;
        }

        // Process right child
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newTreeNode(arr[i]);
                enqueue(&q, curr->right);
            }
            i++;
        }
    }
    return root;
}

// Recursive function for Inorder traversal
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Recursive function for Preorder traversal
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Recursive function for Postorder traversal
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Construct the tree
    TreeNode* root = buildTree(arr, n);

    // Perform traversals
    inorder(root);
    printf("\n");
    
    preorder(root);
    printf("\n");
    
    postorder(root);
    printf("\n");

    // Clean up dynamically allocated memory
    free(arr);
    // Note: Ideally, we should also free the tree nodes here using a post-order traversal free function.
    // However, for standard competitive programming problems, explicit tree freeing is often omitted 
    // as the OS reclaims memory after program termination.
    
    return 0;
}