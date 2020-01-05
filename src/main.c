
#include <stdio.h> // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <string.h> // Supplies strlen(), strcpy(), strcat(), strcmp(), strlwr(), strupr()

#include "node.h"
#include "int_node.h"
#include "list.h"
#include "data_types.h"

void checkNode();
void checkList();

/* main.c */
int main(int argc, char *argv[]) {
	checkList();
	//exit succesful
	return 0;
}

void checkIntDigits(){
	int a = 1, b = 245;
	int c = 234547551;
	printf("n: %d digits: %d\n", a, getDigitsOfInt(a));
	printf("n: %d digits: %d\n", b, getDigitsOfInt(b));
	printf("n: %d digits: %d\n", c, getDigitsOfInt(c));
}

void checkList(){
	List* list = NULL;
	STATUS status;

	list = listCreate();
	if(list == NULL){
		printf("Error Creating List\n");
		return;
	}

	// create data and functions
	int n = 21;
	int n2 = 22;
	int data_size = sizeof(int);

	int* data = NULL;
	data = intNodeCreate(n);
	if(data == NULL) return;

	int* data2 = NULL;
	data2 = intNodeCreate(n2);
	if(data2 == NULL){
		intNodeDestroy(data);
		return;
	}

	// PREPEND TWO TIMES
	status = listPrepend(list, data, data_size,
		intNodeDestroy, intNodeCompare, intNodeToString);
	if(status == ERROR){
		printf("Error prepending\n");
		listDestroy(list);
		intNodeDestroy(data);
		intNodeDestroy(data2);
		return;
	}

	status = listPrepend(list, data, data_size,
		intNodeDestroy, intNodeCompare, intNodeToString);
	if(status == ERROR){
		printf("Error prepending\n");
		listDestroy(list);
		intNodeDestroy(data);
		intNodeDestroy(data2);
		return;
	}

	status = listAppend(list, data2, data_size,
		intNodeDestroy, intNodeCompare, intNodeToString);
	if(status == ERROR){
		printf("Error prepending\n");
		listDestroy(list);
		intNodeDestroy(data);
		intNodeDestroy(data2);
		return;
	}

	status = listAppend(list, data2, data_size,
		intNodeDestroy, intNodeCompare, intNodeToString);
	if(status == ERROR){
		printf("Error prepending\n");
		listDestroy(list);
		intNodeDestroy(data);
		intNodeDestroy(data2);
		return;
	}

	listPrint(list, stdout);
	printf("\n");

	status = listRemoveFirstElement(list);
	if(status == ERROR){
		printf("Error removing First\n");
		listDestroy(list);
		intNodeDestroy(data);
		intNodeDestroy(data2);
		return;
	}

	status = listRemoveLastElement(list);
	if(status == ERROR){
		printf("Error removing Last\n");
		listDestroy(list);
		intNodeDestroy(data);
		intNodeDestroy(data2);
		return;
	}

	listPrint(list, stdout);
	printf("\n");

	intNodeDestroy(data);
	intNodeDestroy(data2);
	listDestroy(list);
}

void checkNode(){
		// variables
	Node *node = NULL;
	char *node_string = NULL;

	// create data and functions
	int n = 21;
	int n2 = 22;
	int data_size = sizeof(int);

	int* data = NULL;
	data = intNodeCreate(n);
	if(data == NULL) return;

	// create node1
	node = nodeCreate(data, NULL, NULL, data_size,
		NULL, intNodeCompare, intNodeToString);
	if(node == NULL){
		intNodeDestroy(data);
		printf("Error creating node\n");
		return;
	}
	intNodeDestroy(data);

	int* data2 = NULL;
	data2 = intNodeCreate(n2);
	if(data2 == NULL){
		nodeDestroy(node);
		return;
	}

	// create node2
	Node *node2 = NULL;
	node2 = nodeCreate(data2, NULL, NULL, data_size,
		NULL, intNodeCompare, intNodeToString);
	if(node == NULL){
		printf("Error creating node\n");
		nodeDestroy(node);
		intNodeDestroy(data2);
		return;
	}
	intNodeDestroy(data2);

	// print nodeToString
	node_string = nodeToString(node);
	if(node_string == NULL){
		printf("Error in nodeToString");
		nodeDestroy(node);
		nodeDestroy(node2);
		return;
	}
	printf("Node data: %s\n", node_string);
	free(node_string);

	
	// compare node1 node2
	COMPARATION comp;
	comp = nodeCompare(node, node2);
	printf("Comp %d\n", comp);

	// destroy node1 node2
	nodeDestroy(node);
	nodeDestroy(node2);
}