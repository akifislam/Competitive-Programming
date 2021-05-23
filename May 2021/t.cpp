#include <stdio.h>
int main()
{
    int n = 4;
      
    printf("Parity of %d is %d ",
           n, __builtin_parity(n));
    return 0;
}