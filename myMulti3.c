#include <stdlib.h>
#include <stdio.h>

int isMultipleOf3(int num)
{
    int OddCount = 0, EvenCount = 0;
    if (num == 0)
        return 1;
    if (num == 1)
        return 0;
    if( num < 0)
        num = -num;
    
    while(num) {
        if(num & 1) {
            OddCount++;
        }
        num = num>>1;
        if(num & 1) {
            EvenCount++;
        }
        num = num>>1;
    }
    
    return isMultipleOf3(OddCount- EvenCount);
}

int main()
{
    int x;
    printf("Enter a number to check :");
    scanf(" %d", &x);
    if(isMultipleOf3(x)) {
        printf("%d is multiple of 3\n", x);
    } else {
        printf("%d is not multiple of 3\n", x);
    }
}