#include<bits/stdc++.h>
using namespace std;

void printSum(int arr[][3], int target ,int row, int col){

    for(int row=0; row<3; row++){
        int sum = 0;
        for(int col=0; col<3; col++){
           sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout<< endl;
}
 
int main(){
 
    int arr[3][3];  
    int a=3;
    cout<<a*2;
 
    return 0;
}