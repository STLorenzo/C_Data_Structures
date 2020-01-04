#ifndef __DATA_TYPES_H 
#define __DATA_TYPES_H

/*
typedef enum makes than when declaring a variable is not neccesary to put enum all time.

Without typedef:
enum STATUS x = OK;

With typedef:
STATUS x = OK;
*/
typedef enum {
	OK = 1,
	WARNING = 0,
	ERROR = -1
}STATUS;

typedef enum{
	ER = -1,
	EQ = 0,
	GT = 1,
	LT = 2
}COMPARATION;

// enum without = assigment makes first_word = 0, second_word = 1, third_word = 2 ... etc
typedef enum {FALSE, TRUE} bool;

// Function for freeing the element. Has to be given when the element is created
typedef void (*freeFunction)(void *);
// Iterator function for the list 
typedef bool (*listIterator)(void *);
// Comparing function
typedef COMPARATION (*compareFunction)(void *, void *);
// String function
typedef char* (*toStringFunction)(void *);

#endif