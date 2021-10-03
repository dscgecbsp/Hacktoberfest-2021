/*
Bubble sort : Repeated swapping of adjacent elements if they are in wrong order.
Time complexity : O(n^2)
*/

#include<stdio.h>

void sort(int *x,int *y)
{
    int temp;
    temp = *x ;
    *y = *x ;
    *x = temp;
}

int main()
{
    int unsorted[10],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&unsorted[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(unsorted[j]>unsorted[j+1])
                sort(unsorted+j,unsorted+j+1);
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",unsorted[i]);
    }
    return 0;
}