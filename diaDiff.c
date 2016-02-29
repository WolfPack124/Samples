#include <stdio.h>
#define N 4

int findDiff(int Array[N][N])
{
    int i, j, d1 = 0, d2 = 0;
    for(i = 0; i < N; i++){
        d1 = d1 + Array[i][i];
        d2 = d2 + Array[i][N-1-i];
    }
    return (d2-d1);
}

int main()
{
    int Array[N][N] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,0,1},
        {2,3,4,5}};
    int diff = 0;
    diff = findDiff(Array);
    printf("Difference of diagonal sum is %d\n", diff);
}