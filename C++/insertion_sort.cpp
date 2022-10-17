#include<iostream>
 
using namespace std;

void insertionSort(int a[],int n){
    for(int i=1;i<n;++i){
        int current=a[i];
        int j;
        for(j=i-1;j>=0;--j){
            if(current<a[j])
                a[j+1]=a[j];
            else
             break;   
        }
        a[j+1]=current;
    }
}

void input(int a[],int n){
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
}

void output(int a[],int n){
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
}

int main(){
   int a[100];
   int n;
   cin>>n;
   input(a,n);              //input array
   insertionSort(a,n);      //calling insertionSort
   output(a,n);             //ouput array
    return 0;
}