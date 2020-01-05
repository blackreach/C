#include "expr_eval.h"

int MAX_INPUT_LENGTH = 50;

int isOperator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isNumeric(char c) {
    return (c >= '0') && (c <= '9');
}

int EvaluatePostfix(char expression[MAX_INPUT_LENGTH])
{
    stack s;
    StackInit(&s, MAX_INPUT_LENGTH);

    for(int i = 0; i < (int)strlen(expression) ; ++i) {

        if(expression[i] == ' ') continue;

        else if(isNumeric(expression[i])){
            int operand = 0;
            while(i < (int)strlen(expression) && isNumeric(expression[i])) {
                operand = (operand*10) + (expression[i] - '0');
                i++;
            }
            i--;

            StackPush(&s, operand);
        }

        else if(isOperator(expression[i])) {
            char operation = expression[i];

            int operand2 = StackPop(&s);
            int operand1 = StackPop(&s);

            // Perform operation
            int result;
            switch(operation){
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            StackPush(&s, result);
        }

    }

    int finalResult = StackTop(&s);
    StackDestroy(&s);
    return finalResult;
}

void InfixToPostfix(char expression[MAX_INPUT_LENGTH], char transformedExpression[MAX_INPUT_LENGTH]) {
    stack s;
    StackInit(&s, MAX_INPUT_LENGTH);
    char tmp[MAX_INPUT_LENGTH];
    int k = - 1;
    for(int i = 0; i < (int)strlen(expression); i++) {

        if(expression[i] == ' ') {
            tmp[++k] = expression[i];
        }

        else if(isNumeric(expression[i])) {
            tmp[++k] = expression[i];
            if(!isNumeric(expression[i+1])){
                tmp[++k] = ' ';
            }
        }

        else if(isOperator(expression[i])) {
            while(hasHigherPrecedence(StackTop(&s), expression[i]) &&
                  !StackIsEmpty(&s) && StackTop(&s) != '(') {

                tmp[++k] = StackPop(&s);
            }

            StackPush(&s, expression[i]);

        }

        else if(expression[i] == '(') {
            StackPush(&s, expression[i]);
        }

        else if(expression[i] == ')') {
            while(StackTop(&s) != '(' && !StackIsEmpty(&s)) {
                tmp[++k] = StackPop(&s);
            }
            StackPop(&s);
        }
    }

    while(!StackIsEmpty(&s)) {
        tmp[++k] = StackPop(&s);
    }

    tmp[++k] = '\0';

    strcpy(transformedExpression, tmp);

}

int EvaluateExpression(char expression[MAX_INPUT_LENGTH]) {
    char transformedExpression[MAX_INPUT_LENGTH];
    InfixToPostfix(expression, transformedExpression);
    return EvaluatePostfix(transformedExpression);
}

int hasHigherPrecedence(char o1, char o2) {
    if(operatorWeight(o1) > operatorWeight(o2)) return 1;
    else return 0;
}

int operatorWeight(char operator) {
    int weight;
    switch(operator) {
        case '+':
            weight = 0;
            break;
        case '-':
            weight = 0;
            break;
        case '*':
            weight = 1;
            break;
        case '/':
            weight = 1;
            break;
    }

    return weight;
}
