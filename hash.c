/*
* FILENAME         : Hash.c
* PROBLEM STATEMENT:
* A Program in C that uses Hash function H: K → L as H(K)=K mod m (remainder method), and implement hashing 
* technique to map a given key K to the address space L. Resolve the collision (if any) using linear probing.
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E.
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#define M 11
#define hash(key) (key % M)

typedef struct
{
    int key;
    char name[50];
}Employee;

int insert(Employee *ht[], Employee *emp);
void printHashTable(Employee *ht[]);

int main()
{
    Employee *ht[M] = {NULL}, *emp;
    int cntr = 0;

    while(++cntr <= M)
    {
        emp = (Employee *) malloc(sizeof(Employee));    //create employee record
        printf("Enter employee key & name (-1 q to exit): ");
        scanf("%d %s", &emp->key, emp->name);
        if(emp->key == -1) break;
        printf("Inserted at address %d\n", insert(ht, emp));
    }
    printHashTable(ht);
}

int insert(Employee *ht[], Employee *emp)
{
    int addr = hash(emp->key);          //get hash key
    while(ht[addr] != NULL)             //find for unused space
        addr = (addr + 1) % M;
    ht[addr] = emp;                     //insert record to empty space
    return addr;
}

void printHashTable(Employee *ht[])
{
    printf("\nAddr: Key , Name\n");
    for(int i = 0; i < M; i++)
    {
        if (ht[i] == NULL)
            printf("%3d : ---\n", i);
        else
            printf("%3d : %d, %s\n", i, ht[i]->key, ht[i]->name);
    }
}