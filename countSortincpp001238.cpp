#include <iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;

int maximum(int arr[], int n){
    int max=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max<arr[i])
        {
            max= arr[i];
        }
        
    }
    return max;
    
}

void CountSort(int arr[], int n){
    int i,j;
    // find the maximum element in arr
    int max= maximum(arr,n);
    //create the count array
    int * count = (int *)malloc((max+1) *sizeof(int));
    // initilize the arr element to zero
    for (i = 0; i < max+1; i++)
    {
        count[i]= 0;

    }

    // increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[arr[i]]= count[arr[i]]+1;

    }
    
    i=0; // counter for count array
    j=0; // counter for given array

    while(i<=max){
        if (count[i]>0)
        {
            arr[j]= i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++; 
        }
        

    }

}


int main()
{

    int n;
    cout << "Enter the no of array you want:- ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element of  array :- ";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "your array is :- " << arr[i] << endl; // printing the array before sorting
    }

    CountSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << "You countsort array is :- " << arr[i] << endl; // printing the array before sorting
    }

    return 0;
}