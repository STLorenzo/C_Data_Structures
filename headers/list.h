#ifndef __LIST_H
#define __LIST_H

typedef struct _List {
	int length;
	Node *head;
	Node *tail;
} List;

List* listCreate(void);
void listDestroy(List *list);

STATUS listPrepend(List *list, void *data, size_t dataSize, freeFunction freeFn,
	compareFunction compFn, toStringFunction toStringFn);
STATUS listAppend(List *list, void *data, size_t dataSize, freeFunction freeFn,
	compareFunction compFn, toStringFunction toStringFn);

int listSize(List *list);
bool listIsEmpty(List *list);

void listForEach(List *list, listIterator iterator);
void* listHead(List* list);
void* listTail(List* list);


STATUS listRemoveFirstElement(List *list);
STATUS listRemoveLastElement(List *list);

STATUS listRemoveElement(List *list, void *element, compareFunction f);
char* listToString(List *list);
void listPrint(List *list, FILE *f);


#endif