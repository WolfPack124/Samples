#include <stdio.h>
#define N 11

int main()
{
    int Array[N] = {1,2,9,3,4,5,2,4,3,1,9};
    int result = 0;
    for(int i = 0; i < N; i++)
        result ^= Array[i];
    printf("the lone number is %d \n", result);
}