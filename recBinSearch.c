#include <stdio.h>
void readArr(int[],int);
int recBinSearch(int[],int,int,int);
void main()
{
    int A[20],n,key,x;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    readArr(A,n);
    printf("Enter the element to search: ");
    scanf("%d",&key);
    x=recBinSearch(A,0,n-1,key);
    if(x==-1)
        printf("Element not found");
    else
        printf("Element found at position %d",x+1);
}
void readArr(int A[],int n)
{
    int i;
    printf("Enter %d number of elements: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
}
int recBinSearch(int A[],int lwr,int upr,int key)
{
    int mid=(lwr+upr)/2;
    if(lwr>upr)
        return -1;
    else if(A[mid]==key)
        return mid;
    else if(A[mid]>key)
        return recBinSearch(A,lwr,mid-1,key);
    else
        return recBinSearch(A,mid+1,upr,key);
}
