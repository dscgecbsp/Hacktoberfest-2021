/*
Steps by Knight 

Medium Accuracy: 50.11% Submissions: 26591 Points: 4
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target
position.

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

void bfs(bool visited[20][20],int n,int x,int y,int X,int Y,int& count){
    queue<pair<int,int>>q;
    visited[x-1][y-1]=true;
    q.push(make_pair(x,y));
    q.push(make_pair(0,0));
    while(q.size()>1){
        x=q.front().first;
        y=q.front().second;
        if(q.front().first==0 && q.front().second==0){
            q.pop();
            count++;
            q.push(make_pair(0,0));
            continue;
        }
        if(q.front().first==X && q.front().second==Y){
            return;
        }
        if(x>2 && y>1 && visited[x-3][y-2]==false){
            visited[x-3][y-2]=true;
            q.push(make_pair(x-2,y-1));
        }
        if(x>2 && y<n && visited[x-3][y]==false){
            visited[x-3][y]=true;
            q.push(make_pair(x-2,y+1));
        }
        if(x>1 && y<n-1 && visited[x-2][y+1]==false){
            visited[x-2][y+1]=true;
            q.push(make_pair(x-1,y+2));
        }
        if(x<n && y<n-1 && visited[x][y+1]==false){
            visited[x][y+1]=true;
            q.push(make_pair(x+1,y+2));
        }
        if(x<n-1 && y<n && visited[x+1][y]==false){
            visited[x+1][y]=true;
            q.push(make_pair(x+2,y+1));
        }
        if(x<n-1 && y>1 && visited[x+1][y-2]==false){
            visited[x+1][y-2]=true;
            q.push(make_pair(x+2,y-1));
        }
        if(x<n && y>2 && visited[x][y-3]==false){
            visited[x][y-3]=true;
            q.push(make_pair(x+1,y-2));
        }
        if(x>1 && y>2 && visited[x-2][y-3]==false){
            visited[x-2][y-3]=true;
            q.push(make_pair(x-1,y-2));
        }
        q.pop();
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x,y,X,Y;
        cin>>x>>y>>X>>Y;
        int count=0;
        bool visited[20][20]={false};
        bfs(visited,n,x,y,X,Y,count);
        cout<<count<<'\n';
    }
	return 0;
}
