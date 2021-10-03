/*
Selection sort. Compare each element and put the smallest element in the first.
Repeat the above.
Time complexity O(n^2)
*/

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

    for(i=0;i<n;i++)
    {
        int smallest = arr[i];
        int smallest_number_index = i;

        // Finding the smallest from i+1 till end
        for(j=i+1;j<n;j++)
        {
            if(arr[j] < smallest)
            {
                smallest = arr[j];
                smallest_number_index = j;
            }
        }

        // Moving all element from i till 'smallest' to 1 step right 
        // Making place for the 'smallest' to fit in
        // Or we can swap 2 elements(it is faster)
        for(k=smallest_number_index-1;k>i-1;k--)
        {
            arr[k+1] = arr[k];
        }

        // 'smallest' is assigned its new place
        arr[i] = smallest;
    }

    for(int x=0;x<n;x++)
    {
        printf("%d ",arr[x]);
    }
    
}