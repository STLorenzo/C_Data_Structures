#ifndef __CAT_DATA_H 
#define __CAT_DATA_H

#include "data_types.h"

typedef struct _CAT{
	char *name;
	char *color;
	int age;
} Cat;

void* catDataCreate(char*, char*, int);
void catDataDestroy(void *);
COMPARATION catDataCompare(void *, void *);
void* catDataCopy(void*);
char* catDataToString(void *);

#endif