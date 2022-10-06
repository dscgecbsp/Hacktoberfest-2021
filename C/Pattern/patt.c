#include<stdio.h>

#define N 5

int main(){


        int i,j,k,l;
        for (i = 1; i <=N; i++)
    {
    for (k= N; k >i; k--)
        printf(" ");
          for ( j = 1; j <= i; j++)
          printf("%d",j);
             for ( l = j-2; l > 0; l--)
               printf("%d",l);
               printf("\n");
    }
    


return 0;
    
}