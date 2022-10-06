#include<stdio.h>

int main(){

    int n,i,arr[10];
    printf("Enter The No Of Elements: ");
    scanf("%d",&n);
    
    for ( i = 0; i < n; i++)
    {
        printf("Enter arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    
    i=0;
     printf("The Array Elements Are: \n");
    for ( i = 0; i < n; i++)
    {
        
        printf("arr[%d]=%d \n",i,arr[i]);
    }

return 0;
    
    }