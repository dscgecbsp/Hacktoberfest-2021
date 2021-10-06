/*X Total Shapes 

Medium Accuracy: 67.11% Submissions: 8209 Points: 4
Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
Note: 'X' shape consists of one or more adjacent X's (diagonals not included).
 

Example 1:

Input: grid = {{X,O,X},{O,X,O},{X,X,X}}
Output: 3
Explanation: 
The grid is-
X O X
O X O
X X X
So, X with same colour are adjacent to each 
other vertically for horizontally (diagonals 
not included). So, there are 3 different groups 
in the given grid.

Example 2:

Input: grid = {{X,X},{X,X}}
Output: 1
Expanation: 
The grid is- 
X X
X X
So, X with same colour are adjacent to each
other vertically for horizontally (diagonals
not included). So, there is only 1 group
in the given grid.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function xShape() which takes grid as input parameter and returns the count of
total X shapes.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 

Constraints:
1 = n, m = 100 */


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void find(vector<vector<char>>& grid,int i,int j,int n,int m){
        if(i<0||i>=n||j<0||j>=m||grid[i][j]=='O')
         return;
        grid[i][j]='O';
        find(grid,i-1,j,n,m);
         find(grid,i,j-1,n,m);
          find(grid,i+1,j,n,m);
           find(grid,i,j+1,n,m);
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n=grid.size(),m=grid[0].size();
       
        
        int c=0;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         {
             if(grid[i][j]=='X'){
                 find(grid,i,j,n,m);
                 c++;
             }
         }
         return c;
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
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
