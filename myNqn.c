#include <stdio.h>

#define N 8

void displaySolution(int board[N][N]) 
{
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf(" %2d", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[N][N], int X, int Y) 
{
    int i, j;
    for(i = 0; i < Y; i++) {
        if(board[X][i] == 1) {
            return 0;
        }
    }
    for (i = X, j= Y; i >= 0 && j >=0; i--, j--) {
        if(board[i][j] == 1) {
            return 0;
        }
    }
    for(i = X, j = Y; i < N && j >= 0; i++, j--) {
        if(board[i][j] == 1) {
            return 0;
        }
    }
    return 1;
}

int solveNQ(int board[N][N], int Y)
{
    int X;
    if(Y > N) {
        return 1;
    }
    
    for(X = 0; X < N; X++) {
        if(isSafe(board, X, Y) == 1) {
            board[X][Y] = 1;
            if(solveNQ(board, Y + 1) == 1) {
                return 1;
            }
            board[X][Y] = 0;
        }
    }
    return 0;
}

void main()
{
    int i, j;
    int board[N][N];
    for(i = 0; i < N; i++) 
        for (j = 0; j < N; j++) 
            board[i][j] = 0;
    if (solveNQ(board, 0) == 1) {
        displaySolution(board);
    } else {
        printf("No solution found !");
    }
    
}