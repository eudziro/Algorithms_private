#ifndef BINTREE_H
#define BINTREE_H

//
//
//

#ifdef __cplusplus
Extern "C" {
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* right;
	struct Node* left;
};

struct Node* createNode (int );
void BFT (struct Node*);
struct Node *array_to_BST(int *, int , int );
void preorderDFS (struct Node*);
void inorderDFS (struct Node*);
void postorderDFS (struct Node*);
int searchDFS(struct Node* , int);


#ifdef __cplusplus 
}
#endif

#endif // BINTREE_H
