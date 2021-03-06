#include <stdlib.h>
#include <stdio.h>
// binary search tree
// Everything in the left subtree is less than the root.
// Everything in the right subtree is greater than the root.
// Left and right subtrees are binary search trees.

typedef char * BSTData; // The value used for ordering the tree
typedef void * BSTDataSet;  // A link to the whole data set
typedef struct s Student;
typedef struct bt BST;	 // The Binary Search Tree structure


// The only two operations allowed are 'find', and 'insert'.
// You can also provide a 'print' function.
BSTDataSet find(BST *root, BSTData target);
BST *insert(BST *root, BSTData target, BSTDataSet index);

void print2(BST *root, int space); // This function prints the leaves in  the order they were inserted in
void print(BST *root); // The wrapper of the function 'print2' // A smoother way to initialize the space
