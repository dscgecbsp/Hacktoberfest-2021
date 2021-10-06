/*Geek and City 

Easy Accuracy: 58.66% Submissions: 878 Points: 2
Given N cities, some of them have roads in between them. Geek is in city 1. The task is to find the minimum number of roads needed to construct so that geek can visit any city from any other city.

Note:
1. All the cities are numbered from 1 to N.
2. No two cities have multiple roads.
3. No city has self road

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains two space_separated integers N and M.
3. Next M lines contain two space-separated integers u and v, represents a road between cities u and v


Output: For each test case, print the answer


Constraints:
1. 1 <= T <= 100
2. 1 <= N <= 50
3. 0 <= M <= min(1000, N*(N-1)/2)


Example:
Input:
2
4 2
1 2
3 4
5 5
1 2
2 3
3 4
4 5
5 1

Output:
1
0*/

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[],vector<bool>&vis,int u){
    vis[u]=true;
    for(auto j:adj[u])
     if(!vis[j])
     { 
      dfs(adj,vis,j);}
}
int main() {
	//code
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
	int t;cin>>t;
	while(t--){
	    int n,m,a,b,c=0;
	    cin>>n>>m;
	    vector<int>adj[n];
	    vector<bool>vis(n,false);
	    for(int i=0;i<m;i++)
	     {
	         cin>>a>>b;
	        adj[a-1].push_back(b-1);
	        adj[b-1].push_back(a-1);
	     }
	     for(int i=0;i<n;i++)
	      if(!vis[i])
	       {dfs(adj,vis,i);c++;}
	       cout<<c-1<<endl;
	}
	return 0;
}
