/*
* FILENAME         : SinglyLinkedList.c
* PROBLEM STATEMENT:
* A menu driven Program in C for the following operations on 
* Singly Linked List (SLL) of Student Data with the fields:
*       USN, Name, Branch, Sem, PhNo
*   a. Create a SLL of N Students Data by using front insertion.
*   b. Display the status of SLL and count the number of nodes in it
*   c. Perform Insertion / Deletion at End of SLL
*   d. Perform Insertion / Deletion at Front of SLL (Demonstration of stack)
*   e. Exit
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E.
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char usn[11], name[50], branch[30], phNo[15];
    int sem;
    struct student *next;
}Node;

typedef Node * NodePtr;

NodePtr list = NULL;
int nodeCount;

void createList();
Node getStudentDetails();
void insertNode(Node, char);
void deleteNode(char);
void printList();

int main()
{
    int choice;

    while(1)
    {
        printf("\n--------- SLL Menu ---------"
                "\n[1]  Create Initial List"
                "\n[2]  Insert at Front"
                "\n[3]  Delete at Front"
                "\n[4]  Insert at End"
                "\n[5]  Delete at End"
                "\n[6]  Display all nodes"
                "\n[7]  Exit"
                "\nEnter a choice: ");
        scanf("%d", &choice);
        printf("--------------------------\n");

        switch(choice)
        {
            case 1: createList();
                    break;
            case 2: insertNode(getStudentDetails(), 'f');
                    break;
            case 3: deleteNode('f');
                    break;
            case 4: insertNode(getStudentDetails(), 'e');
                    break;
            case 5: deleteNode('e');
                    break;
            case 6: printList();
                    break;
            case 7: return 0;
            default: printf("Error: Invalid choice. Please re-enter your choice.");
        }//end of switch
    }//end of while
}

void createList()
{
    int n, i;

    printf("\nEnter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter %d student(s) details:\n\n", n);
    for(i = 1; i <= n; i++)
    {
        printf("Student %d\n", i);
        insertNode(getStudentDetails(), 'f');
        printf("\n");
}   }

Node getStudentDetails()
{
    Node s;
    s.next = NULL;

    printf("USN\t:");
    scanf("%s", s.usn);

    printf("Name\t:");
    scanf("%s", s.name);

    printf("Branch\t:");
    scanf("%s", s.branch);

    printf("Sem\t:");
    scanf("%d", &s.sem);

    getc(stdin);
    printf("Ph. No.\t:");
    scanf("%s", s.phNo);

    return s;
}

void insertNode(Node node, char ch)
{
    NodePtr newNode = (NodePtr) malloc(sizeof (Node));

    *newNode = node;
    newNode->next = NULL;

    if(list == NULL)
    {
        list = newNode;
    }
    else if(ch == 'f')  //insert at front of list
    {
        newNode->next = list;
        list    = newNode;
    }
    else                //insert at end of list
    {
        NodePtr p;
        for(p = list; p->next != NULL; p = p->next);  //traverse to end of list
        p->next = newNode;      //insert node
    }
    nodeCount++;
}

void deleteNode(char ch)
{
    if(list == NULL)
    {
        printf("Error: Empty List!\n");
        return;
    }
    
    NodePtr p = list;
    if (ch == 'f')    //delete from front of list
    {
        list = list->next;
    }
    else             //delete from end of list
    {
        NodePtr q;
        for(; p->next != NULL; p = p->next)    //traverse to end of list
            q = p;
	
	//if only 1 node, set list to NULL
        (p == list)? (list = NULL) : (q->next = NULL);   
    }

    free(p);
    nodeCount--;
}

void printList()
{
    if(list == NULL)
    {
        printf("\nEmpty List!\n");
        return;
    }

    printf("Node Count: %d\n", nodeCount);
    printf("\nStatus of List: [USN,Name,Branch,Semester,Phone No.]\n");
    for(NodePtr p = list; p != NULL; p = p->next)
    {
        printf("[%s,%s,%s,%d,%s]", p->usn, p->name, p->branch, p->sem, p->phNo);
        if(p->next != NULL)
            printf("-->");
}   }
