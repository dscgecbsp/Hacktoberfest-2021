#include <stdio.h>
void readArr(int[],int);
int linSearch(int[],int,int);
void main()
{
    int A[20],n,key,i,x;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    readArr(A,n);
    printf("Enter the element to search: ");
    scanf("%d",&key);
    x=linSearch(A,n,key);
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
int linSearch(int A[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i]==key)
            return i;
    }
    return -1;
}
