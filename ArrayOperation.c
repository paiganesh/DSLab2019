/*
* FILENAME         : ArrayOperation.c
* PROBLEM STATEMENT:
* Menu driven Program for the following Array operations
*     a. Creating an Array of N Integer Elements
*     b. Display of Array Elements with Suitable Headings
*     c. Inserting an Element at a given valid Position
*     d. Deleting an Element at a given valid Position
*     e. Exit.
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E. 
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

void createArray (int **a, int capacity);
void printArray (int *a, int capacity);
void insert (int *a, int *n, int element, int position);
int  delete (int *a, int *n, int position);

int main()
{
    int choice, *a = NULL, element, position, noOfElements = 0, capacity;
    
    while(1)
    {
        printf("\n------------- Menu -------------\n"
               "1. Create Array\n"
               "2. Insert Element at a position\n"
               "3. Delete an element at a position\n"
               "4. Display array elements\n"
               "5. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);
        printf("-------------------------------\n");
                
        switch(choice)
        {
            case 1: printf("\nEnter the array capacity: ");
                    scanf("%d", &capacity);
                    
                    createArray(&a, capacity);
                    break;
                    
            case 2: if(a == NULL)
                        printf("\nError: Array not created.\n");
                    else if(noOfElements == capacity)
                        printf("\nArray Overflow.\n");
                    else
                    {
                        printf("\nEnter an integer element & its insert position(0-%d): ", noOfElements);
                        scanf("%d %d", &element, &position);

                        insert(a, &noOfElements, element, position);
                    }
                    break; 
                    
            case 3: if(a == NULL)
                        printf("\nError: Array not created.\n");
                    else if(noOfElements == 0)
                        printf("\nEmpty Array.\n");
                    else
                    {
                        printf("\nEnter the delete position(0-%d): ", noOfElements-1);
                        scanf("%d", &position);

                        element = delete(a, &noOfElements, position);

                        if(element != -1)
                            printf("Deleted element: %d\n", element);
                    }
                    break; 
                    
            case 4: if(a == NULL)
                        printf("\nError: Array not created.\n");
                    else
                        printArray(a, noOfElements);
                    break; 
                    
            case 5: return 0;
            
            default: printf("\nInvalid choice. Please re-enter your choice.\n");
        }
    }
}

void createArray(int **a, int capacity)
{
	*a = (int *)calloc(capacity, sizeof(int));   //create a dynamic array of size capacity    
	
    if(*a == NULL)                               //print error message if memory allocation failed
        printf("Error: Memory allocation failed.");
}

void printArray(int *a, int n)
{    
    printf("\nArray [ ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("]\n");
}

void insert(int *a, int *n, int element, int position)
{
    if(position < 0)                    //print error message for negative value of position
    {
        printf("Error: Invalid position.\n");
        return;
    }
	
    if(position > *n)                  //if position entered is > n, set position to n
        position = *n;
    	
    for(int i = *n; i > position; i--)  //shift elements one position right
        a[i] = a[i-1];    
	
    a[position] = element;              //insert the elements in the array    
	
    (*n)++;                             //increment number of elements in the array
}

int delete(int *a, int *n, int position)
{	
    if(position < 0 || position > *n-1)       //print error message for position outside range.
    {
        printf("\nError: Invalid position.\n");
        return -1;
    }
    	
    int element = a[position];          //backup deleting element
		
    for(int i = position; i < *n; i++)  //shift elements one position left
        a[i] = a[i + 1];
		
    (*n)--;                             //decrement number of elements in array
    
    return element;                     //return deleted element
}