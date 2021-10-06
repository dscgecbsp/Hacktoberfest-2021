/*Find whether path exist 

Medium Accuracy: 51.18% Submissions: 16584 Points: 4
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
 

Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0 
3 0 0 0 3 
3 3 3 3 3 
0 2 3 0 0 
3 0 0 1 3 
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.
Example 2:

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1) 
i,e destination.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function is_Possible() which takes the grid as input parameter and returns boolean value true if there is a path otherwise returns false.
 

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
 

Constraints:
1 = n = 500 */

#include<bits/stdc++.h>
using namespace std;
int DFS(vector<int> A[], int row, int col, int N, vector<int> vis[])
{
    if(A[row][col]==2)
        return 1;
    
    if(row<0 || row>=N || col<0 || col>=N || vis[row][col]==1 || A[row][col] == 0 )
        return 0;
    
    //mark visited
    vis[row][col]=1;
    
    
    //traverse in the 4 directions if A[row][col] == 3
    if( DFS(A, row-1, col, N, vis) ||  DFS(A, row, col-1, N, vis) || DFS(A, row, col+1, N, vis) || DFS(A, row+1, col, N, vis))
        return 1;
        
}
int main()
 {
	//thakur
	int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> v[N];
        vector <int> vis[N];
        
        int start_row, start_col;
        for(int i=0; i<N; i++)
        {
            for(int j = 0; j<N;  j++)
            {
                int x;
                cin>>x;
                v[i].push_back(x);
                vis[i].push_back(0);
                //find the position of source cell
                if(x==1)
                {
                    start_row = i;
                    start_col = j;
                }
            }
        }
        
        int x;
        x = DFS(v, start_row, start_col, N, vis);
        
        cout<<x<<endl;
    }
}
