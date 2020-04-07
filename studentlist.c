#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s {
	char *name;
	char *id;
} Student;

void main() {
	Student students[3] = { {"Marouane", "777"},
							{"Nadia", "555"},
							{"Omar", "999"}};
					
	Student *temp = NULL;
	BST *byname = NULL;
	BST *byID = NULL;
	int i;
	
	for(i = 0; i < 3; i++) {
		byname = insert(byname, students[i].name, (void *) (&students[i]));
		byID = insert(byID, students[i].id, (void *) (&students[i]));
	}
	
	temp = find(byID, "555");
	if(temp != NULL) printf("%s is %s in the ID list!\n", temp->id, temp->name);
	else printf("problem with 555...\n");
	temp = find(byID, "222");
	if(temp != NULL) printf("problem with 222...\n");
	else printf("222 is not in the ID list.\n");
	temp = find(byname, "Omar");
	if(temp != NULL) printf("%s is %s in the name list!\n", temp->name, temp->id);
	else printf("problem with Omar...\n");	
	printf("Ordered by name: \n");
	print(byname);
	printf("\nOrdered by ID: \n");
	print(byID);
}