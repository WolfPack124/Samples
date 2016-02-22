#include <stdio.h>
#include <stdlib.h>

#define V 4

int printSol(int C[V])
{
    int i = 0;
    printf("Solution is ");
    for (i = 0; i < V; i++)
        printf ("  %d", C[i]);
    printf("\n");
}

int isSafe(int G[V][V], int C[V], int v, int c)
{
    int i;
    for(i = 0; i < V; i++) {
        if(G[v][i] == 1 && C[i] == c) {
            return 0;
        }
    }
    return 1;
}

int gColor(int G[V][V], int C[V], int mC, int v)
{
    int c;
    if(v == V) {
        return 1;
    }
    for(c = 1; c <= mC; c++) {
        if(isSafe(G, C, v, c)) {
            C[v] = c;
            if (gColor(G, C, mC, v+1) == 1) {
                return 1;
            }
            C[v] = 0;
        }
    }
    return 0;
}

void main()
{
    int i;
    int G[V][V] = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,1,1},
        {1,0,1,0}};
    int C[V];
    for (i = 0; i < V; i++)
        C[i] = 0;
    int mC = 3;
    if ( gColor(G, C, mC, 0) == 1) {
        printSol(C);
    } else {
        printf("Not possible to color with %d colors.\n", mC);
    }
}