#include <stdio.h>

#define N 10 

int main()
{
    int i = 0;
    for(i = 0; i <= N; i ++)
    {
        printf("%2d x 6 = %2d\n", i, (i << 3) - (i << 1));
    }
}