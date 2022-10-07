#include <iostream>
using namespace std;

int binarysearch(int n, int arr[], int key)
{
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            r = mid - 1;
        }
        else if (key > arr[mid])
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    cout << binarysearch(n, arr, key);
    return 0;
}