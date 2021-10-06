/*Mother Vertex 

Easy Accuracy: 49.76% Submissions: 14160 Points: 2
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
 

Example 1:

Input: 

Output: 0
Explanation: According to the given edges, all nodes can be reaced from nodes from 0, 1 and 2. 
But, since 0 is minimum among 0,1 and 3, so 0 
is the output.

Example 2:

Input: 

Output: -1
Explanation: According to the given edges, 
no vertices are there from where we can 
reach all vertices. So, output is -1.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findMotherVertex() which takes V denoting the number of vertices and adjacency list as imput parameter and returns the verticex from through which we can traverse all other vertices of the graph. If there is more than one possible nodes then returns the node with minimum value.If not possible returns -1.
 
Expected Time Complexity: O(V + E)
Expected Space Compelxity: O(V)
 
Constraints:
1 = V = 500*/

//Initial Template for C++


#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * adj[]: graph representation
 */

void dfs(int src,vector<bool> &vis,vector<int> adj[]){
    vis[src]=true;
    for(int i=0;i<adj[src].size();i++){
        if(vis[adj[src][i]]==false)
            dfs(adj[src][i],vis,adj);
    }
}

int findMother(int n, vector<int> adj[]) 
{ 
    int mother=0;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==false)
            {
            dfs(i,vis,adj);
            mother=i;
            }

    }

    vector<bool> visited(n,false);
        dfs(mother,visited,adj);
        for(int i=0;i<n;i++){
            if(visited[i]==false)
                mother=-1;
        }
    return mother;
} 

// { Driver Code Starts.

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends
