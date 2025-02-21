#include "binaryTree.h"

int main (void) 
{
	// create nodes and connect;
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof array/ sizeof (int);

	struct Node* node = array_to_BST(array, 0, n - 1);
	printf("BFS: ");
	BFT(node);

	printf("\ninorder: "); 
	inorderDFS(node);
	printf("\npreorder: "); 
	preorderDFS(node);
	printf("\npostorder: "); 
	postorderDFS(node);

	for (int i = 0; i < 15; i++) 
	{
		if (searchDFS(node, i) == 1)  
		{
			printf("Value %d exists in the BST\n", i);
		} 
		else
		{ 
			fprintf (stderr, "searchDFS: value not found\n"); 
		}
	}
	return 0;

}
