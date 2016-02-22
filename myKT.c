/*-----------The Knight’s tour problem-----------*/
#include <stdio.h>

#define N 8

int isSafe(int X, int Y, int sol[N][N]) 
{
 return( X >= 0 && X < N && Y >= 0 && Y < N && sol[X][Y] == -1 );
}

int TravelKT(int sol[N][N], int moveX[8], int moveY[8], int X, int Y, int imove)
{
 int i, nextX, nextY;
 if(imove == N*N)
   return 1;

 for(i = 0; i < 8; i++)
 {
  nextX = X + moveX[i];
  nextY = Y + moveY[i];
  if(isSafe(nextX, nextY, sol))
  {
   sol[nextX][nextY] = imove;
   if(TravelKT(sol, moveX, moveY, nextX, nextY, imove + 1) == 1)
    return 1;
   else sol[nextX][nextY] = -1;
  }
  
 }
 return 0;
}

void showSol(int sol[N][N])
{
 int i, j ;
 for(i = 0; i < N; i++)
 {
  for (j = 0; j < N; j++)
     printf("  %2d", sol[i][j]);
  printf("\n");
 }
}

void main()
{
 int i, j;
 int sol[N][N];

 int moveX[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
 int moveY[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
 
 for(i = 0; i < N ; i++ )
  for (j = 0; j < N; j++ )
    sol[i][j] = -1;

 sol[0][0] = 0;
 if( TravelKT(sol, moveX, moveY, 0, 0, 1) != 1)
    printf("No possible solution. \n");
 else
    showSol(sol);
}
