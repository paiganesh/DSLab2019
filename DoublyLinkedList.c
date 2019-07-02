/*
* FILENAME         : DoublyLinkedList.c
* PROBLEM STATEMENT:
* A menu driven Program for the following operations on Doubly Linked List (DLL)
*  of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo
*   a. Create a DLL of N Employees Data by using end insertion.
*   b. Display the status of DLL and count the number of nodes in it
*   c. Perform Insertion and Deletion at End of DLL
*   d. Perform Insertion and Deletion at Front of DLL
*   e. Demonstrate how this DLL can be used as Double Ended Queue
*   f. Exit
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E.
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct employee
{
    char ssn[11], name[50], dept[30], designation[20], phNo[15];
    int salary;
    struct employee *left, *right;
}Node;

typedef Node * NodePtr;
NodePtr list = NULL, lastNode = NULL;
int nodeCount;

void createList();
Node getEmployeeDetails();
void insertNode(Node, char);
void deleteNode(char);
void printList();

int main()
{
    int choice;

    while(1)
    {
        printf("\n--------- DLL Menu ---------"
                "\n\t"
                "\n[1]  Create Initial List"
                "\n[2]  Insert at Front"
                "\n[3]  Delete at Front"
                "\n[4]  Insert at End"
                "\n[5]  Delete at End"
                "\n[6]  Display all nodes"
                "\n[7]  Exit"
                "\nEnter a choice: ");
        scanf("%d", &choice);
        printf("------------------------------\n");

        switch(choice)
        {
            case 1: createList();
                    break;
            case 2: insertNode(getEmployeeDetails(), 'f');
                    break;
            case 3: deleteNode('f');
                    break;
            case 4: insertNode(getEmployeeDetails(), 'e');
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

    printf("\nEnter the number of employees: ");
    scanf("%d", &n);

    printf("\nEnter %d employee details:\n\n", n);
    for(i = 1; i <= n; i++)
    {
        printf("Employee %d\n", i);
        insertNode(getEmployeeDetails(), 'e');      //insert node at end of list
        printf("\n");
}   }

Node getEmployeeDetails()
{
    Node emp;
    emp.left = emp.right = NULL;

    printf("SSN\t:");
    scanf("%s", emp.ssn);

    printf("Name\t:");
    scanf("%s", emp.name);

    printf("Department\t:");
    scanf("%s", emp.dept);

    printf("Designation\t:");
    scanf("%s", emp.designation);

    printf("Salary\t:");
    scanf("%d", &emp.salary);

    printf("Ph. No.\t:");
    scanf("%s", emp.phNo);

    return emp;
}

void insertNode(Node node, char ch)
{
    NodePtr newNode = (NodePtr) malloc (sizeof(Node));
    *newNode = node;

    if(list == NULL)
    {
        list = lastNode = newNode;
    }
    else if(ch == 'f')  //insertion at front of list
    {
        newNode->right = list;
        list->left = newNode;
        list = newNode;
    }
    else            //insertion at end of list
    {
        lastNode->right = newNode;
        newNode->left = lastNode;
        lastNode = newNode;
    }
    nodeCount++;
}

void deleteNode(char ch)    //if ch='f', insert at front, if ch='e', insert at front
{
    NodePtr p = list;
    
    if(list == NULL)
    {
        printf("\nEmpty List");
        return;
    }
    
    if(lastNode == list)   //Only one node in the list
    {
        list = lastNode = NULL;
    }
    else if(ch == 'f')  //delete node at front of list
    {
        list = list->right;
        list->left = NULL;
    }
    else    //delete node at end of list
    {
        p = lastNode;
        lastNode = lastNode->left;
        lastNode->right = NULL;     
    }

    free(p);
    nodeCount--;
}

void printList()
{
    if(list == NULL)
    {
        printf("\nEmpty List.\n");
        return;
    }

    printf("Node Count: %d\n", nodeCount);
    printf("\nStatus of List: [SSN,Name,Dept.,Designation,Salary,Ph. No.]\n");
    for(NodePtr p = list; p != NULL; p = p->right)
    {
        printf("[%s,%s,%s,%s,%d,%s]", p->ssn, p->name, p->dept, p->designation, p->salary, p->phNo);
        if(p->right != NULL)
            printf("<=>");
}   }
