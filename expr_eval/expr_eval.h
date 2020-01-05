// Expression evaluator in C
// Example usege:
//	char a[20] = "20 + (4*2*2 + 10)*2";
//	printf("%d\n", EvaluateExpression(a));

#ifndef EXPR_EVAL_H
#define EXPR_EVAL_H

#include "../stack/stack.h"

int isOperator(char c);
int isNumeric(char c);
int EvaluatePostfix(char expression[MAX_INPUT_LENGTH]);
void InfixToPostfix(char expression[MAX_INPUT_LENGTH], char transformedExpression[]);
int EvaluateExpression(char expression[MAX_INPUT_LENGTH]);
int hasHigherPrecedence(char o1, char o2);
int operatorWeight(char operator);

#endif // EXPR_EVAL_H
