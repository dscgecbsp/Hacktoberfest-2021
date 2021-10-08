/*
Possible paths between 2 vertices 

Medium Accuracy: 57.48% Submissions: 7694 Points: 4
Given a Directed Graph. Count the total number of ways or paths that exist between two vertices in the directed graph. These paths doesn’t contain any cycle.
Note: Graph doesn't contain multiple edges, self loop and cycles and the two vertices( source and destination) are denoted in the example.


Example 1:

Input:

Output: 4
Explanation: 
There are 4 paths from 0 to 4.
0 -> 4
0 -> 1 -> 4
0 -> 2 -> 4
0 -> 1 -> 3 -> 2 -> 4

Example 2:

Input:

Output: 3
Explanation:
There are 3 paths from 0 to 3.
0 -> 3
0 -> 1 -> 3
0 -> 1 -> 2 -> 3

Your task:
You don’t need to read input or print anything. Your task is to complete the function countPaths() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  the count of  the number of paths in the graph from the source vertex to the destination vertex.


Expected Time Complexity: O(V!)
Expected Auxiliary Space: O(V)


Constraints:
1 = V, E = 100
1 = source, destination = V
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to count paths between two vertices in a directed graph.
void dfs(int s,int &c,int x1,vector<int >adj[])
 {
   //  vis[s]=true;
     if(s==x1)
      c++;
     else
       {
        for(int x:adj[s])
          //if(vis[x]==false)
            dfs(x,c,x1,adj);
            
       }
    //vis[s]=false;   
 }

	int countPaths(int V, vector<int> adj[], int s, int d)
	{
	    // Code here
	    int c=0;
  dfs(s,c,d,adj);
    return c;  
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;
    	vector<int> adj[V];
    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		// adj[v].push_back(u);
    	}
    	int source, destination;
    	cin >> source >> destination;
        Solution obj;
        cout<<obj.countPaths(V, adj,source,destination)<<endl;
	}
	return 0;
}  // } Driver Code Ends
