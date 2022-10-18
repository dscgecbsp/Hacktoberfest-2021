#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    // shell sorting 
    for(int gap = n/2; gap>=1; gap = gap/2){
        for(int j = gap; j<n; j++){
            for(int i=j - gap; i>=0; i = i-gap){
                if(v[i+gap]>v[i])
                    break;
                else
                    swap(v[i+gap], v[i]);
            }
        }
    }
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    return 0;
}