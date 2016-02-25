#include <stdio.h>

#define N 1000
static int counter = 2;

int isLucky(int n)
{
    int next;
    next = n;
    if(counter > n )
        return 1;
    if(next % counter == 0)
        return 0;
    next = next - (next / counter);
    counter++;
    return isLucky(next);
}

int isItLucky(int n)
{
  static int counter = 2;
 
  /*variable next_position is just for readability of
     the program we can remove it and use n only */
  int next_position = n;
  if(counter > n)
    return 1;
  if(n%counter == 0)
    return 0;      
 
 /*calculate next position of input no*/
  next_position -= next_position/counter;
   
  counter++;
  return isItLucky(next_position);
}

int main()
{
    int i;
    for( i = 3; i < N; i++) {
        counter = 2;
        if(isLucky(i)) {
            printf("%d, ", i);
        }
    }
    printf("\n");
}