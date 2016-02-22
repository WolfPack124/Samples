#include <stdio.h>
#include <stdlib.h>

#define V 4

int visited[V];

void printSolution(int path[V])
{
    int i;
    printf("One Hamiltonian path is:");
    for (i = 0; i < V; i++) {
        printf("  %d", path[i]);
    }
    printf("  %d\n", path[0]);
}

int isSafe(int graph[V][V], int path[V], int pos, int v)
{
    int i;
    if(graph[path[pos-1]][v] == 0 || visited[v] == 1) {
        return 0;
    }
    // for(i = 0; i < pos; i++) {
        // if (path[i] == v) {
            // return 0;
        // }
    // }
    return 1;
}

int cHamilton(int graph[V][V], int path[V], int pos)
{
    int v = 0;
    if(pos == V) {
        if (graph[path[pos-1]][path[0]] == 1 ) {
            return 1;
        } else 
            return 0;
    }
    for(v = 1; v < V; v++) {
        if(isSafe(graph, path, pos, v) == 1) {
            path[pos] = v;
            visited[v] = 1;
            if(cHamilton(graph, path, pos+1) == 1) {
                return 1;
            }
            path[pos] = -1;
            visited[v] = 0;
        }
    }
    return 0;
}

void main()
{
    int i;
    int path[V];
    for(i = 0; i < V; i++) {
        path[i] = -1;
        visited[i] = 0;
    }
    int graph1 [V][V] = {
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 1}
    };
    int graph2 [V][V] = {
        {0, 0, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 1}
    };
    path[0] = 0;
    if(cHamilton(graph2, path, 1) == 1) {
        printSolution(path);
    } else {
        printf("No solution found for this graph!\n");
    }
    path[0] = 0;
    if(cHamilton(graph1, path, 1) == 1) {
        printSolution(path);
    } else {
        printf("No solution found for this graph!\n");
    }
}