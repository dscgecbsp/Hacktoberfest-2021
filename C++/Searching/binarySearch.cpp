#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int sorted_array[], int left, int right, int element) 
{ 
     while (left <= right) 
    { 
        int middle = (left + right) / 2; 
        // Check if element is present at middle position or not 
        if (sorted_array[middle] == element) 
            return middle; 
        // If element is greater, ignore left half 
        if (sorted_array[middle] < element) 
            left = middle + 1; 
        // If element is smaller, ignore right half 
        else
            right = middle - 1; 
    } 
    // if element is not present then return -1 
    return -1; 
}
int main()
{
    int a[] = { 10, 12, 20, 32, 50, 55, 65, 66, 99 };
    int element = 66;
    int size = sizeof(a) / sizeof(a[0]); 
    sort(a, a + size);
    int result = BinarySearch(a, 0, size - 1, element); 
    if(result == -1)
        cout<<"Element is not present in array";
    else
        cout<<"Element is present at index "<< result;
    return 0;
}