
#include <stdio.h> // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <string.h> // Supplies strlen(), strcpy(), strcat(), strcmp(), strlwr(), strupr()

#include "node.h"
#include "list.h"

/* main.c */
int main(int argc, char *argv[]) {
	// variables
	Node node* = NULL;
	char* node_string = NULL;

	// create data and functions
	int data = 21;
	int data_size = sizeof(int);


	// create node1
	node = nodeCreate(data, NULL, NULL, data_size,
		NULL, NULL, intToString);
	if(node == NULL){
		printf("Error creating node\n");
		return -1;
	}
	// print nodeToString
	node_string = nodeToString(node);
	if(node_string == NULL){
		printf("Error in nodeToString");
		nodeDestroy(node);
		return -1;
	}
	printf("Node data: %s", node_string);
	free(node_string);
	// create node2

	// compare node1 node2

	// destroy node1 node2
	nodeDestroy(node);

	//exit succesful
	return 0;
}

char* intToString(void* i){
	char* string = NULL;
	int MAX_SIZE = 20;

	string = (char*)malloc(sizeof(char) * MAX_SIZE);
	if(string == NULL) return NULL;
	sprintf(string, "%d", *(int*)i)
	return(string)
}