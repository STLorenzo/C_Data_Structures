#ifndef __INT_DATA_H 
#define __INT_DATA_H

#include "data_types.h"

void* intDataCreate(int);
void intDataDestroy(void *);
COMPARATION intDataCompare(void *, void *);
char* intDataToString(void *);
void* intDataCopy(void*);
int getDigitsOfInt(int i);

#endif