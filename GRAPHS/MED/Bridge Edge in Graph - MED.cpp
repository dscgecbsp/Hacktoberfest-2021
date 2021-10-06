/*
Bridge Edge in Graph 

Medium Accuracy: 45.82% Submissions: 12648 Points: 4
Given an undirected graph of V vertices and E edges and another edge (c-d), the task is to find if the given edge is a bridge in graph, i.e., 
removing the edge disconnects the graph.

 

Example 1:

Input:

c = 1, d = 2
Output:
1
Explanation:
From the graph, we can clearly see that
removing the edge 1-2 will result in 
disconnection of the graph. So, it is 
a bridge Edge and thus the Output 1.

Example 2:

Input:

c = 0, d = 2
Output:
0
Explanation:

Removing the edge between nodes 0 and 2
won't affect the connectivity of the graph.
So, it's not a Bridge Edge. All the Bridge
Edges in the graph are marked with a blue
line in the above image.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function isBridge()  which takes number of vertices V, the number of 
edges E, an adjacency lsit adj and two integers c and d denoting the edge as input parameters and returns 1 if the given edge c-d is a Bridge. Else, 
it returns 0.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 = V,E = 105
0 = c, d = V-1
*/


#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(vector<int> adj[],vector<bool>&vis,int c){
        vis[c]=true;
        for(auto i:adj[c])
         if(!vis[i])
          dfs(adj,vis,i);
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        for (int i = 0; i < adj[c].size(); i++) {
if (adj[c][i] == d)
{
adj[c].erase(adj[c].begin() + i);
break;
}}
for (int i = 0; i < adj[d].size(); i++) {
if (adj[d][i] == c)
{
adj[d].erase(adj[d].begin() + i);
break;
}
}

        vector<bool>vis(V,false);
        dfs(adj,vis,c);
        if(!vis[d])
         return true;
         return false;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
