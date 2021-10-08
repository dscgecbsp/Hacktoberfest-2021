/*Unit Area of largest region of 1's 

Medium Accuracy: 49.82% Submissions: 18490 Points: 4
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 

Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.
Example 2:

Input: grid = {{0,1}}
Output: 1
Explanation: The grid is-
0 1
The largest region of 1's is colored in 
orange.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
 

Constraints:
1 = n, m = 500 */

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100][100];
void find(int &c,int i,int j){
    if(i<0 || i>=n || j<0 || j>=m || a[i][j]==0)
     return;
    c++;
    a[i][j]=0;
    find(c,i-1,j-1);
    find(c,i+1,j+1);
    find(c,i,j-1);
    find(c,i,j+1);
    find(c,i-1,j);
    find(c,i+1,j);
    find(c,i+1,j-1);
   find(c,i-1,j+1);
}
int main() {
	//code
	int t;cin>>t;
	while(t--){
	    cin>>n>>m;
	   // int a[n][m];
	    for(int i=0;i<n;i++)
	     for(int j=0;j<m;j++)
	      cin>>a[i][j];
	      vector<int>v;
	    for(int i=0;i<n;i++)
	     for(int j=0;j<m;j++)
	      {
	          if(a[i][j])
	          {
	              int count=0;
	              find(count,i,j);
	              v.push_back(count);
	          }
	      }
	      sort(v.begin(),v.end());
	    cout<<v.back()<<endl;
	}
	return 0;
}
