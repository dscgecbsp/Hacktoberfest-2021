/*COVID19 

Easy Accuracy: 68.87% Submissions: 908 Points: 2
Given the N*M binary matrix, 1 represents the healthy person, and 0 represents a patient affected by a coronavirus. The task is to check the minimum time required for all persons to get affected. A patient at [i, j] cell affects a person at cell [i, j-1], [i, j+1] [i+1, j] and [i-1, j] in one second.

Note: There will be at least one patient

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains two space-separated integers N and M.
3. Next N lines contain M space-separated binary integers.


Output: For each test case, print the minimum time required to all persons affected by COVID19

Constraints:
1. 1 <= T <= 100
2. 1 <= N, M <= 100
3. 0 <= mat[i][j] <= 1


Example:
Input:
2
2 2
1 0
1 0
3 3
1 1 1
1 0 1
1 1 1

Output:
1
2

Explanation:
Test Case 2: After first second matrix will look like {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}. After two seconds matrix will look like {{0, 0, 0},
{0, 0, 0}, {0, 0, 0}}.*/
 

//DRIVER CODE
#include<bits/stdc++.h>
using namespace std;
struct Node{
        int t;
        int r,c;
    };

//YOUR CODE
int helpaterp(vector<vector<int>>&grid)
{
        //code here
        queue<Node*>q;
        Node* node;
        int n=grid.size(),m=grid[0].size(),count;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(grid[i][j]==0){
           node=new Node();
           node->t=0;
           node->r=i;
           node->c=j;
           q.push(node);}
        while(!q.empty()){
            Node* a=q.front();
            q.pop();
            int i=a->r,j=a->c,ti=a->t;
            count=ti;
            if(0<=(i+1) && (i+1)<n && grid[i+1][j]==1)
             {
             grid[i+1][j]=0;
             node=new Node();
             node->t=ti+1;
             node->r=i+1;
             node->c=j;
             q.push(node);}
              if(0<=(j+1) && (j+1)<m && grid[i][j+1]==1)
             {
             grid[i][j+1]=0;
             node=new Node();
             node->t=ti+1;
             node->r=i;
             node->c=j+1;
             q.push(node);}
              if(0<=(i-1) && (i-1)<n && grid[i-1][j]==1)
             {
             grid[i-1][j]=0;
             node=new Node();
             node->t=ti+1;
             node->r=i-1;
             node->c=j;
             q.push(node);}
              if(0<=(j-1) && (j-1)<m && grid[i][j-1]==1)
             {
             grid[i][j-1]=0;
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
    
//DRIVER CODE
int main() {
	//code
	int t,a;cin>>t;
	while(t--){
	int n,m;cin>>n>>m;
	vector<vector<int>>grid;
	for(int i=0;i<n;i++){
	     vector<int>temp;
	 for(int j=0;j<m;j++){
	     cin>>a;
	  temp.push_back(a);
	 }
	    grid.push_back(temp);
	}
	 cout<<helpaterp(grid)<<endl;}
	return 0;
}


