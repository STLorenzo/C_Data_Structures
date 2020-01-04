
#include <stdio.h> // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <string.h> // Supplies strlen(), strcpy(), strcat(), strcmp(), strlwr(), strupr()

#include "node.h"
#include "list.h"
#include "data_types.h"



char* intToString(void* i);
COMPARATION intCompare(void *a, void *bool);

/* main.c */
int main(int argc, char *argv[]) {
	// variables
	Node *node = NULL;
	char *node_string = NULL;

	// create data and functions
	int data = 21;
	int data2 = 22;
	int data_size = sizeof(int);

	// create node1
	node = nodeCreate(&data, NULL, NULL, data_size,
		NULL, intCompare, intToString);
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
	printf("Node data: %s\n", node_string);
	free(node_string);

	// create node2
	Node *node2 = NULL;
	node2 = nodeCreate(&data2, NULL, NULL, data_size,
		NULL, intCompare, intToString);
	if(node == NULL){
		printf("Error creating node\n");
		nodeDestroy(node);
		return -1;
	}
	// compare node1 node2
	COMPARATION comp;
	comp = nodeCompare(node, node2);
	printf("Comp %d\n", comp);

	// destroy node1 node2
	nodeDestroy(node);
	nodeDestroy(node2);

	//exit succesful
	return 0;
}

char* intToString(void* i){
	char* string = NULL;
	int MAX_SIZE = 20;

	string = (char*)malloc(sizeof(char) * MAX_SIZE);
	if(string == NULL) return NULL;
	sprintf(string, "%d", *(int*)i);
	return(string);
}

COMPARATION intCompare(void *a, void *b){
	if(a == NULL || b == NULL) return ER;

	int ac = *(int*) a;
	int bc = *(int*) b;
	if( ac > bc ) return GT;
	else if(ac < bc) return LT;
	else return EQ;
}