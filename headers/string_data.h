#ifndef __STRING_DATA_H 
#define __STRING_DATA_H

#include "data_types.h"

void* stringDataCreate(char*);
void stringDataDestroy(void *);
COMPARATION stringDataCompare(void *, void *);
void* stringDataCopy(void*);
char* stringDataToString(void *);

#endif