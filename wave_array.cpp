#include<iostream>
 
using namespace std;

/*
Wave array

Input     3 4
        1  2  3  4
        5  6  7  8
        9  10 11 12

Output : 1 5 9 10 6 2 3 7 11 12 8 4

*/


void waveArray(int a[][100],int m,int n){
    for(int j=0;j<n;++j){
        if(j%2==0){
            for(int i=0;i<m;++i){
                cout<<a[i][j]<<" ";
            }
        }else{
             for(int i=m-1;i>=0;--i){
                cout<<a[i][j]<<" ";
            }
        }
    }
}

int main(){
    int a[100][100];
    int n,m;
    cin>>m>>n;

    //input array
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }

    waveArray(a,m,n);
    return 0;
}