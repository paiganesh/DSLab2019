/*
* FILENAME         : PostfixEvaluation.c
* PROBLEM STATEMENT:
* Program to evaluate Postfix Expression with operators:
* +, -, *, /, %, ^(Power).
*
* I/p = 21+3*52/-11+^    O/p: 49
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E.
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include "stack.h"

int  evaluatePostfix (char *postfix);
int  calculate (int operand1, char operator, int operand2);

int main()
{
    char postfix[MAX];

    printf("\nEnter a valid Postfix Expression containing operators (+, -, *, /, %%, ^): ");
    scanf("%s", postfix);

    printf("\n%s = %d\n", postfix, evaluatePostfix(postfix));
}

int evaluatePostfix(char *postfix)
{
    char    token;
    int     i = 0, op1, op2, result;
    Stack   stack = {-1};

    while((token = postfix[i++]) != '\0')
    {
        if(isdigit(token))
            push(&stack, token - '0'); 
        else
        {
            op2 = pop(&stack);
            op1 = pop(&stack);
            result = calculate(op1, token, op2);
            push(&stack, result);
        }
    }
    
    return pop(&stack);
}

int calculate(int operand1, char operator, int operand2)
{
      switch(operator)
      {
          case '+': return operand1 + operand2;
          case '-': return operand1 - operand2;
          case '*': return operand1 * operand2;
          case '/': if(operand2 == 0)
                    {
                        printf("\nError: Division By Zero");
                        exit(0);
                    }
                    return operand1 / operand2;
          case '%': if(operand2 == 0)
                    {
                        printf("\nError:Floating point error.");
                        exit(0);
                    }
                    return operand1 % operand2;
          case '^': return pow(operand1, operand2);
          default : printf("\nError: Unknown Symbol '%c'", operator);
                    exit(0);
      }
}