#include<stdio.h>
int main(){
    int i,n , arr[13];

    printf("Enter The No. Of Elements: \n");
    scanf("%d", &n);

    printf("Enter The Elements: \n");
    for ( i = 0; i < n; i++)
    {
         scanf("%d", &arr[i]);

    }
    
    for ( i = 0; i < n; i++)
    {
        printf("Array Elements are: \n");
        printf(" arr[%d] = %d \n",i, arr[i]);

    }
    

return 0;

}

