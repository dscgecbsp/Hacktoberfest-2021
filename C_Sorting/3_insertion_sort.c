"""
Insertion sort : Compare a key element with the previous sorted arry
previous sorted array will be in the left side of the key element

Time complexity : O(n^3) (In this case)

We can do the following with 1 for loop and 1 while, instead of 3 nested for loops
For that, we need to compare the elements from right to left (here it is done left to right) wrt key element
Time complexity : O(n^2)
"""

#include<stdio.h>

int main()
{
    int n,arr[15];
    scanf("%d",&n);
    for(int x=0;x<n;x++)
    {
        scanf("%d",&arr[x]);
    }

    int i,j,k;

    for(i=1;i<n;i++)
    {
        int key_element = arr[i];
        // Comparision loop
        for(j=0;j<i;j++)
        {
            if(key_element < arr[j])
            {
                // Moving elements to 1 step right 
                for(k=i-1;k>j-1;k--)
                {
                    arr[k+1] = arr[k];
                }
                arr[j] = key_element;
                break; 
            }
        }
    }
    for(int x=0;x<n;x++)
    {
        printf("%d ",arr[x]);
    }
}