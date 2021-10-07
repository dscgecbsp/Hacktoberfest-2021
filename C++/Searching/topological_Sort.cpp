//This is a C++ Program to find topological sort int a Directed Graph using DFS.
#include <bits/stdc++.h>
using namespace std;
stack<int> s;
void TopoSortDFS(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            TopoSortDFS(it, vis, adj);
        }
    }
    s.push(node);
}
vector<int> TopoSort(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            TopoSortDFS(i, vis, adj);
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int top = s.top();
        s.pop();
        ans[i] = top;
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> res = TopoSort(n, adj);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}
