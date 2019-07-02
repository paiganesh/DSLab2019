/*
* FILENAME         : InfixToPostfix.c
* PROBLEM STATEMENT:
* A program to convert and print a given valid parenthesized infix arithmetic
* expression to postfix expression. The expression consists of single character operands
* and the binary operators +, -, *, %, / and ^(exponent).
*
* Sample i/p:((A+B)*C-(D/E))^F^(G+H)
* o/p: AB+C*DE/-FGH+^^
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E.
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include "stack.h"

void infixToPostfix (char *infix, char *postfix);
int getPriority (char, char);
int priority(char);

int main()
{
    char infix[MAX] = {}, postfix[MAX] = {};

    printf("Enter a valid Infix expression with operators (+, -, *, /, %%, ^): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nInfix Expression  : %s", infix);
    printf("\nPostfix Expression: %s\n", postfix);
}

void infixToPostfix (char *infix, char *postfix)
{
    char token;
    int i = 0, j = 0;
    Stack stack = {-1};

    while((token = infix[i++]) != '\0')
    {
        if(isalnum(token))
            postfix[j++] = token;
        else if(token == '(')
            push(&stack, token);
        else if(token == ')')
        {
            while((token = pop(&stack)) != '(')
                postfix[j++] = token;
        }
        else
        {
            while(!isEmpty(stack) && getPriority(topOf(stack), token))
                postfix[j++] = pop(&stack);
            push(&stack, token);
        }
    }
    while(!isEmpty(stack))
        postfix[j++] = pop(&stack);
}

int getPriority (char stkTop, char token)
{
    if (stkTop == '^' && token == '^')
        return 0;
    return (priority(stkTop) >= priority(token));
}

int priority(char token)
{
    switch(token)
    {
        case '(': return 1;
        case '+': case '-': return 2;
        case '*': case '/': case '%': return 3;
        case '^': return 4;
        default : printf("Error:Unknown symbol %c", token),
                  exit(0);
    }   
}