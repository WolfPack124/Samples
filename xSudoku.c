#include <stdio.h>

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


int isAvailable(int puzzle[][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    int i, j;

    for(i=0; i<9; ++i)
    {
        if (puzzle[row][i] == num) return 0;
        if (puzzle[i][col] == num) return 0;
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}

int fillSudoku(int puzzle[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9) return fillSudoku(puzzle, row, col+1);
            else if((row+1)<9) return fillSudoku(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(fillSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fillSudoku(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int main()
{
    int i, j;
    // int puzzle[9][9]={{0, 0, 0, 0, 0, 0, 0, 9, 0},
                      // {1, 9, 0, 4, 7, 0, 6, 0, 8},
                      // {0, 5, 2, 8, 1, 9, 4, 0, 7},
                      // {2, 0, 0, 0, 4, 8, 0, 0, 0},
                      // {0, 0, 9, 0, 0, 0, 5, 0, 0},
                      // {0, 0, 0, 7, 5, 0, 0, 0, 9},
                      // {9, 0, 7, 3, 6, 4, 1, 8, 0},
                      // {5, 0, 6, 0, 8, 1, 0, 7, 4},
                      // {0, 8, 0, 0, 0, 0, 0, 0, 0}};
    int puzzle[9][9] = {
                      {3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if(fillSudoku(puzzle, 0, 0))
    {
        displayBoard(puzzle);
        // printf("\n+-----+-----+-----+\n");
        // for(i=1; i<10; ++i)
        // {
            // for(j=1; j<10; ++j) printf("|%d", puzzle[i-1][j-1]);
            // printf("|\n");
            // if (i%3 == 0) printf("+-----+-----+-----+\n");
        // }
    }
    else printf("\n\nNO SOLUTION\n\n");

    return 0;
}