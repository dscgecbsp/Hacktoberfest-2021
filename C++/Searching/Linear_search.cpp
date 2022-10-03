/*
Problem statement: Search a element in a given array
Input:
5
2 3 1 4 6
1
Output:
Element found at index: 2

*/

// Linear Search in C++

#include <iostream>
using namespace std;

int search(int array[], int n, int x) {

  // Going through array sequencially
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
  int n;
  cin>>n;
  int array[n];
  for(int i =0;i<n;i++){
    cin>>array[i];
  }
  cout<<"Enter Element to search\n";
  int x;
  cin>>x;
  int result = search(array, n, x);

  (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result; // it will tell whether the element is found or not
}
