#include <stdio.h> // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <assert.h> // assert macro. Verifies assumptions made by the program
#include <string.h> // Supplies strlen(), strcpy(), strcat(), strcmp(), strlwr(), strupr()


#include "node.h"
#include "list.h"

List* listCreate(){
	// variables
	List *list = NULL;

	// Always check if every malloc has been able to allocate memory 
	list = (List*) malloc(sizeof(List));
	if(list == NULL) return NULL;

	// Associate values to variables
	list->length = 0;
	list->head = list->tail = NULL;

	// Remember to return the list
	return list;
}

void listDestroy(List *list){
	// input check
	if(list == NULL) return;

	// variables
	Node *current = NULL;

	//while there is at least one element
	while(list->head != NULL){
		// current points to first node(head).
		current = list->head;
		// head points to the next node to current(the first)
		list->head = current->next;
		// current node is destroyed
		nodeDestroy(current);
	}

	free(list);
}

STATUS listPrepend(List *list, void *data, size_t dataSize, freeFunction freeFn,
	compareFunction compFn, toStringFunction toStringFn){
	//input check
	if(list == NULL || data == NULL
		|| dataSize <= 0 || freeFn == NULL
		|| compFn == NULL || toStringFn == NULL) return ERROR;

	//variables
	Node *node = NULL;

	// Create node
	node = nodeCreate(data, /* before */NULL, /* next */NULL, 
		dataSize, freeFn, compFn, toStringFn);
	if(node == NULL) return ERROR;

	// Make node point to the previous first element
	node->next = list->head;
	// put the node at the start of list
	list->head = node;
	// check if it is the first appended node
	if(!list->tail) list->tail = node;
	// if not Make second node point to first
	else node->next->before = node;

	// increase number of elements
	list->length++;
	
	return OK;
}


STATUS listAppend(List *list, void *data, size_t dataSize, freeFunction freeFn,
	compareFunction compFn, toStringFunction toStringFn){
	//input check
	if(list == NULL || data == NULL
		|| dataSize <= 0 || freeFn == NULL
		|| compFn == NULL || toStringFn == NULL) return ERROR;

	//variables
	Node *node = NULL;

	// Create node
	node = nodeCreate(data, /* before */NULL, /* next */NULL, 
		dataSize, freeFn, compFn, toStringFn);
	if(node == NULL) return ERROR;

	// Make previous last node point to the last appended
	if(list->tail){
		list->tail->next = node;
		node->before = list->tail;
	}
	// put the node at the end of list
	list->tail = node;
	// check if it is the first appended node
	if(!list->head) list->head = node;

	// increase number of elements
	list->length++;
	
	return OK;
}


int listSize(List *list){
	//input check
	if(list == NULL) return -1;

	return list->length;
}

bool listIsEmpty(List *list){
	//input check
	if(list == NULL) return TRUE;

	if(!listSize(list)) return TRUE;
	return FALSE;
}

void* listHead(List* list){
	//input check
	if(list == NULL) return NULL;
	return list->head->data;
}

void* listTail(List* list){
	//input check
	if(list == NULL) return NULL;
	return list->tail->data;
}

void listForEach(List *list, listIterator iterator){
	if(list == NULL || list->head == NULL) return;

	Node *node = NULL;
	node = list->head;
	bool result = TRUE;
	while(node != NULL && result){
		result = iterator(node->data);
		node = node->next;
	}
}

STATUS listRemoveFirstElement(List *list){
	//input check
	// TODO: CHECK THIS INPUT ERROR WITH EMPTY LIST
	if(list == NULL || list->head == NULL || list->tail == NULL) return ERROR;

	// check if there is only one 
	if(!list->head->next){
		nodeDestroy(list->head);
		list->head = NULL;
		list->tail = NULL;
	}// if there are more than one
	else{
		Node *second = NULL;
		second = list->head->next;
		nodeDestroy(list->head);
		list->head = second;
		second->before = NULL;
	}

	return OK;
}

STATUS listRemoveLastElement(List *list){
	//input check
	if(list == NULL || list->head == NULL || list->tail == NULL) return ERROR;

	// check if there is only one 
	if(!list->head->next){
		nodeDestroy(list->head);
		list->head = NULL;
		list->tail = NULL;
	}// if there are more than one
	else{
		// Get previous to last node
		Node *previous_to_last = NULL;
		previous_to_last = list->tail->before;
		// remove last element
		nodeDestroy(list->tail);
		// assign value
		list->tail = previous_to_last;
		// because it is the last node make next = NULL
		previous_to_last->next = NULL;
	}

	return OK;
}

char* listToString(List *list){
	if(list == NULL || list->head == NULL) return NULL;

	char *string = NULL;
	char *final = NULL;
	size_t len = 2;

	final = (char*)malloc(sizeof(char) * len);
	strcpy(final,"[");

	Node *node = NULL;
	node = list->head;

	while(node){
		string = nodeToString(node);
		len += (strlen(string)+1);
		final = (char*)realloc(final, len);
		strcat(final, string);
		free(string);
		if(node->next){
			strcat(final,",");
		}
		node = node->next;
	}
	strcat(final, "]");
	return final;
}

void listPrint(List *list, FILE *f){
	if(list == NULL || f == NULL) return;

	char *list_string = NULL;
	list_string = listToString(list);
	fprintf(f,"%s",list_string);
	free(list_string);
}

// TODO: All this shit

/*
STATUS listRemoveElement(List *list, void *data, compareFunction f);


*/


