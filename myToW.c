#include <stdio.h>

#define N 10

void displayList(int Array[N], int from, int to) 
{
    int i;
    for(i = from; i < to; i++) {
        printf(" %d ", Array[i]);
    }
    printf("\n");
}

void Swap(int Array[N], int x, int y)
{
    int temp = Array[x];
    Array[x] = Array[y];
    Array[y] = temp;
}

int ToW(int Array[N], int L1, int L2, int Sum1, int Sum2)
{
    int i = 0, high = L1;
    
    if(L1 == L2) {
        printf("Sum of lists are %d and %d and difference of List is %d\n", Sum1, Sum2, (Sum1-Sum2) > 0 ?Sum1-Sum2:Sum2-Sum1);
        return L2;
    }
    for(i = L1; i <= L2; i++) {
        if(Array[i] > Array[high]) {
            high = i;
        }
    }
    if(Sum1 < Sum2) {
        Sum1 = Sum1 + Array[high];
        Swap(Array, L1, high);
        ToW(Array, L1+1, L2, Sum1, Sum2);
        
    } else {
        Sum2 = Sum2 + Array[high];
        Swap(Array, L2, high);
        ToW(Array, L1, L2-1, Sum1, Sum2);
    }
}

int main()
{
    int mid = 0;
    int Array[] = {0,1,2,3,4,1,6,1,8,1,100};
    //int Array[] = {0,2,2,3,4,1,11,1};
    printf("Initial list is : ");
    displayList(Array, 0, N);
    mid = ToW(Array, 0, N-1, 0, 0);
    printf("List one is : ");
    displayList(Array, 0, mid);
    printf("List Two is : ");
    displayList(Array, mid, N);
}