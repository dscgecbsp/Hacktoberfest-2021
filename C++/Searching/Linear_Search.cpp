/*
Problem statement: Search a element in a given array
Input:
6
8 2 1 4 6 9
1
Output:
Element found at index: 2
*/

// Linear Search in C++

#include <iostream>
using namespace std;

int Linear_search(int array[], int n, int x) {

  // traverse the array sequencially
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
  int result = Linear_search(array, n, x);

  (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;
}
