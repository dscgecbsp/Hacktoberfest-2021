/*
Replace O's with X's 

Medium Accuracy: 47.02% Submissions: 1868 Points: 4
Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. 
Your Task:
You do not need to read input or print anything. Your task is to complete the function fill() which takes n, m and mat as input parameters ad returns a
2D array representing the resultant matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 = n, m = 500
*/

#include<bits/stdc++.h>
using namespace std;
bool it(char a[21][21],int n,int m,int i,int j,bool vis[21][21])
{
    if(i<0 || i>=n || j<0 || j>=m)
     return 0;
     if(a[i][j]=='X') return 1;
     if(vis[i][j]==1) return 1;
     if(vis[i][j]==0 && a[i][j]=='O')
      vis[i][j]=1;
    bool l=it(a,n,m,i,j-1,vis);
    bool r=it(a,n,m,i,j+1,vis);
    bool u=it(a,n,m,i+1,j,vis);
    bool d=it(a,n,m,i-1,j,vis);
    return l&&r&&u&&d;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	  int n,m;
	  cin>>n>>m;
	  char a[21][21];
	  for(int i=0;i<n;i++)
	  {
	      for(int j=0;j<m;j++)
	      {
	         cin>>a[i][j]; 
	      }
	  }
	  for(int i=0;i<n;i++)
	  {
	      for(int j=0;j<m;j++)
	      {
	         if(a[i][j]=='O')
	         {
	              bool vis[21][21]={};
	             if(it(a,n,m,i,j,vis))
	            {
	              a[i][j]='X';
	            }
	         }
	      }
	  }
	   for(int i=0;i<n;i++)
	  {
	      for(int j=0;j<m;j++)
	      {
	         cout<<a[i][j]<<" "; 
        }
	  }
	   cout<<endl;
	}
	return 0;
}
