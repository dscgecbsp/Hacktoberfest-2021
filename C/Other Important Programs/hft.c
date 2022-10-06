#include<stdio.h>
#include<math.h>

int main(){

    int decimal_num,remainder,binary_num=0;
    int i = 0;
    
   

   printf("\n Enter The Decimal No: ");
   scanf("%d", &decimal_num);
   

   while (decimal_num != 0)
   {
    remainder= decimal_num%2;
    binary_num += remainder*pow(10,i);
    decimal_num = decimal_num/2;
    i++;
}


printf("\n The Binary Equivalent = %d",binary_num);

return 0;

}
   
