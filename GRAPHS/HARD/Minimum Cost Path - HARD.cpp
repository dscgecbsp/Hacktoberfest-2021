/*
Minimum Cost Path 

Hard Accuracy: 50.09% Submissions: 12853 Points: 8
Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 

Note: It is assumed that negative cost cycles do not exist in the input matrix.
 

Example 1:

Input: grid = {{9,4,9,9},{6,7,6,4},
{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Example 2:

Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function minimumCostPath() which takes grid as input parameter and returns the minimum cost to react at bottom right cell from top left cell.
 

Expected Time Compelxity: O(n2*log(n))
Expected Auxiliary Space: O(n2) 
 

Constraints:
1 = n = 500
1 = cost of cells = 1000
*/


#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > vec_vec;
typedef vector<int> vec;
typedef pair<int,int> ipair;
void print(vec_vec v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
bool is_safe(vec_vec &mat,int i,int j)
{
    int n=mat.size();
    if(i<0 || j<0 || i>=n || j>=n)
        return false;
    return true;
}
int dijkstra(vec_vec &mat)
{
    int n=mat.size(),min_cost=INT_MAX,p,q;
    //moves allowed botom,up,left,right
    int x[]= {0,-1,0,1};
    int y[]= {-1,0,1,0};
    vec_vec dist(n,vec(n,INT_MAX));
    dist[0][0]=mat[0][0];
    priority_queue<pair<int,ipair>,vector<pair<int,ipair>>,greater<pair<int,ipair> > > pq;
    pq.push({mat[0][0],{0,0}}); //{w,{u,v}}
    while(!pq.empty())
    {
        int w=pq.top().first;
        int u=pq.top().second.first;
        int v=pq.top().second.second;
      pq.pop();

        for(int k=0; k<4; k++)
        {
            p=u+x[k];
            q=v+y[k];

  if(is_safe(mat,p,q) && mat[p][q]+w<dist[p][q])
            {
                dist[p][q]=mat[p][q]+w;
                pq.push({dist[p][q],{p,q}});
            }
        }

    }
return dist[n-1][n-1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vec_vec V(n,vec(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>V[i][j];
        }
        int mn_cost=dijkstra(V);
        cout<<mn_cost<<endl;
    }
}


