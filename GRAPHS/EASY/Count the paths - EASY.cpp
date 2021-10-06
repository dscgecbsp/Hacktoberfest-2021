/*Count the paths 

Easy Accuracy: 71.04% Submissions: 3622 Points: 2
Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. Given edges, s and d ,count the number of ways to reach from s to d.There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1].


Example:

Input: edges = {{0,1},{0,3},{1,2},{3,2}}, 
n = 4, s = 0, d = 2
Output: 2
Explanation: There are two ways to reach at 
2 from 0. These are-
1. 0->1->2
2. 0->3->2
 

Your Task:
You don't need to read or print anything. Your task is to complete the function possible_paths() which takes edges, n, s and d as input parameter and returns the number of ways to reach from s to d.

 

Expected Time Compelxity: O(2n)
Expected Space Complexity: O(n+e)

where e is the number of edges in the graph.
 

Constraints:
1 <= n <= 15
0 <= s, d <= n-1*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int count_dfs(vector<int>adj[], int u, int d, vector<bool>&vis){
if(u == d)
return 1;
vis[u] = true;
int ans = 0;
for(auto v: adj[u]){
if(!vis[v])
ans += count_dfs(adj, v, d, vis);
}
vis[u] = false;
return ans;
}
int possible_paths(vector<vector<int>>edges, int n, int s, int d){
vector<int> adj[n];
for(auto i:edges)
adj[i[0]].push_back(i[1]);
vector<bool>vis(n, false);
return count_dfs(adj, s, d, vis);
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
