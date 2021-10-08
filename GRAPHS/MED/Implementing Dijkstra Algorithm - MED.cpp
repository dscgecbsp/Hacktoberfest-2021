/*Implementing Dijkstra Algorithm 

Medium Accuracy: 49.0% Submissions: 41693 Points: 4
Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

Example 1:

Input:

S = 0
Output:
0 9
Explanation:
Shortest distance of all nodes from
source is printed.
Example 2:

Input:

S = 2
Output:
4 3 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The other distances are pretty straight-forward.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes number of vertices V and an adjacency list adj as input parameters and returns a list of integers, where ith integer denotes the shortest distance of the ith node from Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the weight between edge i and j is w.

 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

 

Constraints:
1 = V = 1000
0 = adj[i][j] = 1000
0 = S < V */

#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );


int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // Your code here
    set<pair<int,int> > s;
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=10001;
    }
    s.insert(make_pair(0,src));
    dist[src]=0;
    while(!s.empty()){
        
        auto p=*(s.begin());
        
        int node=p.second;
        int nodedist=p.first;
        
        s.erase(s.begin());
        
        for(int i=0;i<V;i++){
            
            if(graph[node][i]){
                
                if(dist[i]>nodedist+graph[node][i]){
                    
                    auto f=s.find(make_pair(dist[i],i));
                    if(f!=s.end())
                    s.erase(f);
                    dist[i]=nodedist+graph[node][i];
                    s.insert(make_pair(dist[i],i));
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }

}
