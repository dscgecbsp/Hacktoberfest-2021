/*
Knight Walk 

Medium Accuracy: 70.73% Submissions: 2597 Points: 4
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
 

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of 
Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum 
number of steps required by the knight to reach from its current position to the given target position.

 

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

 

Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
*/



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    bool check(vector<vector<int>> &mat, int i, int j, int N)
    {
        if(i >= 0 and i < N and j >= 0 and j < N and mat[i][j] == -1)
        {
            return true;
        }
        
        return false;
    }
    
    public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        vector<vector<int>> mat(N, vector<int> (N, -1));
        
        mat[KnightPos[0] - 1][KnightPos[1] - 1] = 0;
        
        queue<pair<int, int>> q;
        
        q.push({KnightPos[0] - 1, KnightPos[1] - 1});
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            int currVal = mat[i][j];
            
            if(check(mat, i - 2, j - 1, N))
            {
                mat[i - 2][j - 1] = currVal + 1;
                
                q.push({i - 2, j - 1});
            }
            if(check(mat, i - 2, j + 1, N))
            {
                mat[i - 2][j + 1] = currVal + 1;
                
                q.push({i - 2, j + 1});
            }
            
            if(check(mat, i - 1, j - 2, N))
            {
                mat[i - 1][j - 2] = currVal + 1;
                
                q.push({i - 1, j - 2});
            }
            if(check(mat, i - 1, j + 2, N))
            {
                mat[i - 1][j + 2] = currVal + 1;
                
                q.push({i - 1, j + 2});
            }
            
            if(check(mat, i + 1, j - 2, N))
            {
                mat[i + 1][j - 2] = currVal + 1;
                
                q.push({i + 1, j - 2});
            }
            if(check(mat, i + 1, j + 2, N))
            {
                mat[i + 1][j + 2] = currVal + 1;
                
                q.push({i + 1, j + 2});
            }
            
            if(check(mat, i + 2, j - 1, N))
            {
                mat[i + 2][j - 1] = currVal + 1;
                
                q.push({i + 2, j - 1});
            }
            if(check(mat, i + 2, j + 1, N))
            {
                mat[i + 2][j + 1] = currVal + 1;
                
                q.push({i + 2, j + 1});
            }
            
            q.pop();
        }
        
        return mat[TargetPos[0] - 1][TargetPos[1] - 1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
