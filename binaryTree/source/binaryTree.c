#include "binaryTree.h"

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

// In-order DFS: Left, Root, Right
void inOrderDFS(struct Node *node){
    if (node == NULL) return;
    inOrderDFS(node->left);
    printf("%d ", node->data);
    inOrderDFS(node->right);
}

// Pre-order DFS: Root, Left, Right
void preOrderDFS(struct Node *node){
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrderDFS(node->left);
    preOrderDFS(node->right);
}

// Post-order DFS: Left, Right, Root
void postOrderDFS(struct Node *node){
    if (node == NULL) return;
    postOrderDFS(node->left);
    postOrderDFS(node->right);
    printf("%d ", node->data);
}

// BFS: Level order traversal
void BFS(struct Node *root){
    if (root == NULL) return;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node *node = queue[front++];
        printf("%d ", node->data);
        if (node->left)
            queue[rear++] = node->left;
        if (node->right)
            queue[rear++] = node->right;
    }
}

struct Node *createNode(int d){
    struct Node *newNode =
      (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main(){
    // Creating the tree
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = 2;
    root->left = (struct Node *)malloc(sizeof(struct Node));
    root->left->data = 3;
    root->right = (struct Node *)malloc(sizeof(struct Node));
    root->right->data = 4;
    root->left->left = (struct Node *)malloc(sizeof(struct Node));
    root->left->left->data = 5;

    printf("In-order DFS: ");
    inOrderDFS(root);
    printf("\nPre-order DFS: ");
    preOrderDFS(root);
    printf("\nPost-order DFS: ");
    postOrderDFS(root);
    printf("\nLevel order: ");
    BFS(root);

    return 0;
}
