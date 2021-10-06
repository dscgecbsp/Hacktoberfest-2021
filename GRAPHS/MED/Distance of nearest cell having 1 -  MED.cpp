/*
Distance of nearest cell having 1 

Medium Accuracy: 52.71% Submissions: 9850 Points: 4
Given a binary grid. Find the distance of nearest 1 in the grid for each cell.

The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row 
number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.
 

Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes grid as input parameter and returns a matrix of 
same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(1)
 

Constraints:
1 = n, m = 500
*/

#include<bits/stdc++.h>
using namespace std;

int xMove[] = {0,0,1,-1};
int yMove[] = {-1,1,0,0};

bool isSafe(int x, int y, int n, int m){
    if(x>=0 && y>=0 && x<n && y<m)
        return true;
    return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int i,n,m,j;
	    cin>>n>>m;
	    queue<pair<pair<int,int>,int>>q;
	    int arr[n][m];
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            cin>>arr[i][j];
	            if(arr[i][j])
	                q.push({{i,j},0});
	        }
	    }
	    int dp[n][m];
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            dp[i][j]=-1;
	            if(arr[i][j]==1)
	                dp[i][j]=0;
	        }
	    }
	    while(!q.empty()){
	        pair<pair<int,int>,int>p = q.front();
	        q.pop();
	        int x = p.first.first;
	        int y = p.first.second;
	        int d = p.second;
	        for(i=0;i<4;i++){
	            int X = x+xMove[i];
	            int Y = y+yMove[i];
	            if(isSafe(X,Y,n,m) && dp[X][Y]==-1){
	                dp[X][Y] = d+1;
	                q.push({{X,Y},d+1});
	            }
	        }
	    }
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            cout<<dp[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
