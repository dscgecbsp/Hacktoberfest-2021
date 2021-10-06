/*Prerequisite Tasks 

Medium Accuracy: 53.22% Submissions: 8794 Points: 4
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, 
which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.


Example 1:

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.
Example 2:

Input:
N = 2, P = 2
prerequisites = {{1,0},{0,1}}
Output:
No
Explanation:
To do task 1 you should have completed
task 0, and to do task 0 you should
have finished task 1. So it is impossible.

Your task:
You don’t need to read input or print anything. Your task is to complete the function isPossible() which takes the integer N denoting the number of
tasks, P denoting the number of prerequisite pairs and prerequisite as input parameters and returns true if it is possible to finish all tasks otherwise returns false. 


Expected Time Complexity: O(N + P)
Expected Auxiliary Space: O(N + P)


Constraints:
1 = N = 104
1 = P = 105 */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& p) {
	    // Code here
	    vector<int>adj[N];
	    vector<int>in(N);
	    int n=p.size(),c=0;
	    queue<int>q;
	    for(int i=0;i<n;i++)
	    {
	        pair<int,int>p1=p[i];
	     in[p1.second]++;
	     adj[p1.first].push_back(p1.second);
	    }
	    for(int i=0;i<N;i++)
	     if(in[i]==0)
	      q.push(i);
	     c=q.size();
	    while(!q.empty()){
	        int u=q.front();
	        q.pop();
	        for(auto j:adj[u])
	         {
	             if(--in[j]==0)
	              {q.push(j);c++;}
	         }
	    }
	    if(c!=N)
	     return false;
	     return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
