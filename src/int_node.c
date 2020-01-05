#include <stdio.h> // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <string.h> // Supplies strlen(), strcpy(), strcat(), strcmp(), strlwr(), strupr()

#include "data_types.h"
#include "int_node.h"
#include "math.h"

void* intNodeCreate(int i){
	int *data = NULL;
	data = (int*)malloc(sizeof(int));
	if(data == NULL) return NULL;
	memcpy(data, &i, sizeof(int));
	return data;
}

void intNodeDestroy(void *data){
	free(data);
	data == NULL;
}

COMPARATION intNodeCompare(void *a, void *b){
	if(a == NULL || b == NULL) return ER;

	int ac = *(int*) a;
	int bc = *(int*) b;
	if( ac > bc ) return GT;
	else if(ac < bc) return LT;
	else return EQ;
}

char* intNodeToString(void *data){
	char* string = NULL;
	int MAX_SIZE = getDigitsOfInt(*(int*)data);

	// MAX_SIZE + 1 because we need space for the \0 char
	string = (char*)malloc(sizeof(char) * (MAX_SIZE+1));
	if(string == NULL) return NULL;
	sprintf(string, "%d", *(int*)data);
	return(string);
}

int getDigitsOfInt(int i){
	if(i == 0) return 1;
	return floor(log10(abs(i))) + 1;
}