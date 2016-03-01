#include <stdio.h>

# define N 9

int main()
{
    float p = 0, n = 0, z = 0;
    int Array[N] = {1,-2,-3,-4,5,6,8,9,0};
    for (int i = 0; i < N; i++) {
        if((Array[i] == 0) ? z++ : ((Array[i] > 0) ? p++ : n++));
    }
    printf("Fraction of positives is %.3f, negative is %.3f and zero is %.3f \n", p/N, n/N, z/N);
}