#include<bits/stdc++.h>
using namespace std;
//problem "Chocolates " on codeforces
//You went to the store, selling n types of chocolates. There are ai chocolates of type i in stock.

//You have unlimited amount of cash (so you are not restricted by any prices) and want to buy as many chocolates as possible. 
//However if you buy xi chocolates of type i (clearly, 0≤xi≤ai), then for all 1≤j<i at least one of the following must hold:

//xj=0 (you bought zero chocolates of type j)
//xj<xi (you bought less chocolates of type j than of type i)
//For example, the array x=[0,0,1,2,10] satisfies the requirement above (assuming that all ai≥xi), while arrays x=[0,1,0], 
//x=[5,5] and x=[3,2] don't.

//Calculate the maximum number of chocolates you can buy.
int main(){
    int n,nc=0;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    long long int r=v[n-1];
    for(int i=n-2;i>=0;i--){
        int t=min(v[i+1]-1,v[i]);
        if(t<0) t=0;
        v[i]=t;
        r+=t;
    }
    cout<<r<<endl;
    return 0;
}