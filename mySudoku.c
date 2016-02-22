#include <stdio.h>
#include <stdlib.h>

void displayBoard(int board[9][9]);

int isInColumn(int board[9][9], int col, int num)
{
    int i;
    for(i = 0; i < 9; i++) {
        if(board[i][col] == num) {
            return 1;
        }
    }
    return 0;
}

int isInRow(int board[9][9], int row, int num)
{
    int i;
    for(i = 0; i < 9; i++) {
        if(board[row][i] == num) {
            return 1;
        }
    }
    return 0;
}

int isInBox(int board[9][9], int row, int col, int num)
{
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[row+i][col+j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(int board[9][9], int row, int col, int num) 
{
    if(!isInColumn(board, col, num) && !isInRow(board, row, num) && !isInBox(board, row-(row%3), col-(col%3), num)) {
        return 1;
    }
    return 0;
}

int FindFreeLocation(int board[9][9], int *i, int *j)
{
    for(*i = 0; *i < 9; (*i)++) {
        for(*j = 0; *j < 9; (*j)++) {
            if(board[*i][*j] == 0) 
                return 1;
        }
    }
    return 0;
}

int solveSudoku(int board[9][9])
{
    int i = 0, j = 0, k = 1;

    if(FindFreeLocation(board, &i, &j) == 0) {
        return 1;
    }
    for(k = 1; k < 10; k++) {
        if(isSafe(board, i, j, k) == 1) {
            board[i][j] = k;
            if(solveSudoku(board) == 1) {
                return 1;
            }
            board[i][j] = 0;
        }
    }
    return 0;
}

void displayBoard(int board[9][9])
{
    int i, j;
    printf("  ------------------------------------\n");
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            if(j %3 == 0) {
            printf("  |");
        }
            printf(" %2d", board[i][j]);
        }
        printf("  |\n");
        if((i+1) % 3 == 0) {
            printf("  ------------------------------------\n");
        }
    }
}

void main()
{
    int board[9][9];
    int i, j;
    for(i = 0; i < 9 ; i++) 
        for(j = 0; j < 9; j++) 
            board[i][j] = 0;
    // int board[9][9] = {
                      // {3, 0, 6, 5, 0, 8, 4, 0, 0},
                      // {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      // {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      // {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      // {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      // {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      // {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      // {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      // {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    solveSudoku(board);
    displayBoard(board);
}