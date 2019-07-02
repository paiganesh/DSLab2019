/*
* FILENAME         : stack.h
* PROBLEM STATEMENT:
*   Array implementation of Integer Stack
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E. 
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct
{
    int top, data[MAX];
} Stack;


int isEmpty(Stack s)                //returns 1 if empty, 0 otherwise
{   return (s.top == -1);   }

int isFull(Stack s)                 //returns 1 if full, 0 otherwise
{   return (s.top == MAX-1);    }

void push(Stack *s, int num)        //pushes an element to stack
{
    if(isFull(*s))
    {
        printf("\nError: Stack overflow\n");
        return;
    }
    s->data[++s->top] = num;
}

int pop(Stack *s)                //removes an element from stack and
{                                //returns element if exist, -1 otherwise
    if(isEmpty(*s))
    {   
        printf("\nError: Stack underflow\n"); 
        return -1;
    }
    return s->data[s->top--];
}

void printStack(Stack s)            //prints all the elements of the stack
{
    printf("\nStack: [ ");
    for(int i = 0; i <= s.top; i++)
    {
        printf("%d ", s.data[i]);
    }
    printf("] <--TOP\n");
}

int topOf(Stack s)                  //returns top element of stack
{   return s.data[s.top];   }