#include "binaryTree.h"

struct Node* createNode (int d)
{
	struct Node* node = (struct Node*) malloc (sizeof(struct Node));
	node->data = d;
	node->right = NULL;
	node->left = NULL;
}

void BFT (struct Node* root)
{
	if (root == NULL) return;
	struct Node* queue[BUFSIZ + 1];
	int front = 0; int rear = 0;
	queue[rear++] = root;

	while (front < rear)
	{
		struct Node* node = queue[front++];
		printf("%d ", node->data);
		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}
}

void inorderDFS (struct Node* root)
{
	if(root == NULL) return;
	inorderDFS(root->left);
	printf("%d ", root->data);
	inorderDFS(root->right);
}

void preorderDFS (struct Node* root)
{
	if (root == NULL) return;
	printf("%d ", root->data);
	preorderDFS (root->left);
	preorderDFS (root->right);
}

void postorderDFS (struct Node* root)
{
	if (root == NULL) return;
	postorderDFS (root->left);
	postorderDFS (root->right);
	printf ("%d ", root->data);
}


struct Node* array_to_BST (int *array, int low, int high)
{
	if (low > high) return NULL;

	int mid = low + (high - low) / 2;

	struct Node* root = createNode(array[mid]);

	root->left = array_to_BST (array, low, mid - 1);
	root->right = array_to_BST (array, mid + 1, high);

	return root;
}
	

int searchDFS (struct Node* root, int x)
{
	if (root == NULL) return 0;
	
	if (root->data == x) return 1;

	int root_left = searchDFS(root->left, x);
	int root_right = searchDFS(root->right, x);

	return root_left || root_right;
}




