//Program : To sort a given array using an improved version of bubble sort which has a better time complexity.
#include<iostream>
using namespace std;
int main(void){
    int n;
    cout<<"Enter Size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool flag=false; //a flag that is set if an exchange is made after an entire pass over the array
    for(int x=0; x<n; x++)
 {
     flag=false;
    for(int y=0; y<n-1; y++)
    {
        if(arr[y]>arr[y+1])
        {
            swap(arr[y],arr[y+1]);
            flag = true;
        }
    }
    if(!flag){
        break;
        }
    }
    cout<<"Elements in array after sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}