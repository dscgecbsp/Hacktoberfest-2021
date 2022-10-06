#include<stdio.h>
#include<math.h>

int main(){

    int decimal_num,remainder,binary_num=0;
    int j, i = 0, arr[20];
    
   

   printf("\n Enter The Decimal No: ");
   scanf("%d", &decimal_num);

   while (decimal_num != 0)
   {
    remainder= decimal_num%2;
    scanf("%d", arr[i]);
    decimal_num = decimal_num/2;
    i++;
}


for (int j = i - 1; j >= 0; j--)
        printf("%d", arr[j]);


return 0;

}
   
