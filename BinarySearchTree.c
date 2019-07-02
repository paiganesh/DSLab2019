/*
* FILENAME         : BinarySearchTree.c
* PROBLEM STATEMENT:
*  A menu driven Program for the following operations on Binary Search Tree (BST) of Integers
*     a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
*     b. Traverse the BST in Inorder, Preorder and Post Order
*     c. Search the BST for a given key element and report the appropriate message
*     d.Exit
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E. 
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int data;
    struct treenode *left, *right;
}* NODE;

NODE root = NULL;

void constructBinTree(int a[], int n);
void preOrderTraverse(NODE n);
void inOrderTraverse(NODE n);
void postOrderTraverse(NODE n);
int search(int key);

int main()
{
    int choice, a[50], key, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter %d elements of the tree: ", n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    constructBinTree(a, n);

    while(1)
    {
        printf("\n-------------- Menu --------------- "
               "\n[1] Inorder Traversal "
               "\n[2] Preorder Traversal "
               "\n[3] Postorder Traversal "
               "\n[4] Search an integer in the tree "
               "\n[5] Exit "
               "\nEnter your choice: ");
        scanf("%d", &choice);
        printf("----------------------------------\n");

        switch(choice)
        {
            case 1: printf("\nInorder Traversal: ");
                    inOrderTraverse(root);
                    break;
            case 2: printf("\nPreorder Traversal: ");
                    preOrderTraverse(root);
                    break;
            case 3: printf("\nPostorder Traversal: ");
                    postOrderTraverse(root);
                    break;
            case 4: printf("\nEnter the search key:");
                    scanf("%d", &key);                  
                    if(search(key) == 1)
                        printf("\nKey '%d' found in the tree\n", key);
                    else
                        printf("\nKey '%d' not found in the tree\n", key);

                    break;
            case 5: return 0;
            default: printf("\nError: Invalid choice. Please re-enter your choice.");
}   }   }

void constructBinTree(int a[], int n)
{
    int     i;
    NODE    newNode, p, q;

    for(i = 0; i < n; i++)
    {
        newNode = (NODE) malloc(sizeof(struct treenode));
        newNode->data = a[i];
        newNode->left = newNode->right = NULL;

        if(root == NULL)
            root = newNode;
        else
        {
            p = root;
            while(p != NULL)
            {
                q = p;
                if(a[i] < p->data)
                    p = p->left;
                else if(a[i] > p->data)
                    p = p->right;
                else
                {
                    free(newNode);
                    break;
                }
            }
            if(p == NULL)
                (a[i] < q->data)? (q->left = newNode) : (q->right = newNode);
        }
    }
}

void preOrderTraverse(NODE n)
{
    if(n != NULL)
    {
        printf("%d ", n->data);
        preOrderTraverse(n->left);
        preOrderTraverse(n->right);
}   }

void inOrderTraverse(NODE n)
{
    if(n != NULL)
    {
        inOrderTraverse(n->left);
        printf("%d ", n->data);
        inOrderTraverse(n->right);
}   }

void postOrderTraverse(NODE n)
{
    if(n != NULL)
    {
        postOrderTraverse(n->left);
        postOrderTraverse(n->right);
        printf("%d ", n->data);
}   }

int search(int key)
{
    NODE n = root;
    while(n != NULL && n->data != key)
        n = (key > n->data)? n->right : n->left;

    return (n != NULL);
}

