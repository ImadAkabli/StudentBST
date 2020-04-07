#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define COUNT 10

typedef struct s {
	char *name;
	char *id;
} Student;

struct bt {
    char *data;
    BST *left;
    BST *right;
    Student* info;
};

BSTDataSet find(BST *root, BSTData target) {
    if(root == NULL) return NULL;
    else{
      if(strcmp(target, root->data) < 0)
        return find(root->left, target);
      else if(strcmp(target, root->data) > 0)
        return find(root->right, target);
      else return root->info; // Return the exact student pointer in the Student Structure
    }
}

BST *insert(BST *root, BSTData target, BSTDataSet index) {
    if(root == NULL) {
        // Allocate Memory for the first tree node
        root = (BST *) malloc(sizeof(BST));
        root->left = root->right = NULL;
        root->data =  target;
        root->info = index;
      
        return root;
    } 
    else {
      int compare = strcmp(target, root->data); // Not to overwhelm the memory by computing 'strcmp' at each time
      if(compare < 0) {
        root->left = insert(root->left, target, index); // Go left
      } else if(compare > 0) {
        root->right = insert(root->right, target, index); // Go Right
      } else return root;
    }
}

void print2(BST *root, int space) { // This function prints the leaves in  the order they were inserted in
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first
    print2(root->right, space); 
  
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%s\n", root->data); 
  
    // Process left child 
    print2(root->left, space); 
} 
  
void print(BST *root) { 
   // Pass initial space count as 0 
   print2(root, 0); 
} 