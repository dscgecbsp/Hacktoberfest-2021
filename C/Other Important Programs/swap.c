#include<stdio.h>
void swap_value(int a,int b);

int main(){

    int num1,num2;

    printf("\n Enter The First No. ");
    scanf("%d", &num1);

    printf("\n Enter The Second No. ");
    scanf("%d", &num2);
    
    printf("\n The Numbers Before Swap Are: num1 = %d  num2 = %d", num1,num2);

    swap_value(num1,num2);

    return 0;

}

void swap_value(int a ,int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("\n The Numbers After Swap Are:  num1 = %d  num2 = %d", a, b);
} 
