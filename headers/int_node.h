#ifndef __INT_NODE_H 
#define __INT_NODE_H

#include "data_types.h"

void* intNodeCreate(int);
void intNodeDestroy(void *);
COMPARATION intNodeCompare(void *, void *);
char* intNodeToString(void *);
int getDigitsOfInt(int i);

#endif