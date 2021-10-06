/*
Strongly Connected Components (Kosaraju's Algo) 

Medium Accuracy: 49.73% Submissions: 29359 Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
 

Constraints:
1 = V = 5000
0 = E = (V*(V-1))
0 = u, v = N-1
Sum of E over all testcases will not exceed 25*106
*/


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs1(vector<int> adj[],stack<int>&s,vector<bool> &vis,int st){
        vis[st]=true;
        for(auto i:adj[st])
         if(!vis[i])
          dfs1(adj,s,vis,i);
        s.push(st);
    }
    void dfs(vector<int> rev[],vector<bool> &vis,int s){
        vis[s]=true;
        for(auto i:rev[s])
         if(!vis[i])
          dfs(rev,vis,i);
       // s.push(s);
    }
    int kosaraju(int V, vector<int> adj[])
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
        //fill(vis.begin(),vis.end(),false);
        for(int i=0;i<V;i++)
         vis[i]=false;
        while(!s.empty()){
            int u=s.top();
            s.pop();
            if(!vis[u]){
                dfs(rev,vis,u);
                c++;
            }
        }
        return c;
        
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
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
