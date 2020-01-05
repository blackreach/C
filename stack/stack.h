// Stack data structure in C
// Example usege:
// 	stack s;
//	StackInit(&s, 10);
// Push some data to the stack:
//	StackPush(&s, 1);
//	StackPush(&s, 2);
// Get the last element with:
//	int x = StackTop(&s);
// Finally free the stack object with:
//	DestroyStack(&s);


#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h>

typedef char stackElementType;

typedef struct {
    stackElementType *elements;
    int top;
    int maxSize;
} stack;

void StackInit(stack *stackP, int maxSize);
void StackDestroy(stack *stackp);
int StackIsEmpty(stack *stackP);
int StackIsNotEmpty(stack *stackP);
int StackIsFull(stack *stackP);
void StackPush(stack *stackP, stackElementType element);
stackElementType StackPop(stack *stackP);
int StackSize(stack *stackp);
stackElementType StackTop(stack *stackp);

#endif // STACK_H
