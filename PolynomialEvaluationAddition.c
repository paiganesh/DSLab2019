/*
* FILENAME         : PolynomialEvaluationAddition.c
* PROBLEM STATEMENT:
* A Program for the following operations on Singly Circular Linked List (SLL)
* with header nodes
*    a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3
*    b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store
*       the result in POLYSUM(x,y,z)
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E.
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int coef, exp_x, exp_y, exp_z;
    struct node *next;
}Polynomial;

Polynomial * getHeaderNode();
void readPolynomial(Polynomial *head);
void printPolynomial(Polynomial *head);
void insertNode(Polynomial *head, Polynomial node);
int evaluatePolynomial(Polynomial *head, int x, int y, int z);
void addPolynomial(Polynomial *head1, Polynomial *head2, Polynomial *head3);

int main()
{
    Polynomial *poly, *poly1, *poly2, *polySum;
    int x, y, z, choice;

    while(1)
    {
        printf("\n-------- Menu --------\n"
               "1. Polynomial Evaluation\n"
               "2. Polynomial Addition\n"
               "3. Exit\n"
               "Enter a choice: ");
        scanf("%d", &choice);
        printf("----------------------\n\n");

        switch(choice)
        {
        case 1: poly = getHeaderNode();
                printf("Enter a Polynomial with variables (x, y, z) to evaluate:\n");
                readPolynomial(poly);

                printf("Enter the value of variables x, y, z: ");
                scanf("%d %d %d", &x, &y, &z);

                int value = evaluatePolynomial(poly, x, y, z);

                printf("\nFor x = %d, y = %d, z = %d\n", x, y, z);
                printPolynomial(poly);
                printf("Value = %d\n", value);
                break;

        case 2: poly1 = getHeaderNode(); poly2 = getHeaderNode(); polySum = getHeaderNode();
                printf("\nEnter Polynomial 1:\n");
                readPolynomial(poly1);

                printf("\nEnter Polynomial 2:\n");
                readPolynomial(poly2);

                addPolynomial(poly1, poly2, polySum);

                printf("\nPolynomial 1 ");
                printPolynomial(poly1);
                
                printf("\nPolynomial 2 ");
                printPolynomial(poly2);
                
                printf("\nPolynomial Sum ");
                printPolynomial(polySum);
                break;

        case 3: return 0;
        default: printf("\nError: Invalid choice. Please re-enter your choice.");
}   }   }

Polynomial * getHeaderNode()
{
    Polynomial *headNode = (Polynomial *) malloc(sizeof(Polynomial));
    headNode->exp_x = headNode->exp_y = headNode->exp_z = -1;
    headNode->coef = 0;
    headNode->next = headNode;
    return headNode;
}

void readPolynomial(Polynomial *head)
{
    int i, n;
    Polynomial newNode;

    printf("Enter no. of terms in the polynomial: ");
    scanf("%d", &n);
    printf("Enter polynomial:\n");
    for(i = 0; i < n; i++)
    {
        printf("Term %d <coefficient x_exponent y_exponent z_exponent>: ", i+1);
        scanf("%d %d %d %d", &newNode.coef, &newNode.exp_x, &newNode.exp_y, &newNode.exp_z);
        insertNode(head, newNode);
}   }

void insertNode(Polynomial *head, Polynomial node)
{
    Polynomial *newNode = (Polynomial *) malloc(sizeof(Polynomial));
    *newNode = node;

    newNode->next = head->next;     //insert node at front of list
    head->next = newNode;
}

void printPolynomial(Polynomial *head)
{
    Polynomial *p;
    if(head->next == head)
    {
        printf ("Empty polynomial.");
        return;
    }

    printf("f(x,y,z) =");
    for(p = head->next; p != head; p = p->next)
    {
        printf(" %+d", p->coef);
        if(p->exp_x != 0)   printf("x^%d", p->exp_x);
        if(p->exp_y != 0)   printf("y^%d", p->exp_y);
        if(p->exp_z != 0)   printf("z^%d", p->exp_z);
    }
    printf("\n");
}

int evaluatePolynomial(Polynomial *poly, int x, int y, int z)
{
    int sum = 0;

    for(Polynomial *p = poly->next; p != poly; p = p->next)
    {
        sum += p->coef * pow(x, p->exp_x) * pow(y, p->exp_y) * pow(z, p->exp_z);
    }
    return sum;
}

void addPolynomial(Polynomial *polyHead1, Polynomial *polyHead2, Polynomial *polySum)
{
    Polynomial *poly1 = getHeaderNode(), *poly2 = getHeaderNode();  //create 2 new list
    Polynomial *p1, *p2, *prev_p1, *prev_p2;

    for(p1 = polyHead1->next; p1 != polyHead1; p1 = p1->next)       //duplicate the 2 lists
        insertNode(poly1, *p1);
    for(p2 = polyHead2->next; p2 != polyHead2; p2 = p2->next)
        insertNode(poly2, *p2);

    prev_p1 = poly1;
    for(p1 = poly1->next; p1 != poly1; p1 = p1->next)   //for each term in poly1
    {
        prev_p2 = poly2;
        for(p2 = poly2->next; p2 != poly2; p2 = p2->next)   //and for each term in poly2
        {
            //if degrees are same, add coefficients
            if(p1->exp_x == p2->exp_x && p1->exp_y == p2->exp_y && p1->exp_z == p2->exp_z)
            {
                p1->coef += p2->coef;
                insertNode(polySum, *p1);

                //delete p1 & p2
                prev_p1->next = p1->next;
                prev_p2->next = p2->next;
                free(p1); free(p2);
                p1 = prev_p1;
                break;
            }
            prev_p2 = p2;
        }
        prev_p1 = p1;
    }

    //insert remaining nodes of poly1 & poly2 to polysum
    for(p1 = poly1->next; p1 != poly1; p1 = p1->next)
        insertNode(polySum, *p1);

    for(p2 = poly2->next; p2 != poly2; p2 = p2->next)
        insertNode(polySum, *p2);
}
