/*-----------Rat in a Maze-----------*/
#include<stdio.h>

#define N 6

int visit[N][N];

void showMatrix(int Mat[N][N]) 
{
    int i , j;
    for (i = 0; i < N ; i++) {
        for (j = 0; j< N ; j++) {
            printf ("  %2d", Mat[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int maze[N][N], int X, int Y) 
{
    if( X < N && X >= 0 && Y >= 0 && Y < N && visit[X][Y] == 0 && maze[X][Y] == 1) {
        return 1;
    }
    else 
        return 0;
}

int solveMaze(int maze[N][N], int sol[N][N], int X, int Y)
{
    if(X == N-1 && Y == N-1) {
        sol[X][Y] = 1;
        return 1;
    }
    if(isSafe(maze, X, Y)) {
        sol[X][Y] = 1;
        visit[X][Y] = 1;

        if(solveMaze(maze, sol, X, Y+1) == 1) {
            return 1;
        }
        
        if(solveMaze(maze, sol, X+1, Y) == 1) {
            return 1;
        }
        
        if(solveMaze(maze, sol, X, Y-1) == 1) {
            return 1;
        }

        if(solveMaze(maze, sol, X-1, Y) == 1)
            return 1;
        
        sol[X][Y] = 0;
        return 0;
    }
    return 0;
}

int main()
{
    int i, j;
    int maze[N][N] = {
        {1,1,1,1,1,0},
        {0,0,0,1,0,0},
        {1,1,1,1,1,1},
        {1,0,0,0,0,0},
        {1,1,0,1,1,1},
        {1,1,1,1,0,1}
    };

    int sol[N][N] ;
    for (i = 0; i <  N; i++)
        for (j = 0; j < N ; j++)
            sol[i][j] = visit[i][j] = 0;
        
    printf("Maze is \n");
    showMatrix(maze);
    if ( solveMaze(maze, sol, 0, 0)) {
        printf("Solution is \n");
        showMatrix(sol);
    } else {
        printf("No solution Found !");
        showMatrix(sol);
    }
    printf("Visit matrix is \n");
    showMatrix(visit);
}