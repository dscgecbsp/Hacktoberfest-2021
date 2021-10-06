/*
Strongly connected component (Tarjans's Algo) 

Hard Accuracy: 37.13% Submissions: 5886 Points: 8
Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.


Example 1:

Input:

Output:
0 1 2,3,4,
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph as mentioned
in the Output.
Example 2:

Input:

Output:
0 1 2,
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC as shown.

Your Task:
You don't need to read input or print anything. Your task is to complete the function tarjans() which takes the number of vertices V and adjacency list of the graph as input parameters and returns a list of list of integers denoting the members of strongly connected components in the given graph.
Note: A single strongly connected component must be represented in the form of a list if integers sorted in the ascending order. The resulting list should consist of a list of all SCCs which must be sorted in a way such that a lexicographically smaller list of integers appears first.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
1 = V  = 105
1 = E  = 105
0 = u, v = N-1
*/

// { Driver Code Starts.

#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    
      //  Driver Code Ends
    void dfs1(vector<int> adj[],stack<int>&s,vector<bool> &vis,int st){
        vis[st]=true;
        for(auto i:adj[st])
         if(!vis[i])
          dfs1(adj,s,vis,i);
        s.push(st);
    }
    void dfs(vector<int> rev[],vector<bool> &vis,int s,vector<int>&v){
        vis[s]=true;
        v.push_back(s);
        for(auto i:rev[s])
         if(!vis[i])
          dfs(rev,vis,i,v);
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        stack<int>s;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++)
         if(!vis[i])
          dfs1(adj,s,vis,i);
        vector<int>rev[V];
        for(int i=0;i<V;i++){
            for(auto u:adj[i])
             rev[u].push_back(i);
        }
        int c=0;
        vector<vector<int>>v;
        for(int i=0;i<V;i++)
         vis[i]=false;
        while(!s.empty()){
            int u=s.top();
            s.pop();
            vector<int>v1;
            if(!vis[u]){
                 dfs(rev,vis,u,v1);
                 sort(v1.begin(),v1.end());
                v.push_back(v1);
               
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
