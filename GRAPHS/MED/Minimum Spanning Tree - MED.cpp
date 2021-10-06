/*
Minimum Spanning Tree 

Medium Accuracy: 49.39% Submissions: 31572 Points: 4
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

 

Example 1:

Input:

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the distance between edge i and j is w.
 

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 

Constraints:
2 = V = 1000
V-1 = E = (V*(V-1))/2
1 = w = 1000
Graph is connected and doesn't contain self loops & multiple edges.
*/


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //int dis[V]={INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        p.push(make_pair(0,0));
        vector<bool>mst(V,false);
        vector<int>key(V,INT_MAX);
        key[0]=0;int wt=0;
        while(!p.empty())
        {
            int u=p.top().second;p.pop();
            if(mst[u])
             continue;
            mst[u]=true;
            
             wt+=key[u];
             for(auto j:adj[u]){
                 int a=j[0],b=j[1];
                  if(!mst[a] && (key[a]>b))
             {
                 key[a]=b;
                 p.push(make_pair(key[a],a));
             }
             }
         /*   for(int i=0;i<V;i++)
             if(!mst[i] && (key[i]>adj[u][i]))
             {
                 key[i]=adj[u][i];
                 p.push(make_pair(key[i],i));
             }*/
        }
        return wt;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
