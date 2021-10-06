/*Rotten Oranges 

Medium Accuracy: 50.57% Submissions: 18635 Points: 4
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

Expected Time Compelxity: O(n*m)
Expected Auxiliary Space: O(1)
 

Constraints:
1 = n, m = 500 */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
   
    struct Node{
        int t;
        int r,c;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<Node*>q;
        Node* node;
        int n=grid.size(),m=grid[0].size(),count;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(grid[i][j]==2){
           node=new Node();
           node->t=0;
           node->r=i;
           node->c=j;
           q.push(node);}
        while(!q.empty()){
            Node* a=q.front();
            q.pop();
         //   cout<<a->t;
            int i=a->r,j=a->c,ti=a->t;
            count=ti;
            if(0<=(i+1) && (i+1)<n && grid[i+1][j]==1)
             {
             grid[i+1][j]=2;
             node=new Node();
             node->t=ti+1;
             node->r=i+1;
             node->c=j;
             q.push(node);}
              if(0<=(j+1) && (j+1)<m && grid[i][j+1]==1)
             {
             grid[i][j+1]=2;
             node=new Node();
             node->t=ti+1;
             node->r=i;
             node->c=j+1;
             q.push(node);}
              if(0<=(i-1) && (i-1)<n && grid[i-1][j]==1)
             {
             grid[i-1][j]=2;
             node=new Node();
             node->t=ti+1;
             node->r=i-1;
             node->c=j;
             q.push(node);}
              if(0<=(j-1) && (j-1)<m && grid[i][j-1]==1)
             {
             grid[i][j-1]=2;
             node=new Node();
             node->t=ti+1;
             node->r=i;
             node->c=j-1;
             q.push(node);}
        }
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(grid[i][j]==1){
              return -1;
          }
          return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
