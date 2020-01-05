#include <stdio.h> // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <string.h> // Supplies strlen(), strcpy(), strcat(), strcmp(), strlwr(), strupr()

#include "data_types.h"
#include "int_data.h"
#include "math.h"

void* intDataCreate(int i){
	int *data = NULL;
	data = (int*)malloc(sizeof(int));
	if(data == NULL) return NULL;
	memcpy(data, &i, sizeof(int));
	return data;
}

void intDataDestroy(void *data){
	if(data == NULL) return;
	free(data);
}

COMPARATION intDataCompare(void *a, void *b){
	if(a == NULL || b == NULL) return ER;

	int ac = *(int*) a;
	int bc = *(int*) b;
	if( ac > bc ) return GT;
	else if(ac < bc) return LT;
	else return EQ;
}

char* intDataToString(void *data){
	char* string = NULL;
	int MAX_SIZE = getDigitsOfInt(*(int*)data);

	// MAX_SIZE + 1 because we need space for the \0 char
	string = (char*)malloc(sizeof(char) * (MAX_SIZE+1));
	if(string == NULL) return NULL;
	sprintf(string, "%d", *(int*)data);
	return(string);
}

void* intDataCopy(void *i){
	if( i == NULL) return NULL;
	int *s = NULL;
	s = (int*)malloc(sizeof(int));
	if ( s == NULL) return NULL;
	memcpy(s, (int*)i, sizeof(int));

	return s;
}

int getDigitsOfInt(int i){
	if(i == 0) return 1;
	return floor(log10(abs(i))) + 1;
}