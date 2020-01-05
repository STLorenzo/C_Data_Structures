#include <stdio.h> // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <string.h> // Supplies strlen(), strcpy(), strcat(), strcmp(), strlwr(), strupr()

#include "data_types.h"
#include "string_data.h"

void* stringDataCreate(char* s){
	if(s == NULL) return NULL;

	char* string = NULL;
	// Take into account the space needed for \0
	size_t len = strlen(s) + 1;
	string = (char*)malloc(sizeof(char)* len);
	if(string == NULL) return NULL;
	strcpy(string, s);
	return string;
}

void stringDataDestroy(void *s){
	if( s == NULL) return;
	free(s);
}

COMPARATION stringDataCompare(void *s1, void *s2){
	if(s1 == NULL || s2 == NULL) return ER;

	int len1 = strlen((char*)s1);
	int len2 = strlen((char*)s2);
	if( len1 > len2) return GT;
	else if( len1 > len2) return LT;
	else return EQ;
}

char* stringDataToString(void *s){
	return (char*) stringDataCreate( (char*) s);
}

void* stringDataCopy(void* s){
	if(s == NULL) return NULL;

	char* string = NULL;
	string = (char*) malloc(sizeof(char) * (strlen((char*)s) +1));
	if(string == NULL) return NULL;
	strcpy(string,s);
	return string;
}