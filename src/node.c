#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()

#include "node.h"

Node* nodeCreate(void *data, Node *before, Node *next, int dataSize, freeFunction freeFn,
	compareFunction compFn, toStringFunction toStringFn){
	// input check
	if(data == NULL || dataSize <= 0) return NULL;

	//variables
	Node *node = NULL;

	// allocate memory for node struct. Return NULL if not posible
	node = (Node*)malloc(sizeof(Node));
	if(node == NULL) return NULL;

	// TODO: CHECK IF CONSTRUCTOR FUNCTION IS NEEDED
	// allocate memory for data. Free node and return NULL if not posible
	node->data = malloc(dataSize)
	if(node->data == NULL){
		free(node);
		return NULL;
	}

	// copy the data
	memcpy(node->data, data, dataSize);

	// assign static values
	node->dataSize = dataSize
	node->freeFn = freeFn;
	node->compFn = compFn;
	node->toStringFn = toStringFn;
	node->next = next;
	node->before = before;

	return node;
}

void nodeDestroy(Node *node){
	// input check
	if(node == NULL) return;

	if(node->freeFn){
		node->freeFn(node->data);
	}

	free(node->data);
	free(node);
}

char* nodeToString(Node *node){
	// input check
	if( node == NULL || !node->toStringFn) return NULL;

	return node->toStringFn(node);
}

COMPARATION nodeCompare(Node *node1, Node *node2){
	// input check
	if( node1 == NULL || node2 == NULL || !node1->compFn
		|| node1->compFn != node2->compFn) return NULL;

	return node1->compFn(node1, node2);
}