#include<stdio.h>

int main(){

    int i,j,n;

    printf("\n Enter The Number: ");
    scanf("%d",&n);

    for ( i = 1; i <=n; i++)
    {
        printf("\n");
        for ( j = 1; j <=i; j++){
            printf("%d",i);
            printf("  ");
        }
        
    }

return 0;
    
}