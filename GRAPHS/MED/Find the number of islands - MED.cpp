/*
Find the number of islands 

Medium Accuracy: 38.66% Submissions: 80379 Points: 4
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes grid as input parameter and returns the total number of islands.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 

Constraints:
1 = n, m = 500
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
        if(i<0||j<0||i>=n||j>=m||grid[i][j]=='0')
         return;
        grid[i][j]='0';
        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i-1,j-1,n,m);
        dfs(grid,i+1,j+1,n,m);
        dfs(grid,i-1,j+1,n,m);
        dfs(grid,i+1,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         {
             if(grid[i][j]=='1')
              {ans++;
                  dfs(grid,i,j,n,m);
              }
         }
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
