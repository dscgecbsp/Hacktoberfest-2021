#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    bool flag = true;  // Initialize flag to true
    
    for (int x = 0; x < n && flag; x++) {  // Update loop condition
        flag = false;  // Reset flag for this iteration
        for (int y = 0; y < n - 1; y++) {
            if (arr[y] > arr[y + 1]) {
                swap(arr[y], arr[y + 1]);
                flag = true;  // Set flag if a swap occurs
            }
        }
    }
    
    cout << "Elements in array after sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
