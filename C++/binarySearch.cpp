#include <iostream>
using namespace std;

int binarySearch(int *, int, int, int);

int main()
{
    int n; // size of array
    cin >> n;
    int arr[n]; // array declaration

    for (int i = 0; i < n; i++) // input array elements
        cin >> arr[i];

    int key; // element we want to find
    cin >> key;

    cout << binarySearch(arr, 0, n - 1, key);

    return 0;
}

int binarySearch(int *arr, int low, int high, int key)
{
    if (low > high)
        return -1; // key not found

    int mid = low + (high - low) / 2; // calculating the mid index

    if (arr[mid] == key)
        return mid; // element found

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    return binarySearch(arr, mid + 1, high, key); // if (key > arr[mid])
}
