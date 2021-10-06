/*
Fill the Tank 

Medium Accuracy: 34.38% Submissions: 227 Points: 4
In a city water tanks are connected by pipeline(As a tree). Since people working at the city corporation are lazy they usually select one of the tank and pour complete amount of water into it, when the tank is filled, the excess water evenly flows to the connected tanks. The head of city corporation has instructed to pour minimum amount of water into the selected tank so that all other tank is filled. As the labours of the corporation are not intelligent enough to figure out the minimum amount of water required to fill all the tanks they have asked your help. Also Maximum amount of water available with city corporation is 1018

NOTE: If the tank if full, the water flows to all of its connected tanks except the tank from which the water had come to it. i.e, to all tanks except the source for that particular tank. If it has no option to flow the water is considered to be wasted

Example 1:

Input:
N = 4 and S = 1
Edges = [[1, 2], [2, 3], [3, 4]]
Cap = [1, 1, 1, 1]
Output: 5
Explanation:
Initially 5 unit of water is poured into 
tank 1. 2 unit of it flows to tank 2 and 
2 unit of it flows into tank 3. From 2 
unit of water in tank 2 1 unit flows into 
tank 4 and 1 unit from tank 3 is wasted.


Example 2:

Input:
N = 3 and S = 2
Edges = [[1, 2], [2, 3]]
Cap = [1, 1, 1]
Output: 3

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimum_amount() which takes an integer N, an integer S, 2-d 
array Edges, and an array Cap of length N as input parameters and returns the minimum amount of water required to fill all the tanks. If it is not 
possible to fill all the tanks print -1.

Expected Time Complexity: O(N*log(S))
Expected Auxiliary Space: O(1)

 

Constraints:
1 = n = 100000
1 = s,u,v = n
1 = capacity of each tank = 1000000007
*/

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> graph[],int source, int src, long &left, int cap[], bool vis[], bool &istrue){
    vis[src]=true;
    if(left>=cap[src]){
        left-=cap[src];
        cap[src]=0;
    }
    else {
        istrue=false;
        return ;
    }
    long count=0;
    for(auto i : graph[src]){
        if(!vis[i]){
            count++;
        }
    }
    // if(src!=source)
    //     count=count-1;
    for(auto itr : graph[src]){
        if(!vis[itr] && istrue){
            long curleft=left/count;
            dfs(graph,source, itr, curleft, cap, vis, istrue);
        }
    }
    return ;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,s;
	    cin>>n>>s;
	    s--;
	    int capacity[n+1];
	    for(int i=0;i<n;i++){
	        cin>>capacity[i];
	    }
	    vector<int> graph[n+1];
	    for(int i=0;i<n-1;i++){
	        int a,b;
	        cin>>a>>b;
	        a--;b--;
	        graph[a].push_back(b);
	        graph[b].push_back(a);
	    }
	    bool vis[n];
	    long lo=1, hi=1e18+1;
	    int cap[n];
	    bool flag=true;
	    while(hi>lo){
	        for(int i=0;i<n;i++){
	            vis[i]=false;
	            cap[i]=capacity[i];
	        }
	        long mid=lo+(hi-lo)/2;
	        long m=mid;
	        bool istrue=true;
	        int src=s;
	        dfs(graph, src, s, mid, cap, vis, istrue);
	        if(istrue){
	            hi=m;
	            flag=false;
	        }
	        else lo=m+1;
	    }
	    
	    if(flag){
	        cout<<-1<<endl;
	    }
	    else cout<<lo<<endl;
	}
	return 0;
}
