#include <stdio.h>
#define N 5

void FlipBits(unsigned int Array[N])
{
    for(int i = 0; i < N; i++) {
        Array[i] = ~Array[i];
    }
}
int main()
{
    unsigned int Array[N] = {0,1,2,3,4};
    for(int i = 0 ; i < N; i++)
        printf(" %u, ", Array[i]);
    printf("\n");
    FlipBits(Array);
    for(int i = 0 ; i < N; i++)
        printf(" %u, ", Array[i]);
    printf("\n");
}