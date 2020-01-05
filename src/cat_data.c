#include <stdio.h> // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <string.h> // Supplies strlen(), strcpy(), strcat(), strcmp(), strlwr(), strupr()

#include "data_types.h"
#include "cat_data.h"
#include "int_data.h"

void* catDataCreate(char* name, char *color, int age){
	if(name == NULL || color == NULL || age < 0) return NULL;

	Cat *cat = NULL;
	cat = (Cat*)malloc(sizeof(Cat));
	if(cat == NULL) return NULL;

	int name_len = strlen(name) +1;
	int color_len = strlen(color) +1;

	cat->name = (char*)malloc(sizeof(char)*name_len);
	if(cat->name == NULL) {
		free(cat);
		return NULL;
	}
	cat->color = (char*)malloc(sizeof(char)*color_len);
	if(cat->color == NULL) {
		free(cat->name);
		free(cat);
		return NULL;
	}

	strcpy(cat->name, name);
	strcpy(cat->color, color);
	cat->age = age;
	return cat;
}

void catDataDestroy(void *c){
	if(c == NULL) return;

	Cat *cat = (Cat*) c;
	free(cat->name);
	free(cat->color);
	free(cat);
}

COMPARATION catDataCompare(void *c1, void *c2){
	if(c1 == NULL || c2 == NULL) return ER;

	Cat *cat1 = (Cat*) c1;
	Cat *cat2 = (Cat*) c2;
	if( cat1->age > cat2->age) return GT;
	else if( cat1->age > cat2->age) return LT;
	else return EQ;
}

char* catDataToString(void *c){
	if(c == NULL) return NULL;

	Cat *cat = (Cat*) c;
	char* s = NULL;
	// LEN of the format strings without the values
	int len_extra = 26;
	int size = strlen(cat->name) + strlen(cat->color) 
		+ getDigitsOfInt(cat->age) + len_extra + 1;

	s = (char*)malloc(sizeof(char) *size);
	if(s == NULL) return NULL;
	sprintf(s, "Cat: %s | color: %s | age: %d", cat->name, cat->color, cat->age);
	return s;
}

void* catDataCopy(void *c){
	if( c == NULL) return NULL;

	Cat *cat = (Cat*) c;
	Cat *copy = NULL;
	copy = catDataCreate(cat->name, cat->color, cat->age);
	if(copy == NULL) return NULL;

	return copy;
}