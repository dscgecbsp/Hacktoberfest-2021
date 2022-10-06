#include<stdio.h>

int biggest(int a, int b, int c);

int main(){
     
     int num1,num2,num3,big;

     printf("\n Enter The Three Numbers: ");
     scanf("%d %d %d", &num1, &num2, &num3);

     big = biggest(num1,num2,num3);

     printf("\n The Biggest No. Is: %d",big);



return 0;
  
}

int biggest(int a, int b, int c){
    if(a>b && a>c)
       return a;
    else if (c>a && c>b)
       return c;
    else 
       return b;
}