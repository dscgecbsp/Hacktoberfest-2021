#include<stdio.h>
int func1(int arr[]);

int main(){

    int i,n,small ,arr[10]={2,3,45,44,33,2,4};
    
    small= func1(&arr[0]);
    printf("The No. Is= %d",small);
return 0;

}
int func1(int arr[10])
{
    
    int sum,i=arr[3];
    sum=i+3;
    return sum;
}