#include <stdio.h>
#define N 4

int findDiff(int Array[N][N])
{
    int i, d = 0;
    for(i = 0; i < N; i++){
        d += Array[i][i];
        d -= Array[i][N-1-i];
    }
    return d;
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