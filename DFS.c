/*
* FILENAME         : DFS.c
* PROBLEM STATEMENT:
*  A Program for the following operations on Graph(G) of Cities
*     a. Create a Graph of N cities using Adjacency Matrix.
*     b. Print all the nodes reachable from a given starting node in a digraph using
*        DFS/BFS method
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E.
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int readGraph(int graph[][MAX]);
void dfs(int graph[][MAX], int startVertex, int noOfVertices);

int main()
{
    int  graph[MAX][MAX] = {0}, startVertex;

    int noOfVertices = readGraph(graph);

    printf("\nEnter start vertex [1-%d]: ", noOfVertices);
    scanf("%d", &startVertex);

    dfs(graph, startVertex, noOfVertices);
} /* end of main */

/* Input function */
int readGraph(int graph[][MAX])
{
    int i, v1, v2, noOfEdges, noOfVertices;

    printf("Enter number of graph Vertices & Edges: ");
    scanf("%d%d", &noOfVertices, &noOfEdges);

    for(i = 1; i <= noOfEdges; i++)
    {
        printf("Enter start & end vertex of edge %d: ", i);
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
    }

    return noOfVertices;
}

void dfs(int a[][MAX], int startVertex, int noOfVertices)
{
    int i, v, visited[MAX] = {0};
    Stack s = {-1};

    visited[startVertex] = 1;
    v = startVertex ;

    printf("\nNodes reachable from start vertex %d: ", startVertex);
    while(1)
    {
        for (i = 1; i <= noOfVertices; i++)
        {
            if (v != i && a[v][i] == 1 && visited[i] == 0)
            {
                push(&s, i);
                visited[i] = 1;
            }
        }
        if (isEmpty(s))
            break;
        v = pop(&s);
        printf("%d  ", v);
    } /* end of while */
} /* end dfs */
