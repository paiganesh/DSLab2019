/*
* FILENAME         : CircularQueue.c
* PROBLEM STATEMENT:
* a menu driven Program for the following operations on Circular QUEUE of 
*  Characters (Array Implementation)
*   a. Insert an Element to Circular QUEUE
*   b. Delete an Element from Circular QUEUE
*   c. Demonstrate Overflow and Underflow situations
*   d. Display the status of Circular QUEUE
*   e. Exit
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E. 
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include<stdio.h>
#define MAX 5

typedef struct cqueue
{
    int  rear, front;
    char data[MAX];
}CQueue;

void insert(CQueue *, char);
char delete(CQueue *);
int isEmpty(CQueue);
int isFull(CQueue);
void printQueue(CQueue);

int main()
{
    int   choice;
    char  element;
    CQueue q = {0, 0};

    while(1)
    {
        printf("\n--- Circular Queue Menu ---\n"
               "1. Insert an Element\n"
               "2. Delete an Element\n"
               "3. Display the status\n"
               "4. Exit\n"
               "Enter your choice : ");
        scanf("%d", &choice);
        printf("-------------------------\n");
        
        switch(choice)
        {
            case 1: printf("\nEnter the element to be inserted: ");
                    getc(stdin);    //skip \n character from previous input
                    scanf("%c", &element);
                    insert(&q, element);
                    break;
                    
            case 2: element = delete(&q);
                    if(element != -1)
                        printf("\nDeleted element: %c\n", element);
                    break;
                    
            case 3: printQueue(q);
                    break;
                    
            case 4: return 0;
            
            default: printf("\nError: Invalid choice. Please re-enter your choice.");
}   }   }

void insert(CQueue *q, char element)
{
    if(isFull(*q))
    {
        printf("\nError: Circular Queue Overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = element;
}

char delete(CQueue *q)
{
    if(isEmpty(*q))
    {
        printf("\nError: Circular Queue Underflow\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX;
    return q->data[q->front];
}

int isEmpty(CQueue q)
{   return (q.front == q.rear);    }

int isFull(CQueue q)
{   return (q.front == (q.rear + 1) % MAX);    }

void printQueue(CQueue q)
{
    if(isEmpty(q))
    {
        printf("\nEmpty Queue.\n");
        return;
    }

    int i = q.front;
    printf("\nCircular Queue [ ");
    do
    {
        i = (i + 1) % MAX;
        printf("%c ", q.data[i]);
    } while(i != q.rear);
    printf("]");
}