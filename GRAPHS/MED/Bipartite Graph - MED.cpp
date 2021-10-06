/*Bipartite Graph 

Medium Accuracy: 40.1% Submissions: 43360 Points: 4
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of graph and returns a boolean value true if graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V)
Expected Space Complexity: O(V)

Constraints:
1 = V, E = 105 */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool is2Colorable(int s, vector<int> adj[], int colored[]){
    queue<int> q;
    q.push(s);
    colored[s] = 0;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        for(int u : adj[v]){
           // if(u == v) return false;
            if(colored[u] == -1){
                colored[u] = 1 - colored[v];
                q.push(u);
            }
            else if(colored[u] == colored[v])
                return false;
        }
    }
    return true;
}

bool isBipartite(int v, vector<int> adj[]){
    int colored[v];
    fill(colored, colored+v, -1);
    
    for(int i=0; i<v; i++)
        if(colored[i] == -1)
            if(!is2Colorable(i, adj, colored))
                return false;
   return true;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
