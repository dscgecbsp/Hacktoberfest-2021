/*Find the Maximum Flow 

Hard Accuracy: 33.34% Submissions: 669 Points: 8
Given a graph with N vertices numbered 1 to N and M edges, The task is to find the max flow from vertex 1 to vertex N.

Example 1:

Input:
N = 5, M =  4
Edges[]= { {1, 2, 1} , {3, 2, 2}, {4, 2, 3}, {2, 5, 5} }
Output:
1 
Explanation: 
1 - 2 - 3
   / \
  4   5 
1 unit can flow from 1 -> 2 - >5 
 

Example 2:

Input:
N = 4 , M = 4
Edges[] = { {1, 2, 8}, {1, 3, 10}, {4, 2, 2}, {3, 4, 3} }
Output:
5 
Explanation:
  1 - 2 
  |   |
  3 - 4
3 unit can flow from 1 -> 3 -> 4
2 unit can flow from 1 -> 2 -> 4
Total max flow from 1 to N = 3+2=5
Your Task: 
You don't need to read input or print anything. Your task is to complete the function solve() which takes the N (the number of vertices) ,M (the number of Edges) and the array Edges[] (Where Edges[i] denoting an undirected edge between Edges[i][0] and Edges[i][1] with a flow capacity of Edges[i][2] ), and returns the integer denoting the maximum flow from 1 to N.

Expected Time Complexity: O( max_flow* M)
Expected Auxiliary Space: O(N+M)

Where max_flow is the maximum flow from 1 to N

Constraints:
1 <= N,M,Edges[i][2] <= 1000
1 <= Edges[i][0],Edges[i][1] <= N */

#include<bits/stdc++.h>
#define endll "\n";
using namespace std;
bool bfs(vector<vector<int>> c,int s,int t,vector<int> &vis,vector<int> &par){
     queue<int> q;
     q.push(s);
     vis[s]=1;
     while(!q.empty()){
         int u=q.front();
         q.pop();
         for(int i=0;i<c.size();i++){
             if(vis[i]==0&&c[u][i]>0){
                 par[i]=u;vis[i]=1;q.push(i);
                 if(i==t){
                     return true;
                 }
             }
         }
     }
     return false;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int e;cin>>e;
        vector<vector<int>> c(n,vector<int> (n,0));
        int u,v,w;
        for(int i=0;i<e;i++){
           cin>>u>>v>>w;
           c[u-1][v-1]+=w;
           c[v-1][u-1]+=w;
        }
        int max_flow=0;
        while(true){
            vector<int> vis(n,0),par(n,-1);
            if(bfs(c,0,n-1,vis,par)==false){
                break;
            }
            int max1=INT_MAX;
            int v=n-1;
            while(par[v]!=-1){
                max1=min(c[par[v]][v],max1);
                v=par[v];
            }
            v=n-1;
            while(par[v]!=-1){
                c[par[v]][v]-=max1;
                c[v][par[v]]+=max1;
                v=par[v];
            }
            max_flow+=max1;
        }
        cout<<max_flow<<endll;
    }
    return 0;
}


