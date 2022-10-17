/*
Maps-STL | CPP | HackerRank | C++ | https://www.hackerrank.com/challenges/cpp-maps/problem | By- Arwaz Khan

Maps are a part of the C++ STL.
Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    int q,a;cin>>q;string n;
    map<string,int>m;
    for(int i=0;i<q;i++)
    {
        cin>>a>>n;int mrk;
        if(a==1)
        {
            cin>>mrk;m[n]+=mrk;
        }
        else if(a==2)       m.erase(n);
        else        cout<<m[n]<<endl;
    }
    return 0;
}
