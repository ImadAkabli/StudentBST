#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    // printf("%s\n", target);
    if(root == NULL) return NULL;
    else{
      // printf("%s %s\n", target, root->data);
      if(strcmp(target, root->data) < 0)
        return find(root->left, target);
      else if(strcmp(target, root->data) > 0)
        return find(root->right, target);
      else return root->info;
    }
}

BST *insert(BST *root, BSTData target, BSTDataSet index) {
    if(root == NULL) {
        // printf("root %s\n", target);
        root = (BST *) malloc(sizeof(BST));
        root->data =  target;
        root->info = index;
        root->left = NULL;
        root->right = NULL;
        return root;
    } 
    else {
      int compare = strcmp(target, root->data); 
      // printf("%d %s %s\n", compare, target, root->data);
      if(compare < 0) {
      // printf("go left %s\n", target);
        root->left = insert(root->left, target, index);
      } else if(compare > 0) {
        // printf("go right %s\n", target);
        root->right = insert(root->right, target, index);
      } else return root;
    }
}


void print(BST *root) {
    int space = 0;
    if(root == NULL){
      printf("The tree is empty");
      return;
    }

    space += 10;
    print(root->right);

    printf("\n"); 
    for (int i = 10; i < space; i++) 
        printf(" "); 
    printf("%s\n", root->data); 

    print(root->left);
}