
#include <stdio.h> // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <string.h> // Supplies strlen(), strcpy(), strcat(), strcmp(), strlwr(), strupr()

#include "node.h"
#include "list.h"
#include "data_types.h"

#include "int_data.h"
#include "string_data.h"
#include "cat_data.h"

void checkNode();
void checkListInt();
void checkListString();
void checkListCat();
void checkCombined();

/* main.c */
int main(int argc, char *argv[]) {
	checkCombined();
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

void checkCombined(){
	List* list = NULL;
	STATUS status;

	list = listCreate();
	if(list == NULL){
		printf("Error Creating List\n");
		return;
	}

	// create data and functions
	int* data1 = NULL;
	data1 = intDataCreate(8);
	if(data1== NULL) return;

	char* data2 = NULL;
	data2 = stringDataCreate("Manolo");
	if(data2 == NULL) return;

	Cat* data3 = NULL;
	data3 = catDataCreate("Eustaquio", "Negro", 4);
	if(data3 == NULL) return;

	int data_size1 = sizeof(int);
	int data_size2 = strlen("Manolo") +1;
	int data_size3 = sizeof(data3);

	status = listPrepend(list, data1, data_size1,
		intDataDestroy, intDataCompare, intDataToString, intDataCopy);

	status = listPrepend(list, data2, data_size2,
		stringDataDestroy, stringDataCompare, stringDataToString, stringDataCopy);

	status = listAppend(list, data3, data_size3,
		catDataDestroy, catDataCompare, catDataToString, catDataCopy);

	listPrint(list, stdout);
	printf("\n");

	intDataDestroy(data1);
	stringDataDestroy(data2);
	catDataDestroy(data3);
	listDestroy(list);
}


void checkListCat(){
	List* list = NULL;
	STATUS status;

	list = listCreate();
	if(list == NULL){
		printf("Error Creating List\n");
		return;
	}

	// create data and functions
	Cat* data = NULL;
	data = catDataCreate("Eustaquio", "Negro", 4);
	if(data == NULL) return;

	Cat* data2 = NULL;
	data2 = catDataCreate("Segismunda", "Blanca con rayas marrones", 7);
	if(data2 == NULL){
		catDataDestroy(data);
		return;
	}

	int data_size1 = sizeof(data);
	int data_size2 = sizeof(data2);

		// PREPEND TWO TIMES
	status = listPrepend(list, data, data_size1,
		catDataDestroy, catDataCompare, catDataToString, catDataCopy);

	status = listPrepend(list, data, data_size1,
		catDataDestroy, catDataCompare, catDataToString, catDataCopy);

	status = listAppend(list, data2, data_size2,
		catDataDestroy, catDataCompare, catDataToString, catDataCopy);

	status = listAppend(list, data2, data_size2,
		catDataDestroy, catDataCompare, catDataToString, catDataCopy);

	listPrint(list, stdout);
	printf("\n");

	status = listRemoveFirstElement(list);
	status = listRemoveLastElement(list);

	listPrint(list, stdout);
	printf("\n");

	catDataDestroy(data);
	catDataDestroy(data2);
	listDestroy(list);
}

void checkListString(){
	List* list = NULL;
	STATUS status;

	list = listCreate();
	if(list == NULL){
		printf("Error Creating List\n");
		return;
	}

	// create data and functions
	int data_size1 = strlen("Manolo") +1;
	int data_size2 = strlen("Pepa") +1;

	char* data = NULL;
	data = stringDataCreate("Manolo");
	if(data == NULL) return;

	char* data2 = NULL;
	data2 = stringDataCreate("Pepa");
	if(data2 == NULL){
		stringDataDestroy(data);
		return;
	}

		// PREPEND TWO TIMES
	status = listPrepend(list, data, data_size1,
		stringDataDestroy, stringDataCompare, stringDataToString, stringDataCopy);

	status = listPrepend(list, data, data_size1,
		stringDataDestroy, stringDataCompare, stringDataToString, stringDataCopy);

	status = listAppend(list, data2, data_size2,
		stringDataDestroy, stringDataCompare, stringDataToString, stringDataCopy);

	status = listAppend(list, data2, data_size2,
		stringDataDestroy, stringDataCompare, stringDataToString, stringDataCopy);

	listPrint(list, stdout);
	printf("\n");

	status = listRemoveFirstElement(list);
	status = listRemoveLastElement(list);

	listPrint(list, stdout);
	printf("\n");

	stringDataDestroy(data);
	stringDataDestroy(data2);
	listDestroy(list);

}

void checkListInt(){
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
	data = intDataCreate(n);
	if(data == NULL) return;

	int* data2 = NULL;
	data2 = intDataCreate(n2);
	if(data2 == NULL){
		intDataDestroy(data);
		return;
	}

	// PREPEND TWO TIMES
	status = listPrepend(list, data, data_size,
		intDataDestroy, intDataCompare, intDataToString, intDataCopy);
	if(status == ERROR){
		printf("Error prepending\n");
		listDestroy(list);
		intDataDestroy(data);
		intDataDestroy(data2);
		return;
	}

	status = listPrepend(list, data, data_size,
		intDataDestroy, intDataCompare, intDataToString, intDataCopy);
	if(status == ERROR){
		printf("Error prepending\n");
		listDestroy(list);
		intDataDestroy(data);
		intDataDestroy(data2);
		return;
	}

	status = listAppend(list, data2, data_size,
		intDataDestroy, intDataCompare, intDataToString, intDataCopy);
	if(status == ERROR){
		printf("Error prepending\n");
		listDestroy(list);
		intDataDestroy(data);
		intDataDestroy(data2);
		return;
	}

	status = listAppend(list, data2, data_size,
		intDataDestroy, intDataCompare, intDataToString, intDataCopy);
	if(status == ERROR){
		printf("Error prepending\n");
		listDestroy(list);
		intDataDestroy(data);
		intDataDestroy(data2);
		return;
	}

	listPrint(list, stdout);
	printf("\n");

	status = listRemoveFirstElement(list);
	if(status == ERROR){
		printf("Error removing First\n");
		listDestroy(list);
		intDataDestroy(data);
		intDataDestroy(data2);
		return;
	}

	status = listRemoveLastElement(list);
	if(status == ERROR){
		printf("Error removing Last\n");
		listDestroy(list);
		intDataDestroy(data);
		intDataDestroy(data2);
		return;
	}

	listPrint(list, stdout);
	printf("\n");

	intDataDestroy(data);
	intDataDestroy(data2);
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
	data = intDataCreate(n);
	if(data == NULL) return;

	// create node1
	node = nodeCreate(data, NULL, NULL, data_size,
		NULL, intDataCompare, intDataToString, intDataCopy);
	if(node == NULL){
		intDataDestroy(data);
		printf("Error creating node\n");
		return;
	}
	intDataDestroy(data);

	int* data2 = NULL;
	data2 = intDataCreate(n2);
	if(data2 == NULL){
		nodeDestroy(node);
		return;
	}

	// create node2
	Node *node2 = NULL;
	node2 = nodeCreate(data2, NULL, NULL, data_size,
		NULL, intDataCompare, intDataToString, intDataCopy);
	if(node == NULL){
		printf("Error creating node\n");
		nodeDestroy(node);
		intDataDestroy(data2);
		return;
	}
	intDataDestroy(data2);

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