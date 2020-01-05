#include "stack.h"

void StackInit(stack *stackP, int maxSize) {
    stackElementType *tmp;
    tmp = (stackElementType *) malloc(sizeof(stack) * maxSize);

    if(tmp == NULL) {
        fprintf(stderr, "Insufficient memory to create stack!");
        exit(1);
    }

    stackP->elements = tmp;
    stackP->maxSize = maxSize;
    stackP->top = -1;
}

void StackDestroy(stack *stackp) {
    free(stackp->elements);
    stackp->elements= NULL;

    stackp->top = -1;
    stackp->maxSize = 0;
}

int StackIsEmpty(stack *stackP)
{
  return stackP->top < 0;
}

//int StackIsNotEmpty(stack *stackP)
//{
//  return stackP->top > 0;
//}

int StackIsFull(stack *stackP)
{
  return stackP->top >= stackP->maxSize - 1;
}

void StackPush(stack *stackP, stackElementType element)
{
  if (StackIsFull(stackP)) {
    fprintf(stderr, "Can't push element on stack: stack is full.\n");
    exit(1);  /* Exit, returning error code. */
  }

  /* Put information in array; update top. */

  stackP->elements[++stackP->top] = element;
}

stackElementType StackPop(stack *stackP)
{
  if (StackIsEmpty(stackP)) {
    fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
    exit(1);  /* Exit, returning error code. */
  }
  return stackP->elements[stackP->top--];
}

int StackSize(stack *stackp) {
    return stackp->top;
}

stackElementType StackTop(stack *stackp) {
    return stackp->elements[stackp->top];
}
