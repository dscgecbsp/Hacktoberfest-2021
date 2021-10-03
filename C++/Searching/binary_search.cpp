/*
Problem statement:
We need to search a element and predict if it is present or not using the technique of Binary Search in c++ .
Approach:
1) First we need to sort the array (Must condition) .
2) Set 2 pointers high and low at highest and lowest position.
3) Find 'mid' element if it match with key return it otherwise,
4) If key>mid then do low=mid+1
5) If key<mid then do high = mid-1
7) Repeat it upto you won't get mid element as Key.

Time complexity:
Best Case: O(1)
Average Case: O(log n)
Worst Case: O(log n)
*/

// Binary Search in C++

#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9}; // You can enter your own element.
  int x = 4;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1); // Call function 
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}
