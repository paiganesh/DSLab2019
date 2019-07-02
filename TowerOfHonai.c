/*
* FILENAME         : TowerOfHonai.c
* PROBLEM STATEMENT:
* Solving the Towers of Hanoi problem with n disks.
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E.
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include<stdio.h>

int counter;
void tower(int disc, char *src, char *dest, char *aux);

int main()
{
    int noOfDisc;

    printf("Enter number of discs in the tower: ");
    scanf("%d", &noOfDisc);

    tower(noOfDisc, "Source", "Destination", "Auxilary");
    printf("\n\nTotal moves done: %d\n", counter);
}

void tower(int disc, char *src, char *dest, char *aux)
{
    if(disc > 0)
    {
        tower(disc-1, src, aux, dest);
        printf("\nMove disc %d from %s to %s", disc, src, dest);
        counter++;
        tower(disc-1, aux, dest, src);
}   }
