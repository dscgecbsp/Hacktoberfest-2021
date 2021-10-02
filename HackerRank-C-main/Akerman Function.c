#include <stdio.h>
#include <stdlib.h>

float akerman(int m, int n);
int main() {
    int x,y;
    float z;
    //Asking value for Akerman function
    printf("Let A(x,y) be an Akerman Function");
    printf("\nEnter Value of x :");
    scanf("%d",&x);
    printf("Enter Value of y :");
    scanf("%d",&y);
    //function is called
    z = akerman(x,y);
    //final result display
    if (z<0)
        printf("Akerman Function is not applicable");
    else
        printf("\nAnswer = %.2f", z);
    return 0;
}

//Akerman function

float akerman(int m, int n) {
    if (m==0)
    {
         return n+1;
    }
    else if (m>0 && n==0)
        return akerman(m-1,1);
    else if(m>0 && n>0)
        return akerman(m-1,akerman(m,n-1));
    else
        return -1;
}
