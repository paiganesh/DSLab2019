/*
* FILENAME         : Stack_Palindrome.c
* PROBLEM STATEMENT:
* A menu driven Program for the following operations on STACK of Integers
* (Array Implementation)
*    a. Push an Element on to Stack
*    b. Pop an Element from Stack
*    c. Demonstrate how Stack can be used to check Palindrome
*    d. Demonstrate Overflow and Underflow situations on Stack
*    e. Display the status of Stack
*    f. Exit
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E. 
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<math.h>
#include "stack.h"

int isPalindrome(int number);

int main()
{
    int choice, element, number;
    Stack stack = {-1};

    while(1)
    {
        printf( "\n------------ MENU ------------"
                "\n1. Push integer into Stack"
                "\n2. Pop integer from Stack"
                "\n3. Display the Stack"
                "\n4. Palindrome check"
                "\n5. Exit"
                "\nEnter a choice: ");
        scanf("%d", &choice);
        printf("------------------------------\n");

        switch(choice)
        {
            case 1: printf("\nEnter an integer to be inserted: ");
                    scanf("%d", &element);

                    push(&stack, element);
                    break;

            case 2: if( (element = pop(&stack)) != -1)
                        printf("\nPopped element: %d\n", element);
                    break;

            case 3: printStack(stack);
                    break;

            case 4: printf("\nEnter a number to check for palindrome: ");
                    scanf("%d", &number);
                    
                    if(isPalindrome(number))
                        printf("%d is a palindrome.\n", number);
                    else
                        printf("%d is NOT a palindrome.\n", number);
                    break;

            case 5: return 0;

            default: printf("\nInvalid choice. Please re-enter your choice.\n");
}   }   }

int isPalindrome(int number)                        // check if array elements are in palindrome
{
    int reverse = 0, exp = 0;
    Stack s = {-1};
    
    for (int num = number; num != 0; num /= 10)     // push each digit of the number to the stack
        push(&s, num % 10);                         // push remainder to stack
        
    while(!isEmpty(s))                              // pop each digit from stack and 
        reverse += pow(10, exp++) * pop(&s);        // generate reverse number
    
    return (number == reverse);                     // return 1 if equal, 0 otherwise
}