/* The Dutch National Flag problem :- The Dutch national flag (DNF) problem is one of the most popular programming problems proposed by Edsger Dijkstra. The flag of the 
Netherlands consists of three colors: white, red, and blue. The task is to randomly arrange balls of white, red, and blue such that balls of the same color are placed together. 
Consider this problem on an array; the task is to sort arrays of 0, 1, and 2 in linear time without any extra space. Since the array is only traversed once, the time complexity 
of the algorithm given below is O(n).*/

//C++ program to sort an array with elements 0, 1 and 2 only.

#include <iostream>
using namespace std;

// Function to swap array elements 
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to sort the input array, the array is assumed to have values in {0, 1, 2} 
void DNF(int A[],int n)
{
    int low,mid,high=n-1;
    low=mid=0;
    while(mid<=high)
    {
        if(A[mid]==0)
        {
            swap(A[low],A[mid]);
            low++;
            mid++;
        }
        else if(A[mid]==1)
        {
            mid++;
        }
        else 
        {
            swap(A[mid],A[high]);
            high--;
        }
    }
}

// Driver Code 
int main()
{
    int n;
    cout<<"ENTER SIZE OF ARRAY : ";
    cin>>n;
    int A[n];
    cout<<"ENTER ARRAY ELEMENTS : ";
  
  //inserting array elemnts from the user:-
    for(int i=0;i<n;i++)
    cin>>A[i];
    DNF(A,n);
  
  // Iterate and print every element
    cout<<"ARARY AFTER SORTING : ";
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
}
