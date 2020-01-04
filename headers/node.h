/* 	ifndef checks if __LIST_H has been defined previously. If it hasn't enters 
	the body. If it has been already defined goes to endif. In this case executes nothing.
	This is useful in medium sized projects where multiple .c files impor the same .h,
	so the compiler only imports it once.

	For example;
	This node.h file can be imported with: 

	#include "node.h" 

	in the node.c file and main.c file. So thanks to the ifndef the compiler only
	imports one time this node.h file.
*/
#ifndef __NODE_H 
#define __NODE_H

#include "data_types.h"

typedef struct _Node {
	void* data;
	struct _Node *next;
	struct _Node *before;
	int dataSize;
	freeFunction freeFn;
	compareFunction compFn;
	toStringFunction toStringFn;
} Node;

Node* nodeCreate(void* data, Node *before, Node* next, int dataSize, freeFunction freeFn,
	compareFunction compFn, toStringFunction toStringFn);
void nodeDestroy(Node *node);
char* nodeToString(Node *node);
COMPARATION nodeCompare(Node *node1, Node *node2);


#endif